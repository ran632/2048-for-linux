#ifndef BOARD_DRAW_H
#define BOARD_DRAW_H  

#define _BSD_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include "slides.h"

#define SIZE 4
#define PRIME 2
#define EMPTY 0
#define VER_BORDER 2
#define HOR_BORDER 1
#define VER_BLOCK 9
#define HOR_BLOCK 5
#define SPRUNG_NUM_DELAY_TIME 85000

void printBoard(int board[][SIZE],int *score);
void drawBlock(int startrow,int startcol,int width,int height,int num,int color);
int getBlockX(int i);
int getBlockY(int j);
unsigned int Logn(unsigned int n, unsigned int r);
void drawScore(int *score);
void springBlock(int board[][SIZE], int i, int j);
void drawGameOver();

#endif
