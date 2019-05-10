

#include "acceleration.h"
int loadBackground(Background *Backg)
{
	// load background
	Backg->backgroundImg = SDL_LoadBMP("../images/background.bmp");
	if (Backg->backgroundImg == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return (-1);
	}

	Backg->backgroundCollide = SDL_LoadBMP("../images/background.bmp");
	if (Backg->backgroundCollide == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return (-1);
	}
	return (0);
}


void initBackground(Background *Backg)
{
	Backg->backgroundPos.x=0;
	Backg->backgroundPos.y=0;
	Backg->backgroundPos.w=SCREEN_W;
	Backg->backgroundPos.h=SCREEN_H;
}

void blitBackground(Background*Backg,SDL_Surface *screen)
{

	if(Backg->backgroundPos.x>Backg->backgroundImg->w-SCREEN_W)
		Backg->backgroundPos.x=0;
	if(Backg->backgroundPos.x<0)
		Backg->backgroundPos.x=Backg->backgroundImg->w-SCREEN_W;
	SDL_BlitSurface(Backg->backgroundImg, &(Backg->backgroundPos), screen,NULL); 

}

void freeBackground(Background *Backg)
{
	SDL_FreeSurface(Backg->backgroundImg);
}

#include "acceleration.h"

void initText(Text *T)
{
	T->textDt=NULL;
	T->textPosition=NULL;
	T->textVitesse=NULL;
	T->textAcceleration=NULL;
}

int loadFont(TTF_Font **police)
{
	if(TTF_Init() == -1) {
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return EXIT_FAILURE;
	}
	*police = TTF_OpenFont("../images/Ubuntu-Title.ttf", 20);
	return EXIT_SUCCESS;
}


void displayText(TTF_Font *police,Text *T,SDL_Surface *screen,Accelere V,Background Bg,Uint32 dt)
{
	SDL_Color couleurNoire = {0, 0, 0};
	SDL_Color couleurBlanche = {255, 255, 255};
	SDL_Rect positionTextDt;
	SDL_Rect positionTextPos;
	SDL_Rect positionTextVitesse;
	SDL_Rect positionTextAcceleration;

	positionTextDt.x=SCREEN_W-300;
	positionTextPos.x=SCREEN_W-300;
	positionTextVitesse.x=SCREEN_W-300;
	positionTextAcceleration.x=SCREEN_W-300;

	positionTextDt.y=20;
	positionTextPos.y=50;
	positionTextVitesse.y=80;
	positionTextAcceleration.y=110;

	char DT[50];
	char vitesse[50];
	char acceleration[50];
	char position[50];

	//dt
	sprintf(DT,"dt= %d ms",dt);
	T->textDt = TTF_RenderText_Shaded(police,DT,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->textDt, SDL_SRCCOLORKEY, SDL_MapRGB(T->textDt->format, 255, 255, 255));

	//position
	sprintf(position,"pos x=%d pixels",V.position.x);
	T->textPosition = TTF_RenderText_Shaded(police,position,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->textPosition, SDL_SRCCOLORKEY, SDL_MapRGB(T->textPosition->format, 255, 255, 255));
	//vitesse
	sprintf(vitesse,"vitesse= %f m/s",V.velocity);
	T->textVitesse = TTF_RenderText_Shaded(police,vitesse,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->textVitesse, SDL_SRCCOLORKEY, SDL_MapRGB(T->textVitesse->format, 255, 255, 255));
	//acceleration
	sprintf(acceleration,"acceleration= %f m/s/s",V.acceleration);
	T->textAcceleration = TTF_RenderText_Shaded(police,acceleration,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->textAcceleration, SDL_SRCCOLORKEY, SDL_MapRGB(T->textAcceleration->format, 255, 255, 255));
	//clean screen &&
	//Flip the backbuffer to the primary Hardware Video Memory
	SDL_BlitSurface(T->textDt,NULL,screen,&positionTextDt);
	SDL_BlitSurface(T->textPosition,NULL,screen,&positionTextPos);
	SDL_BlitSurface(T->textVitesse,NULL,screen,&positionTextVitesse);
	SDL_BlitSurface(T->textAcceleration,NULL,screen,&positionTextAcceleration);

}

