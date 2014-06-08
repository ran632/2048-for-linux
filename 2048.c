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
}


void initialize(){
	
	int i, j;
	for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			board[i][j] = EMPTY;
		}
	}

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
