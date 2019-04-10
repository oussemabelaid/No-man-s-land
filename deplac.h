#define RIGHT 1
#define LEFT 2

#define ENEMY_Height 80
#define ENEMY_Width 80

#define Backg_W 8000
#define Backg_H 600

#define MAXF 3


/*_________   structure numero 1  ____________ */



typedef struct Acteurs Acteurs;
struct Acteurs
{
	  SDL_Surface *screen;
    SDL_Event event ;

	//fond
	SDL_Surface *fond ;
	SDL_Rect posFond;

  //fond noir
  SDL_Surface* backg;
};
/*_________   structure de l hero  ____________ */

typedef struct Hero Hero ;
struct Hero 
{

SDL_Surface *sprite;

/* Coordonnées du héros */
int x , y ;

/* Variables utiles pour l'animation */

int etat  , direction ; 

};
typedef struct Entite
{
   SDL_Surface* sprite;
  int x;
  int y; //destination
}Entite;
void updatePlayer(Hero* hero , Acteurs* acteurs, SDL_Rect camera, SDL_Rect* frame) ;
void initializeEnemy(Entite* entitee);
void drawEnemy(Entite* entitee , Acteurs* acteurs);

#endif
