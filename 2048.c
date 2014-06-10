#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include "slides.h"
#include "boardDraw.h"

void initialize();
int ran();
void placeNum();

int board[SIZE][SIZE];
WINDOW * mainwin;
int score;

int main(){
	initialize();
	placeNum();
	while(1){
		clear();
		refresh();
		printBoard(board, score);
		int keyPress = getch();
		if(!slide(board, keyPress, &score))
			placeNum();
	}

    getch();
	endwin();
	return 0;
}


void initialize(){
	
	int i, j;
	for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			board[i][j] = EMPTY;
		}
	}
	srand(time(NULL));
	mainwin = initscr();
	noecho();
  	keypad(mainwin, TRUE);

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
	if (rand()%10 != 0)
		board[i][j] = PRIME;
	else
		board[i][j] = PRIME*PRIME;
}
