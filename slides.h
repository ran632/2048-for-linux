#include <stdio.h>
#include <ncurses.h>

#define SIZE 4
#define PRIME 2
#define EMPTY 0

int slide(int board[][SIZE], int SIDE, int *score);

int temp[SIZE];