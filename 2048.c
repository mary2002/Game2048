#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "2048header.h"
int main(int argc, char const *argv[])
{
	fill();
	printmatrix();
	//clears the screen terminal to prevent showing all printting matrix
	while(check()==0){
	//reading a character from user  
	 char ch;
	scanf("%c",&ch);
	//Getting the ASCI code
	int nc=ch;
	//if character is 6 ,calls shiftRight function then calls randomNuber to make next number 
		if(nc==54){
			if(shiftRight())
				randomNumber();
			printmatrix();
		}
    //if character is 2 calls shiftDown function then calls randomNuber to make next number 
		if(nc==50){
			if(shiftDown())
				randomNumber();
			printmatrix();
		
		}
    //if character is 4 calls shiftDown function then calls randomNuber to make next number 
		if(nc==52){
			shiftLeft();
			randomNumber();
			printmatrix();
		    
		}
	//if character is 8 calls shiftDown function then calls randomNuber to make next number 
	    if(nc==56){
			shiftUp();
			randomNumber();
			printmatrix();
		
	    }	
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
int check(){
//It's a counter to count the zero elements of matrix
    int c=0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j <4 ; ++j)
		{
			//checking if the players can make a 2048 number is winner and game will exit
			if(m[i][j]==2048){	
				printf("win\n");
				return 1;
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
		return 1;
	}
	return 0;
 }
// This function  fills one houses which is zero by values of two 
int randomNumber(){
	//makes two random number between 0 to 3 for index 
	srand(time(NULL));
	int k=rand()%4;
	int z=rand()%4;
	//if the random house is zero,fills by two values
 	if(m[k][z]==0){
	 	m[k][z]=2;
	 	return 0;
	 }
	 //if the random house isn't zero,searches a house that has zero value and if will find return
	 else{
for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j <4 ; ++j)
		{
			//if the random house is zero,fills by two values
			if(m[i][j]==0){
				m[i][j]=2;
				return 0;
			}
		}
	}
}
return 1;
}
//This function shifts all of the houses matrix to Right and if two numbers are the same value, adds together and put their sum in the next house
bool shiftRight(){
	//I declared the flag to check if the movement occurs or not,for the first time it's false that means movement has't occured yet 
	bool canMove=false;
for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			//If the element isn't zero and the next house is zero swaps them
			if(m[i][j]!=0 && m[i][j+1]==0){
				m[i][j+1]=m[i][j];
				m[i][j]=0;
				//movement has occured then flag became true
				canMove=true;	
			}
			//If  the element isn't zero and is the same to next house adds together and puts the value's house zero 
			if(m[i][j]==m[i][j+1] && m[i][j]!=0){
					m[i][j+1]+=m[i][j];	
					m[i][j]=0;
					canMove=true;
			}	
		}
	}
	 return canMove;
}
//This function shifts all of the houses matrix to down and if two numbers are the same value, adds together and put their sum in the  house
bool shiftDown(){
	//I declared the flag to check if the movement occurs or not,for the first time it's false that means movement has't occured yet 
	bool canMove=false;	
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			//If the element isn't zero and the under house is zero swaps them
			if(m[i][j]!=0 && m[i+1][j]==0){
				m[i+1][j]=m[i][j];
				m[i][j]=0;
				//movement has occured then flag became true
				canMove=true;		
			}
			//If  the element isn't zero and is the same to under house adds together and puts the value's house zero 
			if(m[i][j]==m[i+1][j] && m[i][j]!=0){
					m[i+1][j]+=m[i][j];	
					m[i][j]=0;
					//merging houses has occured then flag became true
				canMove=true;	
			}	
		}
	}
	return canMove;
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

