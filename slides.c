#include "slides.h"

void printTest(){

}
int slideLeft(int board[][SIZE]){
	int stuck = 1;
	int i/*ROW*/, j/*COL*/, k/*temp*/;
	for (i = 0; i < SIZE; i++){
		int temp[]= {0,0,0,0};
		k=0;
		for (j = 0; j < SIZE; j++){
			if (board[i][j] == EMPTY)
				continue;
			if (temp[k] == 0)
				temp[k] = board[i][j];
			else if(temp[k] == board[i][j]){
				temp[k] = temp[k]*PRIME;
				k++;
			}	
			else{
				k++;
				temp[k] = board[i][j];
			}
		}
		for(k = 0 ; k < SIZE ; k++){
			if(temp[k] != board[i][k])
				stuck = 0;
			board[i][k] = temp[k];
		}
	}
	return stuck;
}
int slideRight(int board[][SIZE]){
	int stuck = 1;
	int i/*ROW*/, j/*COL*/, k/*temp*/;
	for (i = 0; i < SIZE; i++){
		int temp[]= {0,0,0,0};
		k=SIZE-1;
		for (j = SIZE-1; j >= 0 ; j--){
			if (board[i][j] == EMPTY)
				continue;
			if (temp[k] == 0)
				temp[k] = board[i][j];
			else if(temp[k] == board[i][j]){
				temp[k] = temp[k]*PRIME;
				k--;
			}	
			else{
				k--;
				temp[k] = board[i][j];
			}
		}
		for(k = 0 ; k < SIZE ; k++){
			if(temp[k] != board[i][k])
				stuck = 0;
			board[i][k] = temp[k];
		}
	}
	return stuck;
}
int slideDown(int board[][SIZE]){
	int stuck = 1;
	int i/*ROW*/, j/*COL*/, k/*temp*/;
	for (i = 0; i < SIZE; i++){
		int temp[]= {0,0,0,0};
		k=SIZE-1;
		for (j = SIZE-1; j >= 0 ; j--){
			if (board[j][i] == EMPTY)
				continue;
			if (temp[k] == 0)
				temp[k] = board[j][i];
			else if(temp[k] == board[j][i]){
				temp[k] = temp[k]*PRIME;
				k--;
			}	
			else{
				k--;
				temp[k] = board[j][i];
			}
		}
		for(k = 0 ; k < SIZE ; k++){
			if(temp[k] != board[k][i])
				stuck = 0;
			board[k][i] = temp[k];
		}
	}
	return stuck;
	
}
int slideUp(int board[][SIZE]){
	int stuck = 1;
	int i/*ROW*/, j/*COL*/, k/*temp*/;
	for (i = 0; i < SIZE; i++){
		int temp[]= {0,0,0,0};
		k=0;
		for (j = 0; j < SIZE; j++){
			if (board[j][i] == EMPTY)
				continue;
			if (temp[k] == 0)
				temp[k] = board[j][i];
			else if(temp[k] == board[j][i]){
				temp[k] = temp[k]*PRIME;
				k++;
			}	
			else{
				k++;
				temp[k] = board[j][i];
			}
		}
		for(k = 0 ; k < SIZE ; k++){
			if(temp[k] != board[k][i])
				stuck = 0;
			board[k][i] = temp[k];
		}
	}
	return stuck;

}