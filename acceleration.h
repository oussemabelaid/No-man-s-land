#ifndef ACCELERATION_H
#define ACCELERATION_H

#ifndef DEFS_H
#define DEFS_H

#define FPS 60
#define ACCELX 0
#define ACCELY 0
#define SCREEN_W 1000
#define SCREEN_H 400
typedef int bool;
enum { false, true };

#endif

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL/SDL.h>


struct Background{
	SDL_Surface *backgroundImg;
	SDL_Surface *backgroundCollide;
	SDL_Rect backgroundPos;
};
typedef struct Background Background;

int loadBackground(Background *Backg);
void initBackground(Background *Backg);
void freeBackground(Background *Backg);
void blitBackground(Background*Backg,SDL_Surface *screen);

#endif


#ifndef ACCELERE_H
#define ACCELERE_H
#include <SDL/SDL.h>


		

		
struct Accelere{
	SDL_Rect position;
	SDL_Surface * image[5];
	int score;
	int vie;
	
	int direction; //0:right 1:left 2:up
	int moving; //0:not moving 1:moving
	float Mass;

	double velocity;
	double acceleration;
};
typedef struct Accelere Accelere;

int loadAccelereImages(Accelere * A);

void initAccelere(Accelere *A);

void moveAccelere(Accelere *A,Background *B,Uint32 dt);


void freeAccelere(Accelere *A);

#endif
#ifndef JEU_H
#define JEU_H

#include <SDL/SDL.h>

int jouer(SDL_Surface * screen);

#endif

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL/SDL.h>


struct Background{
	SDL_Surface *backgroundImg;
	SDL_Surface *backgroundCollide;
	SDL_Rect backgroundPos;
};
typedef struct Background Background;

int loadBackground(Background *Backg);
void initBackground(Background *Backg);
void freeBackground(Background *Backg);
void blitBackground(Background*Backg,SDL_Surface *screen);

#endif

#ifndef TEXT_H
#define TEXT_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>


struct Text {
	SDL_Surface *textDt;
	SDL_Surface *textPosition;
	SDL_Surface *textVitesse;
	SDL_Surface *textAcceleration;
};
typedef struct Text Text;


void initText(Text *T);
int loadFont(TTF_Font **police);
void displayText(TTF_Font *police,Text *T,SDL_Surface *screen,Accelere V,Background Bg,Uint32 dt);

#endif
#endif
