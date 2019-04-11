#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
//#include "initialisation.h"

int main()
{
//initialisation declaration 
SDL_Init(SDL_INIT_VIDEO);

SDL_Surface *fenetre =NULL;
SDL_Surface *bg =NULL;
SDL_Surface *perso=NULL;
SDL_Rect persopos;



fenetre=SDL_SetVideoMode(1000,780,32,SDL_HWSURFACE);


bg=IMG_Load("bg4.jpg");
persopos.x=0;
persopos.y=0;
SDL_BlitSurface(perso,NULL, fenetre,&persopos);
SDL_Flip(fenetre);

/*

TTF_Font *police=NULL;
        perso p1;
        perso p2; 
        scrol s;
        scrol s1;
        vie v1;
	vie v2;
	score sc1;
	score sc2;
	enemie e1;
	enemie e2;
	Text T;
	int t;
	 SDL_Event event;
        int gameover = 1;
        int test=0,test2=0;

*/
SDL_FreeSurface(perso);
SDL_FreeSurface(bg);
SDL_FreeSurface(fenetre);
SDL_Quit();
return 0;

}
