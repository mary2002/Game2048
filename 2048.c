#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "2048header.h"
int main(int argc, char const *argv[])
{

	fill();
	return 0;

}

//This function  fills tow houses of matrix by random index and values of two
void fill(){
//then fill 2 houses of matrix by random index
srand(time(0));
		m[rand()%4][rand()%4]=2;
		m[rand()%4][rand()%4]=2;
}


