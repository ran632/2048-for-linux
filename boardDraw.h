#include <stdio.h>
#include <ncurses.h>
#include "slides.h"

#define SIZE 4
#define PRIME 2
#define EMPTY 0
#define VER_BORDER 2
#define HOR_BORDER 1
#define VER_BLOCK 9
#define HOR_BLOCK 5

void printBoard(int board[][SIZE],int score);
void drawBlock(int startrow,int startcol,int width,int height,int num,int color);
int getBlockX(int i);
int getBlockY(int j);
unsigned int Logn(unsigned int n, unsigned int r);
void drawScore(int score);