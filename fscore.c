#include "fscore.h"




int getPath(char* path)
{
	char userName[USER_NAME_LEN];

	if(getlogin_r(userName, USER_NAME_LEN) != 0)
	{
		//free(path);
		return ERROR;
	}


	strcat(path, userName);
	strcat(path, "/.2048/tfe.dat");
	printf("%s\n", path);
	return 0;

}


	/* Our structure */
int saveScore(int score)
{
	FILE *ptr_myfile;
	char path[FILE_PATH_SIZE] = "/home/";
	if(getPath(path) != 0) 
	{
		perror("ERROR: Cann`t get User Name on host. aborting");
		return ERROR;
	} 
	ptr_myfile=fopen(path,"wb");
	if (!ptr_myfile)
	{
		perror("Unable to open file for save!");
		return ERROR;
	}

	fwrite(&score, sizeof(score), 1, ptr_myfile);

	fclose(ptr_myfile);


	return 0;
}


int loadScore()
{
	FILE *ptr_myfile;
	int score;
	char path[FILE_PATH_SIZE] = "/home/";
	if(getPath(path) != 0) 
	{
		perror("ERROR: Cann`t get User Name on host. aborting");
		return ERROR;
	} 
	ptr_myfile=fopen(path,"rbw+");
	if (!ptr_myfile)
	{
		perror("Unable to open file for load!");
		return ERROR;
	}

	fread(&score,sizeof(score),1,ptr_myfile);

	fclose(ptr_myfile);

	return score;
}
