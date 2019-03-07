#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"

void initjoueur (joueur *j)

{
    
    j->position.x =700;
    j->position.y =450 ;
    j->im = IMG_Load("jack.bmp");
}
void initjoueurf(joueur *j)

{
    
    j->position.x =700;
    j->position.y =450 ;
    j->im = IMG_Load("lucy.bmp");
}



void afficherjoueur(joueur *j,SDL_Surface *ecran)
{
 SDL_BlitSurface(j->im, NULL, ecran, &j->position);
}

void afficherjoueurf(joueur *j,SDL_Surface *ecran)
{
 SDL_BlitSurface(j->im, NULL, ecran, &j->position);
}

                                        
