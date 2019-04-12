#include <stdlib.h>
#include <stdio.h>
#include"SDL/SDL_ttf.h"
#include"vie.h"
#include"score.h"
#include"clock.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include<time.h>



int main()
 {
SDL_Surface *screen;
tempss temp;
vie v;
int test=0;
int i=0;
score scor;
SDL_Init(SDL_INIT_EVERYTHING);
TTF_Init();

screen=SDL_SetVideoMode(900,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
scor=intialiser_score(scor);
temp=inisaliser_temp_decompteur(temp,1);
v=init_vie(v);
v=updatevie(v,test,screen);


displayvie(v,screen);
SDL_Flip(screen);
SDL_Delay(500);
test=1;
v=updatevie(v,test,screen);
displayvie(v,screen);
SDL_Flip(screen);
SDL_Delay(500);

v=updatevie(v,test,screen);
displayvie(v,screen);
SDL_Flip(screen);
SDL_Delay(1000);
do
{

temp=gestion_temps_decompteur(0,0,temp,screen);
scor=gestion_score(0,0,0,0,scor,screen,0);
i++;
}while(i!=20);
afficher_score(scor,screen);

SDL_Delay(2000);



}
