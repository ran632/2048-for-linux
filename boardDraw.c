
#include "boardDraw.h"
void printBoard(int board[][SIZE],int *score){ 
	start_color(); 
	
 	drawBlock(0,0,(SIZE+1)*(VER_BORDER)+(SIZE)*(VER_BLOCK),
 		(SIZE+1)*(HOR_BORDER)+(SIZE)*(HOR_BLOCK),0,COLOR_WHITE);    
 	
 	move(0,0);
 	
	int i,j;
	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE; ++j)
			drawBlock(getBlockX(j),getBlockY(i),VER_BLOCK,HOR_BLOCK,board[i][j],
				Logn(board[i][j],PRIME)%(COLORS-1));
	drawScore(score);

}

void drawBlock(int x,int y,int width,int height,int num, int color){
	
	init_pair(color, COLOR_WHITE, color);
	attron(COLOR_PAIR(color));
	int r, c;
	for(r=0;r < height;r++){
		for(c=0;c < width;c++){
   			move(y+r,x+c);
   			printw(" ");
  		}
 	}
 	if (num != EMPTY){
	 	move(y+(HOR_BLOCK/2),x+(VER_BLOCK)/2);
	 	printw("%d", num);
	 }
 	attroff(COLOR_PAIR(color));
}

int getBlockX(int i){
	return ((i+1)*VER_BORDER)+(i*VER_BLOCK);
}

int getBlockY(int j){
	return ((j+1)*HOR_BORDER)+(j*HOR_BLOCK);
	
}

unsigned int Logn(unsigned int n, unsigned int r){
	if(r == EMPTY)
		return 0;
   return (n > r-1)? 1 + Logn(n/r, r): 0;
}

void drawScore(int *score){
	move((SIZE+1)*(HOR_BORDER)+(SIZE)*(HOR_BLOCK),0);
	printw("SCORE: %d", score[0]);
	move((SIZE+1)*(HOR_BORDER)+(SIZE)*(HOR_BLOCK)+1,0);	
	printw("HIGH SCORE:%d",score[1]);
}