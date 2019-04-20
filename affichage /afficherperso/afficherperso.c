#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "afficher.h"



int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;
    SDL_Surface *perso=NULL;
    SDL_Surface *back=NULL;
    SDL_Event event;
    SDL_Rect positionperso,positionback;
    int continuer = 1;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Affichage perso", NULL);
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    perso= IMG_Load("jack.bmp");
    back= IMG_Load("back.bmp");
  //  SDL_BlitSurface(back, NULL, ecran,&positionback);
   // SDL_BlitSurface(perso,NULL, ecran,&positionperso);

    positionperso.x = 151;
    positionperso.y = 210;
    positionback.x = 0;
    positionback.y = 0;
    
    //SDL_EnableKeyRepeat(100,100);
     while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;
            

}


afficher_perso(perso,ecran,back,positionperso,positionback);

}


    SDL_Quit();

    return EXIT_SUCCESS;
}

    
    
    

