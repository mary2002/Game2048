#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "2048header.h"
int main(int argc, char const *argv[])
{

	fill();
	printmatrix();
	//as while the user wins or loses, the game continues
	while(check()){
	//reading a character from user  
	 char ch;
	scanf("%c",&ch);
	//Getting the ASCI code
	int nc=ch;
	//if character is 6 ,calls shiftRight function then calls randomNuber to make next number 
		if(nc==54){
			shiftRight();
			randomNumber();
		}
    //if character is 2 calls shiftDown function then calls randomNuber to make next number 
		if(nc==50){
			shiftDown();
			randomNumber();
		}
    //if character is 4 calls shiftDown function then calls randomNuber to make next number 
		if(nc==52){
			shiftLeft();
			randomNumber();
		}
	//if character is 8 calls shiftDown function then calls randomNuber to make next number 
	    if(nc==56){
			shiftUp();
			randomNumber();
	    }

printf("\n");	
printmatrix();
}
	return 0;

}

//This function  fills tow houses of matrix by random index and values of two
void fill(){
//then fill 2 houses of matrix by random index
srand(time(0));
		int i=rand()%4;
		int j=rand()%4;
		int k=rand()%4;
		int z=rand()%4;
		m[i][j]=2;
		if(i==k && j==z){
		 k=rand()%4;
		 z=rand()%4;
		}
		m[k][z]=2;
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
//This function shifts all of the houses matrix to Right and if two numbers are the same value, adds together and put their sum in the next house
void shiftRight(){
for (int i = 0; i < 4; ++i)
	{

		for (int j = 0; j < 3; ++j)
		{
			//If the element isn't zero and the next house is zero swaps them
			if(m[i][j]!=0 && m[i][j+1]==0){
				m[i][j+1]=m[i][j];
				m[i][j]=0;
				
			}
			//If  the element isn't zero and is the same to next house adds together and puts the value's house zero 
			if(m[i][j]==m[i][j+1] && m[i][j]!=0){
					m[i][j+1]+=m[i][j];	
					m[i][j]=0;
			}	
			
			
		}
	}


}
//This function shifts all of the houses matrix to down and if two numbers are the same value, adds together and put their sum in the  house
void shiftDown(){
	
	for (int i = 0; i < 3; ++i)
	{

		for (int j = 0; j < 4; ++j)
		{
			//If the element isn't zero and the under house is zero swaps them
			if(m[i][j]!=0 && m[i+1][j]==0){
				m[i+1][j]=m[i][j];
				m[i][j]=0;
				
			}
			//If  the element isn't zero and is the same to under house adds together and puts the value's house zero 
			if(m[i][j]==m[i+1][j] && m[i][j]!=0){
					m[i+1][j]+=m[i][j];	
					m[i][j]=0;
			}	
			
			
		}
	}
}
//This function shifts all af matrix houses to left and if two numbers in a row are the same value and there isn't any number except zero between them
void shiftLeft(){
//analysis the rows from the first
for (int i = 0; i < 4; ++i)
	{
//analysis the colums from the last
		for (int j = 3; j > 0; --j)
		{
			//if the element isn't zero and the left house is zero,swaps them
			if(m[i][j]!=0 && m[i][j-1]==0){
				m[i][j-1]=m[i][j];
				m[i][j]=0;
				
			}
			//if the element isn't zero and is the same to left house adds together and puts the value's house zero 
			if(m[i][j]==m[i][j-1] && m[i][j]!=0){
					m[i][j-1]+=m[i][j];	
					m[i][j]=0;
			}	
			
			
		}
	}

}
//This function shifts all af matrix houses to up and if two numbers in a colum are the same value and one of them above the other one,adds together
void shiftUp(){
//analysis the rows from the last
for (int i = 3; i > 0; --i)
	{
//analysis the colums from the first
		for (int j = 0; j < 4; ++j)
		{
			//if the element isn't zero and the elements above it is zero,swaps them
			if(m[i][j]!=0 && m[i-1][j]==0){
				m[i-1][j]=m[i][j];
				m[i][j]=0;
				
			}
			//if the element isn't zero and is the same to above house adds together and puts the value's house zero 
			if(m[i][j]==m[i-1][j] && m[i][j]!=0){
					m[i-1][j]+=m[i][j];	
					m[i][j]=0;
			}	
			
			
		}
	}


}

