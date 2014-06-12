
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
int gameOver();

int board[SIZE][SIZE];
WINDOW * mainwin;
int score[2];
int keyPress;
