#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include "initialisation.h"
int main()
{//initialisation declaration 
SDL_Init(SDL_INIT_VIDEO);

SDL_Surface *fenetre =NULL;
SDL_Surface *image =NULL;
SDL_Surface *image1=NULL;
SDL_Surface *image2=NULL	;
SDL_Rect imagepos;
SDL_Rect imageposition;

	vie v1;
	score sc1;
 initialiser_vie(&v1);
	

//score
initialiser_score(&sc1);	


//cree une fenetre 
fenetre=SDL_SetVideoMode(600,800,32,SDL_HWSURFACE);
//ajout d'une image
image=IMG_Load("back.jpg");
imageposition.x=0;
imageposition.y=0;
SDL_BlitSurface(image,NULL, fenetre,&imageposition);
SDL_Flip(fenetre);

image=IMG_Load("aa.png");
imageposition.x=500;
imageposition.y=0;
SDL_BlitSurface(image,NULL, fenetre,&imageposition);
SDL_Flip(fenetre);

image=IMG_Load("4.png");
imageposition.x=30;
imageposition.y=50;
SDL_BlitSurface(image,NULL, fenetre,&imageposition);
SDL_Flip(fenetre);


int continuer=1;
while(continuer)
{

 SDL_Event event;
SDL_WaitEvent(&event);
switch(event.type)
{
case SDL_QUIT:
continuer =0;
break ;
/*
case SDL_VIDEORESIZE:
nlargeur = event.resize.w ;
nhauteur =  event.resize.h ;

break ;*/




}
}
SDL_FreeSurface(image1);
SDL_FreeSurface(image);
SDL_FreeSurface(fenetre);
SDL_Quit();
return 0;
}
