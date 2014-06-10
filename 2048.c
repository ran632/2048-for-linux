#include <stdio.h>
#include <stdlib.h>
#include <time.h>
<<<<<<< HEAD

#define SIZE 4
#define PRIME 2
#define EMPTY 0
=======
#include <curses.h>
#include "slides.h"
#include "boardDraw.h"
>>>>>>> 206db47ed50e1f17fcfe45899c5c84997add7928

void initialize();
int ran();
void placeNum();
<<<<<<< HEAD
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
=======

int board[SIZE][SIZE];
WINDOW * mainwin;

int main(){

  	mainwin = newwin(10,10,1,1);
	srand(time(NULL));
	initialize();
	placeNum();
	while(1){
		clear();
		refresh();
		printBoard(board);
		int keyPress = getch();
		switch(keyPress){
			case KEY_RIGHT:
				if(slideRight(board)) continue;
				break;
			case KEY_LEFT:
				if(slideLeft(board)) continue;
				break;
			case KEY_UP:
				if(slideUp(board)) continue;
				break;
			case KEY_DOWN:
				if(slideDown(board)) continue;
				break;
		}
		placeNum();
	}

    getch();
	endwin();
	return 0;
>>>>>>> 206db47ed50e1f17fcfe45899c5c84997add7928
}


void initialize(){
<<<<<<< HEAD
=======
	
>>>>>>> 206db47ed50e1f17fcfe45899c5c84997add7928
	int i, j;
	for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			board[i][j] = EMPTY;
		}
	}
<<<<<<< HEAD
=======

	mainwin = initscr();
	noecho();
  	keypad(mainwin, TRUE);

>>>>>>> 206db47ed50e1f17fcfe45899c5c84997add7928
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
<<<<<<< HEAD
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
=======
	if (rand()%10 != 0)
		board[i][j] = PRIME;
	else
		board[i][j] = PRIME*PRIME;
}
>>>>>>> 206db47ed50e1f17fcfe45899c5c84997add7928
