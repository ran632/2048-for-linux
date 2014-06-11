#include "slides.h"


int slide(int board[][SIZE], int SIDE, int *score){
	int stuck = 1;
	int i/*ROW*/, j/*COL*/, k/*temp*/;
	for (i = 0; i < SIZE; i++){
		for (k = 0; k < SIZE; k++){temp[k] = EMPTY;}
		k = (SIDE == KEY_UP || SIDE == KEY_LEFT) ? 0 : SIZE-1;
		j = k;
		while(j < SIZE && j >= 0){
			int x,y;
			if(SIDE == KEY_RIGHT || SIDE == KEY_LEFT){x = i; y = j;}else{x = j; y = i;}
			if (!(board[x][y] == EMPTY)){
				if (temp[k] == 0)
					temp[k] = board[x][y];
				else{
					if(temp[k] == board[x][y]){
						temp[k] = temp[k]*PRIME;
						score[0] = score[0] + temp[k];
						k = (SIDE == KEY_UP || SIDE == KEY_LEFT) ? k+1 : k-1;
					}	
					else{
						k = (SIDE == KEY_UP || SIDE == KEY_LEFT) ? k+1 : k-1;
						temp[k] = board[x][y];
					}
				}
			}
			j = (SIDE == KEY_UP || SIDE == KEY_LEFT) ? j+1 : j-1;
		}
		for(k = 0 ; k < SIZE ; k++){
			int x,y;
			if(SIDE == KEY_RIGHT || SIDE == KEY_LEFT){x = i; y = k;}else{x = k; y = i;}
			if(temp[k] != board[x][y])
				stuck = 0;
			board[x][y] = temp[k];
		}
	}
	return stuck;
}
