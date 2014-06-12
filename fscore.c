#include "fscore.h"
#include <errno.h>

	/* Our structure */
	int saveScore(int score)
	{
		FILE *ptr_myfile;
		
		ptr_myfile=fopen("./tfe.dat","wb");
		if (!ptr_myfile)
		{
			perror("Unable to open file!");
			return -1;
		}

		fwrite(&score, sizeof(score), 1, ptr_myfile);
		
		fclose(ptr_myfile);
		return 0;
	}


	int loadScore()
	{
		FILE *ptr_myfile;
		int score;
		ptr_myfile=fopen("./tfe.dat","rb");
		if (!ptr_myfile)
		{
			perror("Unable to open file!");
			return -1;
		}

		fread(&score,sizeof(score),1,ptr_myfile);

		fclose(ptr_myfile);
		return score;
	}
