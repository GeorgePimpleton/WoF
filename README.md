# WoF

[![Language](https://img.shields.io/badge/Language%20-C++-blue.svg)](https://github.com/GeorgePimpleton/Win32-games/)

## CplusPlus Wheel of Fortune code challenge

https://cplusplus.com/forum/lounge/284716/

The text file has 12,881 phrase entries.

First pass reads the WOF text file and chooses a random phrase using my custom random toolkit.

See https://github.com/GeorgePimpleton/misc_files/tree/main/Random%20Toolkit

The code so far deals with:

1. reading the number of lines in the file
2. randomly choosing one phrase from the list.  The code discards/skips the first two lines since they are not part of the game phrases.
3. create the initial hidden letters phrase block that will be displayed to the user at the start of the game.

If the phrase is CUFF & SAUSAGE LINKS the hidden phrase block is #### & ####### #####

Yes, punctuation matters.

### Notes

I am an incremental coder, I "creep up" on a finished product by writing/adding/updating small changes to the code base.  I have an idea what the finished project will be, I'll get there by small steps.
