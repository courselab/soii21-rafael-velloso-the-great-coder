
 SOII-RAFAEL-VELLOSO-THE-GREAT-CODER
 ==============================

There are three main folders in this project:

* HW is exercise 1: I fixed the bug that was printing the '\0' character;
* MBR is exercise 2: I implemented a command called "movc", which enables
  the user to move the cursor using "W A S D" keys. In order to exit the "movc"
  command, the ESCAPE key must be pressed;
* TYOS is exercise 3: I implemented a Drawing game (called DrawOS). The commands are as follows:
  - W A S D : move the cursor up, left, down, right (respectively);
  - U H J K : same as "W A S D", but you erase as you move the cursor;
  - Q : toggle fill mode (the dafault value is false) - it enables you to draw as you move using "W A S D";
  - E : toggle eraser mode (the dafault value is false) - it enables you to erase or print a single character when pressing SPACE key;
  - SPACE : draws or erases a single character (depending on eraser flag);
  - ESC : resets the game;
