# Game2048
This game is written in console environment.It compiles by gcc compiler in linux.It's just for practice.
you can play game by 2 and 4 and 6 and 8 keys.if you use another keys,program doesn't work.
if you press the 8 keys all of the numbers move to up,
if you press the 2 keys all of the numbers move to down,
if you press the 4 keys all of the numbers move to left,
if you press the 6 keys all of the numbers move to right,
and if two numbers close together in a row,adding them and two numbers above together in a colum,adding them.
if you achive 2048 number,you win and if all of the houses matrix became full, you lose.

The steps of project:

1.I created header file for definitions in projects.

2.I need a matrix to show the number and play game,so the first I declares one matrix (4in4) and filled all matrix by zero.

3.I need a random number between 0 and 3 because of the index of matrix, so I used rand() function and calculated the remainder is divided into four becuase is created ranbom number betwean 0 and 3, and I took ranbom number in index of two matrix houses and put values 2 in them for starting game.

4.I printed matrix.

5.I wrote check function.In this function if one of the matrix elements will became 2048, the player wins and if all of the matrix elements will fill, the player lose the game.

6.I wrote randomNumber function that makes random indexes to put 2 in elements after each movement during the game.

7.I wrote shiftRight function for moving all matrix houses to right and if each rows have the same numbers that are close together,will be added together.

8.I wrote shiftdown function for moving all matrix houses to down and if each colums have the same numbers that are close together,will be added together.

9.I read a character from user to know how to move.user have to use only four character including 8(for up) or 4(for left) or 6(for right) or 2(for down) and got the ASCII code.

10.If the ASCII code character is read from input will be 54 that is number 6,I call the shiftRight function.

11.If the ASCII code character is read from input will be 50 that is number 2,I call the shiftdown function.

12.I wrote shiftLeft function for moving all matrix houses to Left and if each colums have the same numbers that there isn't any numbers between them except zero,will be added together.

13.If the ASCII code character is read from input will be 52 that is number 4,I call the shiftleft function.

14.I wrote shiftUp function for moving all matrix houses to up and if each colums have the same numbers that are above together,will be added together.

15.If the ASCII code character is read from input will be 56 that is number 8,I call the shiftup function.

16.I've called randomNumber function after each moving to make a random number in matrix.

17.I've called check function in a while loop to continue the game untill the user wins or loses.

18.I clear the sreen terminal to prevent showing all step's printing.