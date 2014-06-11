#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include "slides.h"
#include "boardDraw.h"
#include "fscore.h"

void initialize();
int ran();
void placeNum();
void checkHighScore();

int board[SIZE][SIZE];
WINDOW * mainwin;
int score[2];

int main(){
	initialize();
	placeNum();
	while(1){
		clear();
		refresh();
		printBoard(board, score);
		int keyPress = getch();
		if(!slide(board, keyPress, score))
			placeNum();
		checkHighScore();
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
  	if (loadScore() == -1){
  		saveScore(0);
  	}
  	score[1] = loadScore();
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
void checkHighScore(){
	if (score[0] > score[1]){
		score[1] = score[0];
		saveScore(score[0]);
	}
}