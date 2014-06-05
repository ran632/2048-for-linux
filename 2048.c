#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define PRIME 2
#define EMPTY 0

void initialize();
int ran();
void placeNum();
void printBoard();

int board[SIZE][SIZE];


int main(int argc, int* argv[]){
	int i=0;
	srand(time(NULL));
	initialize();
	while(1){
		placeNum();
		printBoard();
		break;
	}
}


void initialize(){
	int i, j;
	for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			board[i][j] = EMPTY;
		}
	}
}

int ran(){
  	return (rand() % (SIZE));
}

void placeNum(){
	int i,j;
	do{
		i = ran();
		j = ran();
	}while(board[i][j] != EMPTY);
	board[i][j] = PRIME;
}


void printBoard(){
	int i,j;
	for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			printf("%d\t", board[i][j]);
		}
		printf("\n\n");
	}
}