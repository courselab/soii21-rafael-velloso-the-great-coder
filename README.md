
 SOII-RAFAEL-VELLOSO-THE-GREAT-CODER
 ==============================

There are three main folders in this project:
 - hw
 - mbr
 - tyos

* HW is exercise 1: I fixed the bug that was printing the '\0' character;
* MBR is exercise 2: I implemented a command called "movc", which enables
  the user to move the cursor using "W A S D" keys. In order to exit the "movc"
  command, the ESCAPE key must be pressed;
* TYOS is exercise 3: I implemented a Drawing game (called DrawOS). The commands are as follows:
  - W A S D : move the cursor up, left, down, right (respectively);
  - U H J K : same as "W A S D", but you erase as you move the cursor;
  - Q : toggle fill mode -> it enables you to draw as you move using "W A S D";
  - E : toggle eraser mode -> it enables you to erase a single character;
  - SPACE : draws a single char or erases a single char (depending on eraser flag);
  - ESC : resets the game;
