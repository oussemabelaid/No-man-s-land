#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "initialisation.h"



void initialiser_vie(vie *v1)
{
v1->nb=3;
v1->posvie.x=0;
v1->posvie.y=0;
v1->vie0=IMG_Load("unnamed.png");
v1->vie1=IMG_Load("unnamed2.png");
v1->vie2=IMG_Load("3.png");

}

/*


void initialiser_vie2(vie *v2)
{
v2->nb=3;
v2->posvie.x=630;
v2->posvie.y=0;
v2->vie0=IMG_Load("");
v2->vie1=IMG_Load("");
v2->vie2=IMG_Load("");
v2->vie3=IMG_Load("");
}
*/


void afficher_vie(vie *v,SDL_Surface *ecran)
{
if (v->nb==3)
{
SDL_BlitSurface(v->vie3,NULL,ecran,&v->posvie);
}

if (v->nb==2)
{
SDL_BlitSurface(v->vie2,NULL,ecran,&v->posvie);
}
if (v->nb==1)
{
SDL_BlitSurface(v->vie1,NULL,ecran,&v->posvie);
}
if (v->nb==0)
{
SDL_BlitSurface(v->vie0,NULL,ecran,&v->posvie);
}

}
/*
void afficher_vie2(vie *v2,SDL_Surface *ecran)
{
if (v2->nb==3)
{
SDL_BlitSurface(v2->vie3,NULL,ecran,&v2->posvie);
}

if (v2->nb==2)
{
SDL_BlitSurface(v2->vie2,NULL,ecran,&v2->posvie);
}
if (v2->nb==1)
{
SDL_BlitSurface(v2->vie1,NULL,ecran,&v2->posvie);
}
if (v2->nb==0)
{
SDL_BlitSurface(v2->vie0,NULL,ecran,&v2->posvie);
}





}
*/

void initialiser_score(score *sc1)
{
//score1
sc1->posscore.x=600;
sc1->posscore.y=0;
sc1->nb=1000;
sc1->textscore=NULL;
sc1->police=NULL;
sc1->police=TTF_OpenFont("eya.TTF",30);
}



/*
void initialiser_score2(score *sc2)
{
sc2->posscore.x=1150;
sc2->posscore.y=0;
sc2->nb=1000;
sc2->textscore=NULL;
sc2->police=NULL;
sc2->police=TTF_OpenFont("angelina.TTF",30);
}
*/

void afficher_score(score *sc1,SDL_Surface *ecran)

{
SDL_Color noire={0,0,0};
if (sc1->nb<0)
{sc1->nb=0;}
sprintf(sc1->resultat,"%d",sc1->nb);

sc1->textscore=TTF_RenderText_Blended(sc1->police,sc1->resultat,noire);
SDL_BlitSurface(sc1->textscore,NULL,ecran,&(sc1->posscore));

}
/*
void afficher_score2(score *sc2,SDL_Surface *ecran)

{
SDL_Color noire={0,0,0};
if (sc2->nb<0)
{sc2->nb=0;}
sprintf(sc2->resultat,"%d",sc2->nb);

sc2->textscore=TTF_RenderText_Blended(sc2->police,sc2->resultat,noire);
SDL_BlitSurface(sc2->textscore,NULL,ecran,&(sc2->posscore));

}

*/





 void load_background(background *b)
{
b->fond=NULL;
b->fond=IMG_Load("back.jpg");
}

void init_background(background *b)
{
b->position.x=0;//-252;
b->position.y=0;//-6048;
b->position.w = b->fond->w;
b->position.h = b->fond->h;
}

 void display_background(background *b,SDL_Surface *ecran)
{

SDL_BlitSurface(b->fond,NULL,ecran,&(b->position));
SDL_Flip(ecran);
}


















    

