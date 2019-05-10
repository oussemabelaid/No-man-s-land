#include "jeu.h"

void sauvegarder(Hero perso)
{
	FILE *fp = NULL;


	fp = fopen("save.txt","w");
	if(fp == NULL)
		printf("Erreur de sauvgarde!");
	else{
		
		fprintf(fp,"x=%d\n",perso.positionAbsolue.x);
		fprintf(fp,"y=%d\n",perso.positionAbsolue.y);
                fprintf (fp,"nbrevie=%d\n",perso.vie);
	}
	fclose(fp);
}
 
Hero Loadgame (Hero perso)
{ int x,y,v;
FILE *fp = NULL;
	int i;
	fp = fopen("save.txt","r");
if(fp == NULL)
		printf("Erreur de sauvgarde!");
else{

fscanf(fp,"%d ",&x);
fscanf(fp,"%d ",&y);
fscanf(fp,"%d",&v);
perso.positionAbsolue.x=x;
perso.positionAbsolue.y=y;
perso.vie=v;
}
fclose(fp);
return perso ;
}

