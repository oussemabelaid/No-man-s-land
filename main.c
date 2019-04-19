#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "file.h" 

int bounding_box(SDL_Rect Personnage,SDL_Rect Ennemi)
{
if((Personnage.x<Ennemi.x)&&((Personnage.x+Personnage.w)>=Ennemi.x)&&(Personnage.y<=(Ennemi.y+Ennemi.h))&&((Personnage.y+Personnage.h)>=Ennemi.y))
return 2;
if(((Personnage.x+Personnage.w)>=Ennemi.x)&&(Personnage.x<=(Ennemi.x+Ennemi.w))&&(Personnage.y>Ennemi.y)&&(Personnage.y<=(Ennemi.y+Ennemi.h)))
return 1;
if((Personnage.x>Ennemi.x)&&(Personnage.x<=(Ennemi.x+Ennemi.w))&&(Personnage.y<=(Ennemi.y+Ennemi.h))&&((Personnage.y+Personnage.h)>=Ennemi.y))
return 4;
if((Personnage.y<Ennemi.y)&&((Personnage.y+Personnage.h)>=Ennemi.y)&&((Personnage.x+Personnage.w)>=Ennemi.x)&&(Personnage.x<=(Ennemi.x+Ennemi.w)))
return 3;
else 
return 0;}
