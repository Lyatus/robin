#include "rbncli.h"

static void fputui(unsigned int value, size_t size, FILE* stream) {
  while(size > 0) {
    fputc(value & 0xff, stream);
    size -= 1;
    value >>= 8;
  }
}

int rbncli_render_mid(const char* filename) {
  tml_message* mid_seq = tml_load_filename(filename);
  if(!mid_seq) {
    return -1;
  }

  unsigned int total_time;
  tml_get_info(mid_seq, NULL, NULL, NULL, NULL, &total_time);

  char wavfilename[128] = "";
  sprintf(wavfilename, "%s.wav", filename);

  const uint32_t channels = 2;
  const uint32_t bytes_per_block = sizeof(int16_t) * channels;
  const uint32_t bits_per_sample = sizeof(int16_t) * 8;
  const uint32_t bytes_per_second = (sample_rate * bits_per_sample * channels) / 8;

  FILE* wavfile = fopen(wavfilename, "wb");
  fputs("RIFF----WAVEfmt ", wavfile);
  fputui(16, 4, wavfile); // No extension data
  fputui(1, 2, wavfile); // PCM
  fputui(channels, 2, wavfile); // Channels
  fputui(sample_rate, 4, wavfile); // Sample rate
  fputui(bytes_per_second, 4, wavfile); // Byte rate
  fputui(bytes_per_block, 2, wavfile); // Bytes per block
  fputui(bits_per_sample, 2, wavfile); // Bits per sample

  const long data_chunk_pos = ftell(wavfile);
  fputs("data----", wavfile);

  uint32_t progress = 0;
  rbncli_progress_bar(progress, NULL);

  tml_message* current_msg = mid_seq;
  uint64_t current_sample = 0;
  uint64_t total_rendering_time = 0;
  uint64_t total_rendered_samples = 0;
  while(current_msg) {
    const uint64_t current_time = (current_sample * 1000) / sample_rate;

    rbncli_progress_bar((uint32_t)((current_time * 100) / total_time), &progress);

    const int64_t time_to_wait = current_msg->time - current_time;
    if(time_to_wait > 0) {
      uint32_t samples_to_render = (uint32_t)((time_to_wait * sample_rate) / 1000);

      // Pad sample count to block size
      if(samples_to_render % RBN_BLOCK_SAMPLES > 0) {
        samples_to_render += RBN_BLOCK_SAMPLES - (samples_to_render % RBN_BLOCK_SAMPLES);
      }

      int16_t* buffer = malloc(samples_to_render * sizeof(int16_t) * 2);

      const uint64_t previous_rendered_samples = inst.rendered_samples;
      const uint64_t previous_time = rbncli_get_time();

      rbn_result result = rbn_render(&inst, buffer, samples_to_render);
      if(result != rbn_success) {
        printf("rbn_render failed\n");
        tml_free(mid_seq);
        fclose(wavfile);
        return -1;
      }

      total_rendering_time += rbncli_get_time() - previous_time;
      total_rendered_samples += inst.rendered_samples - previous_rendered_samples;

      fwrite(buffer, sizeof(int16_t) * 2, samples_to_render, wavfile);

      free(buffer);

      current_sample += samples_to_render;
    }

    rbncli_send_tml_msg(&inst, current_msg);
    current_msg = current_msg->next;
  }

  rbncli_progress_bar(100, &progress);

  const long file_size = ftell(wavfile);

  // Fix the data chunk header to contain the data size
  fseek(wavfile, data_chunk_pos + 4, SEEK_SET);
  fputui(file_size - data_chunk_pos + 8, 4, wavfile);

  // Fix the file header to contain the proper RIFF chunk size, which is (file size - 8) bytes
  fseek(wavfile, 4, SEEK_SET);
  fputui(file_size - 8, 4, wavfile);

  tml_free(mid_seq);
  fclose(wavfile);

  printf("Samples per us: %f\n", (double)total_rendered_samples / (double)total_rendering_time);

  return 0;
}