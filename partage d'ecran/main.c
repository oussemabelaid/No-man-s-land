#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *bg = NULL, *bg1 = NULL,*perso=NULL, *perso1=NULL;
    SDL_Rect positionbg,positionbg1,positionperso1,positionperso;
int continuer=1 ;


    positionperso.x = 0;
    positionperso.y = 50;
    positionperso1.x = 500;
    positionperso1.y = 50;
    positionbg.x = 0;
    positionbg.y = 0;
    positionbg1.x = 0;
    positionbg1.y = 0;

    SDL_Init(SDL_INIT_VIDEO);

     ecran = SDL_SetVideoMode(950,250, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
 bg = IMG_Load("bg.png");
    

//    bg1 = IMG_Load("bg.png");
   

 perso = IMG_Load("1.png");
   

    perso1 = IMG_Load("1.png");
 

	init_splitscreen(&positionbg,&positionbg1,950);

	SDL_BlitSurface(bg, NULL, ecran, &positionbg);
 SDL_BlitSurface(bg, NULL, ecran, &positionbg1);
 SDL_BlitSurface(perso, NULL, ecran, &positionperso);
 SDL_BlitSurface(perso1, NULL, ecran, &positionperso1);
 SDL_Event event;
    while (continuer)
    {
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
   }

    SDL_Flip(ecran);
}

    SDL_FreeSurface(perso1);
    SDL_FreeSurface(perso);

    SDL_FreeSurface(bg);
 //   SDL_FreeSurface(bg1);

    SDL_Quit();

    return EXIT_SUCCESS;
}