void freeFont(TTF_Font **police)
{
	TTF_CloseFont(*police); /* Doit être avant TTF_Quit() */
    TTF_Quit();	
}

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "acceleration.h"

#include <stdio.h>

int loadAccelereImages(Accelere * A)
{
	int i;
	char buf[50];
	char buf0[]="../images/Accelere";
	char bmp[]=".bmp";
	for(i=0; i<4; i++) {
		sprintf(buf,"%s%d%s",buf0,i,bmp);
		A->image[i] = SDL_LoadBMP(buf);
		if (A->image[i]== NULL) {
			printf("Unable to load  Accelere bitmap:\n");
			return (-1);
		}
		// set the color of Accelere background (white color) as transparent
		SDL_SetColorKey( A->image[i], SDL_SRCCOLORKEY, SDL_MapRGB(A->image[i]->format, 255, 255, 255) );
	}
	return(0);
}

void initAccelere(Accelere *A)
{
	A->direction=0;
	A->position.x=0;
	A->position.y=SCREEN_H - A->image[0]->h;
	A->position.w=A->image[0]->w;
	A->position.h=A->image[0]->h;
	A->score=0;
	A->vie=5;
	A->velocity=0; //velocity=0
	A->acceleration=0;
	A->Mass=70;
	A->moving=0;
}

void moveAccelere(Accelere *A,Background *B,Uint32 dt)
{A->position.x+=0.002*dt+0.5*dt*dt*A->acceleration;

		//Partie 1
}

void freeAccelere(Accelere *A)
{
	int i;
	for(i=0; i<4; i++)
		SDL_FreeSurface(A->image[i]);
}

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "acceleration.h"


int jouer(SDL_Surface * screen)
{
	int done = 0;
	int i=0;
	Uint32 t_prev, dt=1; 
	
	Accelere car;
	Background Backg;
	Text txt;
	
	SDL_Event event;
	int keysHeld[323] = {0}; // everything will be initialized to false
	
	TTF_Font *police = NULL;

	if(loadAccelereImages(&car) == -1) {
		printf("Erreuer Chargement Accelere Images\n");
		return(-1);

	}

	if(loadBackground(&Backg) == -1) {
		printf("Erreuer Chargement Background Images\n");
		return(-1);
	}
	
	if(loadFont(&police) == EXIT_FAILURE){
		printf("Erreuer Chargement Font ttf\n");
		return(-1);
	}

	initBackground(&Backg);
	initAccelere(&car);
	initText(&txt);

	// program Game loop
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);


	while(!done) {
		t_prev=SDL_GetTicks();
		while (SDL_PollEvent(&event)) {
			// check for messages
			switch (event.type) {
				// exit if the window is closed
			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
				car.moving=1; //lets move
				keysHeld[event.key.keysym.sym] = 1;
				break;
			case SDL_KEYUP:
				keysHeld[event.key.keysym.sym] = 0;
				car.moving=0;
				car.velocity=0;
				break;
			}
			// exit if ESCAPE is pressed
			if (keysHeld[SDLK_ESCAPE])
				done = 1;
			if(keysHeld[SDLK_SPACE]) {
				car.velocity=5;
				car.direction=0; //right direction
				car.acceleration+=0.005;
				//moveAccelere(&car,&Backg,dt);
				i++;}
			else
			{if(car.acceleration>0)
			car.acceleration-=0.001;
			
			}
			if(keysHeld[SDLK_CLEAR]) {
			car.acceleration-=0.001;
			
			}
			moveAccelere(&car,&Backg,dt);
		} // end of message processing
		i=i%4;
		//Blit the bachground to the backbuffer
		blitBackground(&Backg,screen);

		//Blit Accelere to screen
		if(!car.moving)
			i=0;
		if(car.direction == 0)
			SDL_BlitSurface(car.image[i],NULL,screen,&car.position);
			
		displayText(police,&txt,screen,car,Backg,0);
		
		SDL_Flip(screen);
		dt=SDL_GetTicks()-t_prev;
		if((1000/FPS)>dt)
		SDL_Delay(1000/FPS-dt);
		
	}

	                // free loaded bitmap

	freeAccelere(&car);
	freeBackground(&Backg);
	TTF_CloseFont(police);
	return(0);
}


