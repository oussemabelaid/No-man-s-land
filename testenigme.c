#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include"enigme.h"


 int main(void) {
int directionSDL=0;
   int collision = 0;
  int game =1;
 enigme *E;
int val;


   SDL_Event event;
   SDL_Surface *screen=NULL,*pomme=NULL,*tanit=NULL,*yes=NULL,*no=NULL,*enigme=NULL, *question=NULL;
	SDL_Surface *re3;
	SDL_Surface *re4, *imageDeFond = NULL;
   SDL_Rect positionpomme,postanit,position;
SDL_Rect posquestion;
	SDL_Rect posrep3;
	SDL_Rect posrep4;
	SDL_Rect rzlt;
position.x = 0;
position.y = 0;
SDL_Init(SDL_INIT_VIDEO);
imageDeFond = SDL_LoadBMP("grand.bmp");
pomme=IMG_Load("pomme.gif");
tanit=IMG_Load("flous 21.png");
screen = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
positionpomme.x=10;
positionpomme.y=400;
positionpomme.w=pomme->w;
positionpomme.h=pomme->h;
postanit.x=150;
postanit.y=310;
postanit.w=tanit->w;
postanit.h=tanit->h;



SDL_Flip(screen);
SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
while (game)
{
  //input from SDL
  while(SDL_PollEvent(&event)){
        switch (event.type)
        {
        // exit if the window is closed
        case SDL_QUIT:
            game = 0;
            break;
        case SDL_KEYDOWN:
        {

            if (event.key.keysym.sym == SDLK_d)
              directionSDL = 1;

            if (event.key.keysym.sym == SDLK_q)
              directionSDL = 2;

        }
        break;
        case SDL_KEYUP:
          directionSDL=0;
        break;

        }
      }

        if(positionpomme.x+positionpomme.w<postanit.x)
            collision=0;
        else
            collision=1;




        if(collision == 1){
      

          affichage(&E, val);
         game=0;
        }


        if((directionSDL == 1 ) && !collision){
             positionpomme.x += 1;


        }
        if ((directionSDL == 2 ) && !collision){
          positionpomme.x -= 1;
        }

        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 255,255, 255));
         SDL_BlitSurface(imageDeFond, NULL, screen, &position);
      
        SDL_BlitSurface(pomme ,NULL, screen, &positionpomme );
        SDL_BlitSurface(tanit ,NULL, screen, &postanit );
        SDL_Flip( screen );

}



SDL_FreeSurface(pomme);
SDL_FreeSurface(tanit);
SDL_FreeSurface(imageDeFond);
SDL_Quit();
return 0;
}
