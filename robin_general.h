/*
  robin_general.h - v0.1
  General MIDI configuration for robin
*/

#ifndef ROBIN_H
#define RBN_KEYMAP_CHANNEL 9
#define RBN_KEYMAP_OFFSET 101 // 128 (tonal instruments) - 27 (first percussion key)
#define RBN_CHAN_COUNT 16
#define RBN_PROGRAM_COUNT 195 // 128 tonal instruments + 67 percussive sounds
#define RBN_VOICE_COUNT 128
#define RBN_OPERATOR_COUNT 8
#define RBN_ENVPT_COUNT 6
#define RBN_FILTER_COUNT 4
#endif

#include "robin.h"

#ifndef ROBIN_GENERAL_H
#define ROBIN_GENERAL_H

#ifdef __cplusplus
extern "C" {
#endif

  RBNDEF rbn_result rbn_general_init(rbn_instance* inst, const rbn_config* config);

#ifdef __cplusplus
}
#endif
#endif // ROBIN_GENERAL_H

#ifdef RBN_GENERAL_IMPLEMENTATION
#ifdef __cplusplus
extern "C" {
#endif

  rbn_result rbn_general_init(rbn_instance* inst, const rbn_config* config) {
    rbn_init(inst, config);

    // Set all tonal instruments to simple sinewaves
    for(uintptr_t i = 0; i < 128; i++) {
      rbn_program* program = inst->programs + i;
      program->operators[0].freq_ratio = 1.f;
      program->operators[0].output = 1.f;
      program->operators[0].volume_envelope.points[0].time = 0.05f;
      program->operators[0].volume_envelope.points[0].value = 1.f;
      program->operators[0].volume_envelope.release_time = 0.05f;
      //program->operators[1].freq_ratio = 1.f;
      //program->operators[1].volume_envelope.points[0].value = 1.f;
      //program->op_matrix[1][0] = 1.f;
    }

    rbn_program* piano = inst->programs + 0;
    piano->operators[0].freq_ratio = 1.f;
    piano->operators[0].output = 0.5f;
    piano->operators[0].volume_envelope.points[0].time = 0.f;
    piano->operators[0].volume_envelope.points[0].value = 1.f;
    piano->operators[0].volume_envelope.points[1].time = 2.f;
    piano->operators[0].volume_envelope.points[1].value = 0.25f;
    piano->operators[0].volume_envelope.points[2].time = 4.f;
    piano->operators[0].volume_envelope.points[2].value = 0.05f;
    piano->operators[0].volume_envelope.release_time = 0.5f;
    piano->operators[1].freq_ratio = 1.f;
    piano->operators[1].volume_envelope.points[0].time = 0.f;
    piano->operators[1].volume_envelope.points[0].value = 1.f;
    piano->operators[1].volume_envelope.release_time = -1.f;
    piano->op_matrix[1][0] = 4.f;
    piano->op_matrix[1][1] = 0.4f;
    RBN_MEMCPY(inst->programs + 1, piano, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 2, piano, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 3, piano, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 4, piano, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 5, piano, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 6, piano, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 7, piano, sizeof(rbn_program));

    rbn_program* tuned_percussion = inst->programs + 8;
    tuned_percussion->operators[0].freq_ratio = 1.f;
    tuned_percussion->operators[0].output = 0.5f;
    tuned_percussion->operators[0].volume_envelope.points[0].time = 0.f;
    tuned_percussion->operators[0].volume_envelope.points[0].value = 1.f;
    tuned_percussion->operators[0].volume_envelope.points[1].time = 2.f;
    tuned_percussion->operators[0].volume_envelope.points[1].value = 0.25f;
    tuned_percussion->operators[0].volume_envelope.points[2].time = 4.f;
    tuned_percussion->operators[0].volume_envelope.points[2].value = 0.f;
    tuned_percussion->operators[0].volume_envelope.release_time = 0.1f;
    tuned_percussion->operators[1].freq_ratio = 8.f;
    tuned_percussion->operators[1].volume_envelope.points[0].time = 0.f;
    tuned_percussion->operators[1].volume_envelope.points[0].value = 0.1f;
    tuned_percussion->operators[1].volume_envelope.release_time = -1.f;
    tuned_percussion->op_matrix[1][0] = 1.f;
    RBN_MEMCPY(inst->programs + 9, tuned_percussion, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 10, tuned_percussion, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 11, tuned_percussion, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 12, tuned_percussion, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 13, tuned_percussion, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 14, tuned_percussion, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 15, tuned_percussion, sizeof(rbn_program));

    rbn_program* organ = inst->programs + 16;
    organ->operators[0].freq_ratio = 0.4999f;
    organ->operators[0].output = 0.25f;
    organ->operators[0].volume_envelope.points[0].time = 0.05f;
    organ->operators[0].volume_envelope.points[0].value = 1.f;
    organ->operators[0].volume_envelope.release_time = 0.05f;
    organ->operators[1].freq_ratio = 1.f;
    organ->operators[1].output = 0.25f;
    organ->operators[1].volume_envelope.points[0].time = 0.05f;
    organ->operators[1].volume_envelope.points[0].value = 1.f;
    organ->operators[1].volume_envelope.release_time = 0.05f;
    organ->operators[2].freq_ratio = 2.0001f;
    organ->operators[2].output = 0.25f;
    organ->operators[2].volume_envelope.points[0].time = 0.05f;
    organ->operators[2].volume_envelope.points[0].value = 1.f;
    organ->operators[2].volume_envelope.release_time = 0.05f;
    organ->operators[3].freq_ratio = 3.999f;
    organ->operators[3].output = 0.25f;
    organ->operators[3].volume_envelope.points[0].time = 0.05f;
    organ->operators[3].volume_envelope.points[0].value = 1.f;
    organ->operators[3].volume_envelope.release_time = 0.05f;
    RBN_MEMCPY(inst->programs + 17, organ, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 18, organ, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 19, organ, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 20, organ, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 21, organ, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 22, organ, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 23, organ, sizeof(rbn_program));

    rbn_program* guitar = inst->programs + 24;
    guitar->operators[0].freq_ratio = 1.f;
    guitar->operators[0].output = 0.5f;
    guitar->operators[0].volume_envelope.points[0].time = 0.f;
    guitar->operators[0].volume_envelope.points[0].value = 1.f;
    guitar->operators[0].volume_envelope.points[1].time = 2.0f;
    guitar->operators[0].volume_envelope.points[1].value = 0.5f;
    guitar->operators[0].volume_envelope.release_time = 0.2f;
    guitar->operators[1].freq_ratio = 1.f;
    guitar->operators[1].volume_envelope.points[0].value = 1.f;
    guitar->operators[1].volume_envelope.release_time = -1.f;
    guitar->op_matrix[1][0] = 2.5f;
    RBN_MEMCPY(inst->programs + 25, guitar, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 26, guitar, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 27, guitar, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 28, guitar, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 29, guitar, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 30, guitar, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 31, guitar, sizeof(rbn_program));

    rbn_program* bass = inst->programs + 32;
    bass->operators[0].freq_ratio = 1.f;
    bass->operators[0].output = 1.f;
    bass->operators[0].volume_envelope.points[0].time = 0.f;
    bass->operators[0].volume_envelope.points[0].value = 1.f;
    bass->operators[0].volume_envelope.points[1].time = 0.7f;
    bass->operators[0].volume_envelope.points[1].value = 0.3f;
    bass->operators[0].volume_envelope.release_time = 0.2f;
    bass->operators[1].freq_ratio = 1.f;
    bass->operators[1].volume_envelope.points[0].time = 0.f;
    bass->operators[1].volume_envelope.points[0].value = 1.f;
    bass->operators[1].volume_envelope.points[1].time = 0.25f;
    bass->operators[1].volume_envelope.points[1].value = 0.f;
    bass->operators[1].volume_envelope.release_time = -1.f;
    bass->op_matrix[1][0] = 1.f;
    RBN_MEMCPY(inst->programs + 33, bass, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 34, bass, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 35, bass, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 36, bass, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 37, bass, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 38, bass, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 39, bass, sizeof(rbn_program));

    rbn_program* brass = inst->programs + 56;
    brass->operators[0].freq_ratio = 1.f;
    brass->operators[0].output = 1.f;
    brass->operators[0].volume_envelope.points[0].time = 0.06f;
    brass->operators[0].volume_envelope.points[0].value = 1.f;
    brass->operators[0].volume_envelope.points[1].time = 0.7f;
    brass->operators[0].volume_envelope.points[1].value = 0.5f;
    brass->operators[0].volume_envelope.release_time = 0.2f;
    brass->op_matrix[0][0] = 1.f;
    brass->operators[1].freq_ratio = 1.f;
    brass->operators[1].volume_envelope.points[0].time = 0.f;
    brass->operators[1].volume_envelope.points[0].value = 1.f;
    brass->operators[1].volume_envelope.release_time = -1.f;
    brass->op_matrix[1][0] = 1.f;
    brass->op_matrix[1][1] = 1.f;
    brass->operators[2].freq_ratio = 3.67f;
    brass->operators[2].volume_envelope.points[0].time = 0.f;
    brass->operators[2].volume_envelope.points[0].value = 1.f;
    brass->operators[2].volume_envelope.points[1].time = 0.05f;
    brass->operators[2].volume_envelope.points[1].value = 0.f;
    brass->operators[2].volume_envelope.release_time = -1.f;
    brass->op_matrix[2][0] = 1.f;
    brass->operators[3].freq_ratio = 0.02f;
    brass->operators[3].volume_envelope.points[0].time = 0.3f;
    brass->operators[3].volume_envelope.points[0].value = 0.f;
    brass->operators[3].volume_envelope.points[1].time = 0.6f;
    brass->operators[3].volume_envelope.points[1].value = 1.f;
    brass->operators[3].volume_envelope.release_time = 0.1f;
    brass->op_matrix[3][0] = 0.1f;
    RBN_MEMCPY(inst->programs + 57, brass, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 58, brass, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 59, brass, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 60, brass, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 61, brass, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 62, brass, sizeof(rbn_program));
    RBN_MEMCPY(inst->programs + 63, brass, sizeof(rbn_program));

    rbn_program* reed = inst->programs + 64;
    reed->operators[0].freq_ratio = 4.f;
    reed->operators[0].output = 1.f;
    reed->operators[0].volume_envelope.points[0].time = 0.1f;
    reed->operators[0].volume_envelope.points[0].value = 1.f;
    reed->operators[0].volume_envelope.release_time = 0.2f;
    reed->operators[1].freq_ratio = 1.0f;
    reed->operators[1].volume_envelope.points[0].value = 1.f;
    reed->operators[1].volume_envelope.release_time = -1.f;
    reed->op_matrix[1][0] = 2.5f;
    inst->programs[65] = *reed;
    inst->programs[66] = *reed;
    inst->programs[67] = *reed;
    inst->programs[68] = *reed;
    inst->programs[69] = *reed;
    inst->programs[70] = *reed;
    inst->programs[71] = *reed;

    rbn_program* melodic_drum = inst->programs + 112;
    melodic_drum->operators[0].freq_ratio = 0.5f;
    melodic_drum->operators[0].output = 1.f;
    melodic_drum->operators[0].volume_envelope.points[0].time = 0.f;
    melodic_drum->operators[0].volume_envelope.points[0].value = 1.f;
    melodic_drum->operators[0].volume_envelope.points[1].time = 0.2f;
    melodic_drum->operators[0].volume_envelope.points[1].value = 0.75f;
    melodic_drum->operators[0].volume_envelope.points[2].time = 0.35f;
    melodic_drum->operators[0].volume_envelope.points[2].value = 0.f;
    melodic_drum->operators[0].pitch_envelope.points[0].time = 0.001f;
    melodic_drum->operators[0].pitch_envelope.points[0].value = 1.f;
    melodic_drum->operators[0].pitch_envelope.points[1].time = 0.25f;
    melodic_drum->operators[0].pitch_envelope.points[1].value = -2.f;
    inst->programs[113] = *melodic_drum;
    inst->programs[114] = *melodic_drum;
    inst->programs[115] = *melodic_drum;
    inst->programs[116] = *melodic_drum;
    inst->programs[117] = *melodic_drum;
    inst->programs[118] = *melodic_drum;
    inst->programs[119] = *melodic_drum;

    rbn_program* perc_programs = inst->programs + RBN_KEYMAP_OFFSET;

    // Default percussion
#if 0
    for(uintptr_t i = 128; i < RBN_PROGRAM_COUNT; i++) {
      rbn_program* perc = inst->programs + i;
      perc->operators[0].freq_ratio = 0.2f;
      perc->operators[0].noise = 0.5f;
      perc->operators[0].output = 1.f;
      perc->operators[0].volume_envelope.points[0].time = 0.001f;
      perc->operators[0].volume_envelope.points[0].value = 1.f;
      perc->operators[0].volume_envelope.points[1].time = 0.1f;
      perc->operators[0].volume_envelope.points[1].value = 0.f;
      perc->operators[0].pitch_envelope.points[0].time = 0.1f;
      perc->operators[0].pitch_envelope.points[0].value = -2.f;
    }
#endif

    rbn_program* bass_drum = perc_programs + 35;
    bass_drum->operators[0].freq_ratio = 0.2f;
    bass_drum->operators[0].output = 8.f;
    bass_drum->operators[0].volume_envelope.points[0].time = 0.f;
    bass_drum->operators[0].volume_envelope.points[0].value = 1.f;
    bass_drum->operators[0].volume_envelope.points[1].time = 0.2f;
    bass_drum->operators[0].volume_envelope.points[1].value = 0.75f;
    bass_drum->operators[0].volume_envelope.points[2].time = 0.35f;
    bass_drum->operators[0].volume_envelope.points[2].value = 0.f;
    bass_drum->operators[0].pitch_envelope.points[0].time = 0.001f;
    bass_drum->operators[0].pitch_envelope.points[0].value = 1.f;
    bass_drum->operators[0].pitch_envelope.points[1].time = 0.25f;
    bass_drum->operators[0].pitch_envelope.points[1].value = -2.f;
    perc_programs[36] = *bass_drum;

    rbn_program* side_stick = perc_programs + 37;
    side_stick->operators[0].freq_ratio = 1.f;
    side_stick->operators[0].noise = 0.1f;
    side_stick->operators[0].output = 2.f;
    side_stick->operators[0].volume_envelope.points[0].time = 0.f;
    side_stick->operators[0].volume_envelope.points[0].value = 1.f;
    side_stick->operators[0].volume_envelope.points[1].time = 0.02f;
    side_stick->operators[0].volume_envelope.points[1].value = 0.f;
    side_stick->operators[0].pitch_envelope.points[0].time = 0.07f;
    side_stick->operators[0].pitch_envelope.points[0].value = -1.f;
    side_stick->operators[1].freq_ratio = 1.f;
    side_stick->operators[1].volume_envelope.points[0].time = 0.f;
    side_stick->operators[1].volume_envelope.points[0].value = 1.f;
    side_stick->op_matrix[1][0] = 5.f;

    rbn_program* snare = perc_programs + 38;
    snare->operators[0].freq_ratio = 0.6f;
    snare->operators[0].output = 8.f;
    snare->operators[0].volume_envelope.points[0].time = 0.f;
    snare->operators[0].volume_envelope.points[0].value = 1.f;
    snare->operators[0].volume_envelope.points[1].time = 0.02f;
    snare->operators[0].volume_envelope.points[1].value = 0.07f;
    snare->operators[0].volume_envelope.points[2].time = 0.13f;
    snare->operators[0].volume_envelope.points[2].value = 0.f;
    snare->operators[0].pitch_envelope.points[0].time = 0.f;
    snare->operators[0].pitch_envelope.points[0].value = 1.f;
    snare->operators[0].pitch_envelope.points[1].time = 0.01f;
    snare->operators[0].pitch_envelope.points[1].value = -1.f;
    snare->operators[1].noise = 1.f;
    snare->operators[1].output = 1.f;
    snare->operators[1].volume_envelope.points[0].time = 0.f;
    snare->operators[1].volume_envelope.points[0].value = 1.f;
    snare->operators[1].volume_envelope.points[1].time = 0.1f;
    snare->operators[1].volume_envelope.points[1].value = 0.1f;
    snare->operators[1].volume_envelope.points[2].time = 0.3f;
    snare->operators[1].volume_envelope.points[2].value = 0.f;
    snare->operators[1].volume_envelope.release_time = -1.f;
    perc_programs[40] = *snare;

    rbn_program* hand_clap = perc_programs + 39;
    hand_clap->operators[0].noise = 1.f;
    hand_clap->operators[0].output = 2.f;
    hand_clap->operators[0].volume_envelope.points[0].time = 0.001f;
    hand_clap->operators[0].volume_envelope.points[0].value = 1.f;
    hand_clap->operators[0].volume_envelope.points[1].time = 0.01f;
    hand_clap->operators[0].volume_envelope.points[1].value = 0.f;
    hand_clap->operators[0].volume_envelope.points[2].time = 0.011f;
    hand_clap->operators[0].volume_envelope.points[2].value = 0.9f;
    hand_clap->operators[0].volume_envelope.points[3].time = 0.02f;
    hand_clap->operators[0].volume_envelope.points[3].value = 0.f;
    hand_clap->operators[0].volume_envelope.points[4].time = 0.021f;
    hand_clap->operators[0].volume_envelope.points[4].value = 0.8f;
    hand_clap->operators[0].volume_envelope.points[5].time = 0.06f;
    hand_clap->operators[0].volume_envelope.points[5].value = 0.f;

    rbn_program* tom = perc_programs + 41;
    tom->operators[0].freq_ratio = 0.2f;
    tom->operators[0].output = 8.f;
    tom->operators[0].volume_envelope.points[0].time = 0.f;
    tom->operators[0].volume_envelope.points[0].value = 1.f;
    tom->operators[0].volume_envelope.points[1].time = 0.2f;
    tom->operators[0].volume_envelope.points[1].value = 0.75f;
    tom->operators[0].volume_envelope.points[2].time = 0.35f;
    tom->operators[0].volume_envelope.points[2].value = 0.f;
    tom->operators[0].pitch_envelope.points[0].time = 0.001f;
    tom->operators[0].pitch_envelope.points[0].value = 1.f;
    tom->operators[0].pitch_envelope.points[1].time = 0.25f;
    tom->operators[0].pitch_envelope.points[1].value = 0.f;
    perc_programs[43] = *tom;
    perc_programs[45] = *tom;
    perc_programs[47] = *tom;
    perc_programs[48] = *tom;
    perc_programs[50] = *tom;

    rbn_program* closed_hihat = perc_programs + 42;
    closed_hihat->operators[0].noise = 1.f;
    closed_hihat->operators[0].output = 0.5f;
    closed_hihat->operators[0].volume_envelope.points[0].time = 0.f;
    closed_hihat->operators[0].volume_envelope.points[0].value = 1.f;
    closed_hihat->operators[0].volume_envelope.points[1].time = 0.05f;
    closed_hihat->operators[0].volume_envelope.points[1].value = 0.f;

    rbn_program* pedal_hihat = perc_programs + 44;
    pedal_hihat->operators[0].noise = 1.f;
    pedal_hihat->operators[0].output = 0.5f;
    pedal_hihat->operators[0].volume_envelope.points[0].time = 0.f;
    pedal_hihat->operators[0].volume_envelope.points[0].value = 1.f;
    pedal_hihat->operators[0].volume_envelope.points[1].time = 0.1f;
    pedal_hihat->operators[0].volume_envelope.points[1].value = 0.f;

    rbn_program* open_hihat = perc_programs + 46;
    open_hihat->operators[0].noise = 1.f;
    open_hihat->operators[0].output = 0.5f;
    open_hihat->operators[0].volume_envelope.points[0].time = 0.f;
    open_hihat->operators[0].volume_envelope.points[0].value = 1.f;
    open_hihat->operators[0].volume_envelope.points[1].time = 0.15f;
    open_hihat->operators[0].volume_envelope.points[1].value = 0.f;
    perc_programs[49] = *open_hihat;
    perc_programs[51] = *open_hihat;
    perc_programs[55] = *open_hihat;

    return rbn_refresh(inst);
  }

#ifdef __cplusplus
}
#endif

#endif // RBN_GENERAL_IMPLEMENTATION

/*

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org>

*/
