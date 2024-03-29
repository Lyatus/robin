# robin

Robin aims to be a single-header MIDI-compliant frequency modulation synthesizer. This repository also contains configuration for it to play General MIDI audio, and a command-line interface for testing purposes.

## Usage

You can use Robin by placing `robin.h` in your project folder and including it. You need to include it once with the `RBN_IMPLEMENTATION` macro defined to actually define the functions, while - without the macro defined - it will only declare robin's structures and functions.

```
#define RBN_IMPLEMENTATION
#include "robin.h"
```

## General MIDI configuration

To use the General MIDI configuration, include `robin_general.h` in place of `robin.h` (it depends on `robin.h` being in the same directory).

```
#define RBN_IMPLEMENTATION
#define RBN_GENERAL_IMPLEMENTATION
#include "robin_general.h"
```

## Command-Line Interface

### Building

You can use [CMake](https://cmake.org/) to build the [cli](cli) source folder.

### Usage

- `play [file]` will directly play a `.mid` file
- `render [file]` will render the audio of a `.mid` file into a `.wav` file
- `edit [program_index]` will open a crude program editor
- `export [program_index]` will export the program to `export.c`

## JUCE plugin

### Building

You need to install [Projucer](https://juce.com) to open the `.jucer` project file in the [juce](juce) folder.
