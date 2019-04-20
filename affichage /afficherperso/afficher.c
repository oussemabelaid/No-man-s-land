#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "afficher.h"

void afficher_perso(SDL_Surface *perso,SDL_Surface *ecran,SDL_Surface *back ,SDL_Rect positionperso,SDL_Rect positionback)
{

 SDL_BlitSurface(back, NULL, ecran,&positionback);
    SDL_BlitSurface(perso,NULL, ecran,&positionperso);
SDL_Flip(ecran);
}
