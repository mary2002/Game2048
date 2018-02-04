#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "2048header.h"
int main(int argc, char const *argv[])
{

	fill();
	printmatrix();
	return 0;

}

//This function  fills tow houses of matrix by random index and values of two
void fill(){
//then fill 2 houses of matrix by random index
srand(time(0));
		m[rand()%4][rand()%4]=2;
		m[rand()%4][rand()%4]=2;
}

//print matrix
void printmatrix(){
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j <4 ; ++j)
		{
			printf("%2d|",m[i][j]);

			
		}
		printf("\n");
		
	}
}
//This functin checks if the player win or lose,the game will finish and exit
bool check(){
//It's a counter to count the zero elements of matrix
    int c=0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j <4 ; ++j)
		{
			//checking if the players can make a 2048 number is winner and game will exit
			if(m[i][j]==2048){
				
				printf("win\n");
				return false;
				exit(0);
		   }
		   //checking if elements of houses are zero,one  number added to counter
		   if(m[i][j]==0){
		   c++;
		   }

 	    }
			
	} 
	//If the counter is zero, it means there is no empty house and the player has lost the game
	if(c==0){

		printf("lose\n");
		return false;
		exit(0);
	}

	return true;
 }
// This function  fills one houses which is zero by random index and values of two
void randomNumber(){

		srand(time(0));
	int i=rand()%4;
	int j=rand()%4;
	if(m[i][j]==0){
		m[i][j]=2;

	    }

}


