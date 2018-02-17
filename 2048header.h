#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
//for clear screen
#define gotoxy(x, y) printf("\033[%d;%dH", x, y)
#define update() printf("\033[H\033[J")
//defining matrix and first filling all of matrix by zero
int m[4][4]={0};
void fill();
void printmatrix();
int check();
int randomNumber();
bool shiftRight();
bool shiftDown();
bool shiftLeft();
bool shiftUp();
int print(){
 update();
 printmatrix();
 gotoxy(5, 0);
 return 0;
}