#ifndef AFFICHECHAR_H_INCLUDED
#define AFFICHECHAR_H_INCLUDED

typedef struct joueur
{

  SDL_Surface *im;
  SDL_Rect position ;
  int inv;/*inventaire de personage*/
  int type;/*type de joueur 1 si c'est l'homme 2 si c'est la femme*/

}joueur; 


void initjoueur (joueur *pl);/*initialisation de joueur*/
void afficherjoueur(joueur *j,SDL_Surface *ecran);
void initjoueurf(joueur *pl);/*initialisation de joueur*/
void afficherjoueurf(joueur *j,SDL_Surface *ecran);
