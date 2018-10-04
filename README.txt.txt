################################################################################
OMAHA
################################################################################
Description:
This program compares two sets of Poker hands to identify hi/lo hands in the game of OMAHA Hi/Lo.

Assumptions:
-Input is read through a file "input.txt" in the main directory of the .exe file
-Input format is "HandA:Ac-Kd-Jd-3d HandB:5c-5d-6c-7d Board:Ah-Kh-5s-2s-Qd" -once per line
-Input is correct (ie. No input validation is provided)
-Output is saved as "output.txt" in the same directory as the input file
-Output format is "HandB wins Hi (3-of-a-Kind); HandB wins Lo (7652A)" -once per line
-Notation example as follows:
Ad (Ace diamonds)
Kc (King clubs)
Qh (Queen hearts)
Js (Jack spades)
Td (10 diamonds)  
9s (9 spades)


Gameplay assumptions:
-Suit has no impact on ranking
-Ace can be used as the highest card or as the lowest card
-Lo hand must have different ranks and no card must be greater than 8

Running this application:
Run omahacomp.exe in the Debug folder.