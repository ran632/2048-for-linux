#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include "slides.h"


// #define SIZE 4
// #define PRIME 2
// #define EMPTY 0

void initialize();
int ran();
void placeNum();
void printBoard();

int board[SIZE][SIZE];
WINDOW * mainwin;

int main(){

  	
	srand(time(NULL));
	initialize();
	placeNum();
	while(1){
		clear();
		refresh();
		printBoard();
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
	board[i][j] = PRIME;
}


void printBoard(){
	int i,j;
	for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			printw("%d\t", board[i][j]);
		}
		printw("\n\n");
	}
}

// void slideRight(){
// 	int i/*ROW*/, j/*COL*/, k/*temp*/;
// 	for (i = 0; i < SIZE; i++){
// 		int temp[]= {0,0,0,0};
// 		k=SIZE-1;
// 		for (j = SIZE-1; j >= 0; j--){
// 			if (board[i][j] == EMPTY)
// 				continue;
// 			if (temp[k] == 0)
// 				temp[k] = board[i][j];
// 			else if(temp[k] == board[i][j]){
// 				temp[k] = temp[k]*PRIME;
// 				k--;
// 			}	
// 			else{
// 				k--;
// 				temp[k] = board[i][j];
// 			}
// 		}
// 		for(k = 0 ; k < SIZE ; k++)
// 			board[i][k] = temp[k];
// 	}
// }
