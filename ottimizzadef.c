#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *r,*classifica;
	char defense[64];
	char offense[64];
	char comando[256];
	int percentuale;
	int garbage;
	strcpy(defense,"QVBqLsgjOyBmLwPEPlPE");
	strcpy(offense,"QVBqLsgjOyBmLwPEPlPE");
	while(1)
	{
		sprintf(comando,"tyrant_optimize.exe %s %s -o -e \"Clone Experiment\" climb 100000",defense,offense);
		system(comando);
		printf("-Finito di ottimizzare la difesa\n");
		r=fopen("risultati.txt","r");
		fscanf(r,"%s %d",&defense,&garbage);
		fclose(r);
		sprintf(comando,"tyrant_optimize.exe %s %s -o -s -e \"Clone Experiment\" climb 100000",offense,defense);	//per il miglior risultato possibile, qui togli il -o
		system(comando);
		printf("-Finito di calcolare la percentuale dell'attaccante\n");
		r=fopen("risultati.txt","r");
		fscanf(r,"%s %d",&offense,&percentuale);
		fclose(r);
		classifica=fopen("classificadefCloneExperiment.csv","a");
		fprintf(classifica,"%s; %d;\n",defense,percentuale);
		fclose(classifica);
		printf("-Classifica aggiornata\n");
	}
	return 0;
}