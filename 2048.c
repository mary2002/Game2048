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

