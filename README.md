# Project: Hare And Tortoise

Write a hare and tortoise competition program using object-oriented programming.

There is a road with n blocks, where n >= 1. The road can be slippery, so occasionally animals may move backwards from current position.

The first animal to reach or pass the last block is the winner; there can also be a tie.

In each round, your program adjusts the position of the animals according to its moving pattern. Use variables to keep track of animals’ current positions, which can be at block 0 to n-1. 

Each animal starts at position 0 (the first block). If an animal slips left before block 0, move that animal back to block 0.
You may image there is a road blocker cone at the beginning of the first block, hence animals cannot fall left to block 0.

Similarly, if an animal moves past position n-1 (the last block), move that animal back to square n-1. You may image there is a road blocker cone at the end of last block, hence animals cannot fall right to last block.

Generate the percentages in the above table by producing a random integer in the range 0 <= i < 10. For the tortoise, perform a “fast plod” when 0 <= i < 5, a “slip” when 5 <= i < 7 or a “slow plod” when 7 <= i < 10. Use a similar technique to move the hare. 


Begin the race.


(8.1) For each round in competition, display a line whose length is the same as number of blocks in a road. Letter T is shown in the position of the tortoise and the letter H in the position of the hare. 
(8.2) Occasionally, the animals can land on the same block. In this case, the tortoise bites the hare, and your program should display only letter T, with message "Ouch, Tortoise bites Hare." in the next line.
(8.3) All output positions other than T and H should be blank. 
After each line is displayed, test for whether either animal has reached or passed the last block. If so, display the winner and terminate the simulation.


(9.1) If the tortoise wins, display 
         Yay!!! tortoise wins!
         
         
(9.2) If the hare wins, display
         Yuck, hare wins.
         
         
(9.3) If both animal win on the same tick of the clock, you can print out
         It is a tie.

