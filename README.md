# Advent of Code in C on a Commodore 64  

This is my attempt at solving some of the puzzles from [Advent of Code](https://adventofcode.com) using C ([cc65](https://cc65.github.io/)), running the solution binaries on a Commodore 64.  

## Basic setup  
- Development is done on a modern computer (Macbook Pro from 2012, running some form of Linux distro).  
- C code is compiled using [cc65](https://cc65.github.io/), with the -t c64 flag.
- The binaries are then tested in the [Vice emulator](https://vice-emu.sourceforge.io/) (x64sc).  
- And the last step is to verify that the binary can be run on the actual C64 hardware.  
  For this I use my [Kung Fu Flash 2 cartridge](https://github.com/Sgw32/KungFuFlash2-USBC/) to get the files from my laptop, via an SD-card, and on to my [Commodore 64C](https://www.c64-wiki.com/wiki/C64C).  

## Quirks and stuff  

I've noticed that when I used `fread()`, or `fgets()`, I would get weird problems with `strok()`, `sscanf()`, and `strchr()`. They would simply not work as they should.  
The exact same data, put on the stack or heap using any other method, did not cause the same issues. So after a long time of troubleshooting I decided to abandon that method. I was thinking of loading the inputs from textfiles, like I usually do - instead of baking it into the source code.  
But there must be some weird bug in the cc65 CBM filesystem layer or something that messes things up. So I instead went for the method of putting the input for each day into a header file, and excluding that from the git repo via .gitignore. All in order to not expose the inputs publicly, as requested by the creator of Advent of Code.  

