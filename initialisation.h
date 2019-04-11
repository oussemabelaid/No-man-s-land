#ifndef ENTITE_H_INCLUDED
#define ENTITE_H_INCLUDED


#define CAMERA_W 1200
#define CAMERA_H 900
#include <SDL/SDL.h>

#include <SDL/SDL_ttf.h>

typedef struct vie
{
int nb;
SDL_Surface *vie0;
SDL_Surface *vie1;
SDL_Surface *vie2;
SDL_Surface *vie3;
SDL_Rect posvie;
}vie;
typedef struct score
{
int nb;
char resultat[20];
SDL_Surface *textscore;
SDL_Rect posscore;
TTF_Font *police;
}score;

typedef struct background{

SDL_Surface *fond;
SDL_Rect position;
}background;

void load_background(background *b);
void init_background(background *b);
void display_background(background *b,SDL_Surface *ecran);

void initialiser_vie(vie *v);
void afficher_vie(vie *v,SDL_Surface *ecran);
/*void initialiser_vie2(vie *v2);
void afficher_vie2(vie *v2,SDL_Surface *ecran);*/




void initialiser_score(score *s);
void afficher_score(score *sc1,SDL_Surface *ecran);



/*	
void initialiser_score2(score *sc2);
void afficher_score2(score *sc2,SDL_Surface *ecran);
*/
#endif
