#ifndef FSCORE_H
#define FSCORE_H

#include <stdio.h>
#include <curses.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#define USER_NAME_LEN 	15
#define ERROR 			-1
#define FILE_PATH_SIZE	50

int saveScore(int score);
int loadScore();


#endif