#include <stdio.h>
#include <ncurses.h>

#define SIZE 4
#define PRIME 2
#define EMPTY 0

int slideLeft(int board[][SIZE]);
int slideRight(int board[][SIZE]);
int slideDown(int board[][SIZE]);
int slideUp(int board[][SIZE]);
int slide(int board[][SIZE], int SIDE);

int temp[SIZE];