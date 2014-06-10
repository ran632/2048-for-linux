#include "slides.h"


int slide(int board[][SIZE], int SIDE){
	int stuck = 1;
	int i/*ROW*/, j/*COL*/, k/*temp*/;
	printf("in slides\n");

	for (i = 0; i < SIZE; i++){
		printf("i = %d\n", i);
		for (k = 0; k < SIZE; k++){temp[k] = EMPTY;}
		k = (SIDE == KEY_UP || SIDE == KEY_LEFT) ? 0 : SIZE-1;
		j = k;
		while(j < SIZE && j >= 0){
			printf("j = %d\n", j);
			int x,y;
			if(SIDE == KEY_RIGHT || SIDE == KEY_LEFT){x = i; y = j;}else{x = j; y = i;}
			if (!(board[x][y] == EMPTY)){
				if (temp[k] == 0)
					temp[k] = board[x][y];
				else{
					if(temp[k] == board[x][y]){
						temp[k] = temp[k]*PRIME;
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

// int slideLeft(int board[][SIZE]){
// 	int stuck = 1;
// 	int i/*ROW*/, j/*COL*/, k/*temp*/;

// 	for (i = 0; i < SIZE; i++){
// 		for (k = 0; k < SIZE; k++){temp[k] = EMPTY;}
// 		k=0;
// 		for (j = 0; j < SIZE; j++){
// 			if (board[i][j] == EMPTY)
// 				continue;
// 			if (temp[k] == 0)
// 				temp[k] = board[i][j];
// 			else if(temp[k] == board[i][j]){
// 				temp[k] = temp[k]*PRIME;
// 				k++;
// 			}	
// 			else{
// 				k++;
// 				temp[k] = board[i][j];
// 			}
// 		}
// 		for(k = 0 ; k < SIZE ; k++){
// 			if(temp[k] != board[i][k])
// 				stuck = 0;
// 			board[i][k] = temp[k];
// 		}
// 	}
// 	return stuck;
// }
// int slideRight(int board[][SIZE]){
// 	int stuck = 1;
// 	int i/*ROW*/, j/*COL*/, k/*temp*/;
// 	for (i = 0; i < SIZE; i++){
// 		for (k = 0; k < SIZE; k++){temp[k] = EMPTY;}
// 		k=SIZE-1;
// 		for (j = SIZE-1; j >= 0 ; j--){
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
// 		for(k = 0 ; k < SIZE ; k++){
// 			if(temp[k] != board[i][k])
// 				stuck = 0;
// 			board[i][k] = temp[k];
// 		}
// 	}
// 	return stuck;
// }
// int slideDown(int board[][SIZE]){
// 	int stuck = 1;
// 	int i/*ROW*/, j/*COL*/, k/*temp*/;
// 	for (i = 0; i < SIZE; i++){
// 		for (k = 0; k < SIZE; k++){temp[k] = EMPTY;}
// 		k=SIZE-1;
// 		for (j = SIZE-1; j >= 0 ; j--){
// 			if (board[j][i] == EMPTY)
// 				continue;
// 			if (temp[k] == 0)
// 				temp[k] = board[j][i];
// 			else if(temp[k] == board[j][i]){
// 				temp[k] = temp[k]*PRIME;
// 				k--;
// 			}	
// 			else{
// 				k--;
// 				temp[k] = board[j][i];
// 			}
// 		}
// 		for(k = 0 ; k < SIZE ; k++){
// 			if(temp[k] != board[k][i])
// 				stuck = 0;
// 			board[k][i] = temp[k];
// 		}
// 	}
// 	return stuck;
	
// }
// int slideUp(int board[][SIZE]){
// 	int stuck = 1;
// 	int i/*ROW*/, j/*COL*/, k/*temp*/;
// 	for (i = 0; i < SIZE; i++){
// 		for (k = 0; k < SIZE; k++){temp[k] = EMPTY;}
// 		k=0;
// 		for (j = 0; j < SIZE; j++){
// 			if (board[j][i] == EMPTY)
// 				continue;
// 			if (temp[k] == 0)
// 				temp[k] = board[j][i];
// 			else if(temp[k] == board[j][i]){
// 				temp[k] = temp[k]*PRIME;
// 				k++;
// 			}	
// 			else{
// 				k++;
// 				temp[k] = board[j][i];
// 			}
// 		}
// 		for(k = 0 ; k < SIZE ; k++){
// 			if(temp[k] != board[k][i])
// 				stuck = 0;
// 			board[k][i] = temp[k];
// 		}
// 	}
// 	return stuck;

// }



