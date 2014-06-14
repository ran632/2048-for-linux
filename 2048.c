#include "2048.h"

int main(){

	while(1){
	initialize();
		while(1){
			printBoard(board, score);
			if(gameOver())break;
			if ('q' == (keyPress = getch()))goto endSession;
			if(!slide(board, keyPress, score)){
				printBoard(board, score);
				placeNum();	
			}
			checkHighScore();
		}
		if ('q' == (keyPress = getch()))break;
	}
	endSession:
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
	score[0] = 0;
  	score[1] = loadScore();
  	//First time game (load score returns -1 (ERROR))
  	if(score[1] == ERROR)
  		score[1] = 0;
	
	srand(time(NULL));
	mainwin = initscr();
	noecho();
  	keypad(mainwin, TRUE);
  	if (loadScore() == ERROR){
  		saveScore(0);
  	}
  	printBoard(board, score);
	springBlock(board, 0, 0);
	sleep(1);
	placeNum();
	placeNum();
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
	springBlock(board, i, j);
	
}
void checkHighScore(){
	if (score[0] > score[1]){
		score[1] = score[0];
		saveScore(score[0]);
	}
}

int gameOver(){
	int i, j;
	for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			if (board[i][j] == EMPTY)
				return 0;
			if (i != SIZE-1)
				if (board[i][j] == board[i+1][j])
					return 0;
			if (j != SIZE-1)
				if (board[i][j] == board[i][j+1])
					return 0;
		}
	}
	refresh();
	sleep(2);
	drawGameOver(score[0]);
	return 1;
}