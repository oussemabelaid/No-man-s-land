#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

void menu()
{int screen = 1;
int x,y;
int i=1;
int j=1;
int r;
int o=0;
int w=0;
int continuer=1;
int play=1;
SDL_Event event;
SDL_Surface *ecran=NULL, /**image=NULL,*/ *text=NULL;
TTF_Font *police=NULL;
SDL_Color couleurnoir={0,0,0};  
SDL_Surface *imagef;  
SDL_Surface *im1=NULL;
SDL_Surface *im11=NULL;
SDL_Surface *im2=NULL;
SDL_Surface *im22=NULL;
SDL_Surface *im3=NULL;
SDL_Surface *im33=NULL;
SDL_Surface *im4=NULL;
SDL_Surface *im44=NULL;
SDL_Surface *im5=NULL;
SDL_Surface *im55=NULL;
SDL_Surface *im6=NULL;
SDL_Surface *im66=NULL;
SDL_Surface *f1=NULL;
SDL_Surface *f2=NULL;
SDL_Surface *sound=NULL;
SDL_Surface *keys=NULL;
SDL_Surface *langue=NULL;
SDL_Surface *back2=NULL;
SDL_Surface *f2f=NULL;
SDL_Surface *soundf=NULL;
SDL_Surface *keysf=NULL;
SDL_Surface *languef=NULL;

SDL_Rect positionsound;
SDL_Rect positionkeys;
SDL_Rect positionlangue;
SDL_Rect positionsoundf;
SDL_Rect positionkeysf;
SDL_Rect positionlanguef;

//SDL_Rect positionFond;
SDL_Surface *back1=NULL;
SDL_Rect positionim1;
SDL_Rect positionback1;
SDL_Rect pos_text;

SDL_Rect positionim2;
SDL_Rect positionFond1;
SDL_Rect positionim3;
SDL_Rect positionf1;
SDL_Rect positionim4;
SDL_Rect positionf2;
SDL_Rect positionim5;
Mix_Music *musique;
Mix_Chunk *son;
positionfull.x=360;
positionfull.y=150; 
 
positionsound.x=427;
positionsound.y=140;

positionkeys.x=427;
positionkeys.y=300;


positionlangue.x=427;
positionlangue.y=452;

positionsoundf.x=857;
positionsoundf.y=280;

positionkeysf.x=854;
positionkeysf.y=600;


positionlanguef.x=854;
positionlanguef.y=904;


positionFond1.x = 0;
positionFond1.y = 0;

positionf1.x=698;
positionf1.y=116;

positionf2.x=698;
positionf2.y=405; 

positionf2f.x=1386;
positionf2f.y=810; 

positionback1.x=0;
positionback1.y=0;

//positionFond.x = 0;
//positionFond.y = 0;

positionim1.x = 270;
positionim1.y = 100; 


positionim2.x = 270;
positionim2.y = 170;


positionim3.x = 270;
positionim3.y = 240;


positionim4.x = 270;
positionim4.y = 310;


positionim5.x = 270;
positionim5.y = 380;

pos_text.x=600;
pos_text.y=250;

SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
TTF_Init();
//police= TTF_OpenFont("Loma.ttf",65);
//text= TTF_RenderText_Blended(police,"enjoy it !",couleurnoir);

ecran=SDL_SetVideoMode(800, 600, 32,SDL_HWSURFACE|SDL_DOUBLEBUF | SDL_SRCALPHA);
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) 

  printf("%s", Mix_GetError());
if (ecran==NULL)
printf ("Erreur");
else
SDL_WM_SetIcon ( IMG_Load("../images/icon-fin.jpg"), NULL );



musique = Mix_LoadMUS("../images/music2.mp3");
Mix_VolumeMusic(MIX_MAX_VOLUME * 2);
son = Mix_LoadWAV("../images/Mouse_Click_Fast.wav");
Mix_PlayMusic(musique, -1);

sound=IMG_Load("../images/sound.png");
soundf=IMG_Load("../images/soundf.png");
//video=IMG_Load("../images/video.png");
keys=IMG_Load("../images/KEYS.png");
keysf=IMG_Load("../images/KEYSf.png");
langue=IMG_Load("../images/full.png");
languef=IMG_Load("../images/fullf.png");
imagef=IMG_Load("../images/back.png");
f1=IMG_Load("../images/on.png");
f2=IMG_Load("../images/off.png");
f2f=IMG_Load("../images/offf.png");
map=IMG_Load("../images/back.png");
back2=IMG_Load("../images/back2.bmp");
back1=IMG_Load("../images/back1.");
SDL_BlitSurface(text,NULL,ecran,&pos_text);
im1=IMG_Load("../images/newgame.png");
SDL_BlitSurface(im1,NULL,ecran,&positionim1);

im2=IMG_Load("../images/continuee.png");
SDL_BlitSurface(im2,NULL,ecran,&positionim2);

 
im3=IMG_Load("../images/multi.png");
SDL_BlitSurface(im3,NULL,ecran,&positionim3);

  
im4=IMG_Load("../images/options.png");
SDL_BlitSurface(im4,NULL,ecran,&positionim4);

im5=IMG_Load("../images/exit.png");
SDL_BlitSurface(im5,NULL,ecran,&positionim4);

	
SDL_Flip(ecran);
im11=IMG_Load("../images/newgamem.png");
im22=IMG_Load("../images/continuem.png");

im33=IMG_Load("../images/multim.png");
im44=IMG_Load("../images/optionsm.png");
im55=IMG_Load("../images/exitm.png");

while (screen)
    {
        SDL_WaitEvent(&event);
switch(event.type)
{ case SDL_QUIT:
    screen = 0; 
  case SDL_KEYDOWN:
 switch (event.key.keysym.sym)
            {
                case SDLK_DOWN:
			
								
				switch(i)
				{
					case 1:
						i++;
						//initialliser ecran

						//SDL_BlitSurface(image,NULL,ecran,&positionFond);

						SDL_BlitSurface(im1,NULL,ecran,&positionim1);

						SDL_BlitSurface(im2,NULL,ecran,&positionim2);		

  

						SDL_BlitSurface(im3,NULL,ecran,&positionim3);

 

						SDL_BlitSurface(im4,NULL,ecran,&positionim4);

 

						SDL_BlitSurface(im5,NULL,ecran,&positionim5);

						

						SDL_BlitSurface(im11,NULL,ecran,&positionim1);

                                                
                                                SDL_BlitSurface(text,NULL,ecran,&pos_text);


                                                Mix_PlayChannel(1, son, 0);


						SDL_Flip(ecran);	
						break;
					case 2:		

						i++;
						//initialliser ecran

					//SDL_BlitSurface(image,NULL,ecran,&positionFond);

						SDL_BlitSurface(im1,NULL,ecran,&positionim1);

						SDL_BlitSurface(im2,NULL,ecran,&positionim2);

  

						SDL_BlitSurface(im3,NULL,ecran,&positionim3);

 

						SDL_BlitSurface(im4,NULL,ecran,&positionim4);

 

						SDL_BlitSurface(im5,NULL,ecran,&positionim5);

						

						SDL_BlitSurface(im22,NULL,ecran,&positionim2);
                                                Mix_PlayChannel(1, son, 0);
                                                SDL_BlitSurface(text,NULL,ecran,&pos_text);
						SDL_Flip(ecran);
						break;
					case 3:		

						i++;
						//initialliser ecran


						SDL_BlitSurface(im1,NULL,ecran,&positionim1);

						SDL_BlitSurface(im2,NULL,ecran,&positionim2);

  

						SDL_BlitSurface(im3,NULL,ecran,&positionim3);

 

						SDL_BlitSurface(im4,NULL,ecran,&positionim4);

 

						SDL_BlitSurface(im5,NULL,ecran,&positionim5);

						

 Mix_PlayChannel(1, son, 0);					SDL_BlitSurface(im33,NULL,ecran,&positionim3);
SDL_BlitSurface(text,NULL,ecran,&pos_text);
						SDL_Flip(ecran);	
						break;
					case 4:		

						i++;

						//initialliser ecran


						SDL_BlitSurface(im1,NULL,ecran,&positionim1);

						SDL_BlitSurface(im2,NULL,ecran,&positionim2);

  

						SDL_BlitSurface(im3,NULL,ecran,&positionim3);

 

						SDL_BlitSurface(im4,NULL,ecran,&positionim4);

 
	
						SDL_BlitSurface(im5,NULL,ecran,&positionim5);

						

						SDL_BlitSurface(im44,NULL,ecran,&positionim4);
Mix_PlayChannel(1, son, 0);
SDL_BlitSurface(text,NULL,ecran,&pos_text);
						SDL_Flip(ecran);	
						break;
					case 5:		

						i=1;
						//initialliser ecran



						SDL_BlitSurface(im1,NULL,ecran,&positionim1);

						SDL_BlitSurface(im2,NULL,ecran,&positionim2);

  

						SDL_BlitSurface(im3,NULL,ecran,&positionim3);

 

						SDL_BlitSurface(im4,NULL,ecran,&positionim4);

 

						SDL_BlitSurface(im5,NULL,ecran,&positionim5);

						

Mix_PlayChannel(1, son, 0);						SDL_BlitSurface(im55,NULL,ecran,&positionim5);
SDL_BlitSurface(text,NULL,ecran,&pos_text);
						SDL_Flip(ecran);
						break;	


					
            		
		
		}
		break;
		
		case SDLK_UP:
			
					switch(i)
					{	
					case 1:
					
						

						i=5;
						//initialliser ecran



						SDL_BlitSurface(im1,NULL,ecran,&positionim1);

						SDL_BlitSurface(im2,NULL,ecran,&positionim2);

  

						SDL_BlitSurface(im3,NULL,ecran,&positionim3);

 

						SDL_BlitSurface(im4,NULL,ecran,&positionim4);

 

						SDL_BlitSurface(im5,NULL,ecran,&positionim5);

						

						SDL_BlitSurface(im11,NULL,ecran,&positionim1);
Mix_PlayChannel(1, son, 0);
SDL_BlitSurface(text,NULL,ecran,&pos_text);
						SDL_Flip(ecran);
						break;
					case 2:		

						i--;
						//initialliser ecran


						SDL_BlitSurface(im1,NULL,ecran,&positionim1);

						SDL_BlitSurface(im2,NULL,ecran,&positionim2);

  

						SDL_BlitSurface(im3,NULL,ecran,&positionim3);

 

						SDL_BlitSurface(im4,NULL,ecran,&positionim4);

 

						SDL_BlitSurface(im5,NULL,ecran,&positionim5);

						

						SDL_BlitSurface(im22,NULL,ecran,&positionim2);
Mix_PlayChannel(1, son, 0);
SDL_BlitSurface(text,NULL,ecran,&pos_text);
						SDL_Flip(ecran);	
						break;
					case 3:		

						i--;
						//initialliser ecran


						SDL_BlitSurface(im1,NULL,ecran,&positionim1);

						SDL_BlitSurface(im2,NULL,ecran,&positionim2);

  

						SDL_BlitSurface(im3,NULL,ecran,&positionim3);

 

						SDL_BlitSurface(im4,NULL,ecran,&positionim4);

 
	
						SDL_BlitSurface(im5,NULL,ecran,&positionim5);

						

						SDL_BlitSurface(im33,NULL,ecran,&positionim3);
Mix_PlayChannel(1, son, 0);
SDL_BlitSurface(text,NULL,ecran,&pos_text);
						SDL_Flip(ecran);	
						break;
					case 4:		

						i--;


						SDL_BlitSurface(im1,NULL,ecran,&positionim1);

						SDL_BlitSurface(im2,NULL,ecran,&positionim2);

  

						SDL_BlitSurface(im3,NULL,ecran,&positionim3);

 

						SDL_BlitSurface(im4,NULL,ecran,&positionim4);

 

						SDL_BlitSurface(im5,NULL,ecran,&positionim5);

						

 
Mix_PlayChannel(1, son, 0);					SDL_BlitSurface(im44,NULL,ecran,&positionim4);
SDL_BlitSurface(text,NULL,ecran,&pos_text);
						SDL_Flip(ecran);
						break;	


					case 5:		

						i--;
						//initialliser ecran


						SDL_BlitSurface(im1,NULL,ecran,&positionim1);

						SDL_BlitSurface(im2,NULL,ecran,&positionim2);

  

						SDL_BlitSurface(im3,NULL,ecran,&positionim3);

 

						SDL_BlitSurface(im4,NULL,ecran,&positionim4);

 

						SDL_BlitSurface(im5,NULL,ecran,&positionim5);

						

						SDL_BlitSurface(im55,NULL,ecran,&positionim5);
Mix_PlayChannel(1, son, 0);
SDL_BlitSurface(text,NULL,ecran,&pos_text);	
						SDL_Flip(ecran);
                				break;
            		
		
		}
		break;

		}
 

case SDL_MOUSEBUTTONUP:
     if (((event.button.x >=270)&&(event.button.x <=470))&&((event.button.y <= 430)&&(event.button.y >= 380)))

if(event.button.button == SDL_BUTTON_LEFT)
{
screen=0;
 Mix_PlayChannel(1, son, 0);
}
if (((event.motion.x >=270)&&(event.motion.x <=470))&&((event.motion.y <= 150)&&(event.motion.y >= 100)))
if(event.button.button == SDL_BUTTON_LEFT)
{Mix_PlayChannel(1, son, 1);
//jouerard(r,ecran);
jouer(ecran,perso);
//sous();
while (play)
{

SDL_WaitEvent(&event);
switch (event.type) 
{
case SDL_MOUSEBUTTONUP:

if(event.button.button == SDL_BUTTON_RIGHT)
play=0;
}
}
}
if (((event.motion.x >=270)&&(event.motion.x <=470))&&((event.motion.y <= 220)&&(event.motion.y >= 170)))
if(event.button.button == SDL_BUTTON_LEFT)
{Mix_PlayChannel(1, son, 1);
//jouerard(r,ecran);
perso=Loadgame (perso);
jouer(ecran,perso);
//multiplayer(screen);
//sous();
while (play)
{

SDL_WaitEvent(&event);
switch (event.type) 
{
case SDL_MOUSEBUTTONUP:

if(event.button.button == SDL_BUTTON_RIGHT)
play=0;
}
}
}
if (((event.motion.x >=270)&&(event.motion.x <=470))&&((event.motion.y <= 360)&&(event.motion.y >= 310)))
if(event.button.button == SDL_BUTTON_LEFT)
{Mix_PlayChannel(1, son, 1);
//jouerard(r,ecran);
//perso=Loadgame (perso);
//jouer(ecran,perso);
multiplayer(screen);
//sous();
while (play)
{

SDL_WaitEvent(&event);
switch (event.type) 
{
case SDL_MOUSEBUTTONUP:

if(event.button.button == SDL_BUTTON_RIGHT)
play=0;
}
}
}

if (((event.motion.x >=270)&&(event.motion.x <=470))&&((event.motion.y <= 290)&&(event.motion.y >= 240)))
if(event.button.button == SDL_BUTTON_LEFT)
{Mix_PlayChannel(1, son, 1);
SDL_BlitSurface(back1,NULL,ecran,&positionFond1);
SDL_BlitSurface(sound,NULL,ecran,&positionsound);
SDL_BlitSurface(keys,NULL,ecran,&positionkeys);
SDL_BlitSurface(langue,NULL,ecran,&positionlangue);
SDL_BlitSurface(f1,NULL,ecran,&positionf1);
SDL_BlitSurface(f1,NULL,ecran,&positionf2);
SDL_Flip(ecran);
continuer=1;
while (continuer)
{

SDL_WaitEvent(&event);
switch (event.type) 
{
case SDL_MOUSEBUTTONUP:
 if (((event.button.x >=698)&&(event.button.x <=750))&&((event.button.y <= 188)&&(event.button.y >= 116)))
switch (j)
{case 1:
j--;
if(event.button.button == SDL_BUTTON_LEFT)
{

SDL_BlitSurface(back1,NULL,ecran,&positionFond1);
SDL_BlitSurface(sound,NULL,ecran,&positionsound);
SDL_BlitSurface(keys,NULL,ecran,&positionkeys);
SDL_BlitSurface(langue,NULL,ecran,&positionlangue);
SDL_BlitSurface(f2,NULL,ecran,&positionf1);
SDL_Flip(ecran);
Mix_PauseMusic(); 
}
break;
case 0:
j++;
if((event.button.button == SDL_BUTTON_LEFT)&&(Mix_PausedMusic() == 1))
{Mix_RewindMusic();
Mix_ResumeMusic();

SDL_BlitSurface(back1,NULL,ecran,&positionFond1);
SDL_BlitSurface(sound,NULL,ecran,&positionsound);
SDL_BlitSurface(keys,NULL,ecran,&positionkeys);
SDL_BlitSurface(langue,NULL,ecran,&positionlangue);
SDL_BlitSurface(f1,NULL,ecran,&positionf1);
SDL_Flip(ecran);}
break;}

if (((event.button.x >=1386)&&(event.button.x <=1420))&&((event.button.y <= 880)&&(event.button.y >= 810)))
switch (j)
{case 1:
j--;
if(event.button.button == SDL_BUTTON_LEFT)
{ecran=SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE);
SDL_BlitSurface(back2,NULL,ecran,&positionFond1);
SDL_BlitSurface(soundf,NULL,ecran,&positionsoundf);
SDL_BlitSurface(video,NULL,ecran,&positionvideo);
SDL_BlitSurface(keysf,NULL,ecran,&positionkeysf);
SDL_BlitSurface(languef,NULL,ecran,&positionlanguef);
SDL_BlitSurface(f2f,NULL,ecran,&positionf1);
SDL_Flip(ecran);

}
break;
case 0:
j++;
if((event.button.button == SDL_BUTTON_LEFT)&&(Mix_PausedMusic() == 1))
{ecran=SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
SDL_BlitSurface(back1,NULL,ecran,&positionFond1);
SDL_BlitSurface(sound,NULL,ecran,&positionsound);
SDL_BlitSurface(video,NULL,ecran,&positionvideo);
SDL_BlitSurface(keys,NULL,ecran,&positionkeys);
SDL_BlitSurface(langue,NULL,ecran,&positionlangue);
SDL_BlitSurface(f1,NULL,ecran,&positionf1);
SDL_Flip(ecran);}
break;}
 if(event.button.button == SDL_BUTTON_RIGHT)
continuer=0;
break;

}}}





break;
case SDL_MOUSEMOTION:

if (((event.motion.x >=270)&&(event.motion.x <=470))&&((event.motion.y <= 150)&&(event.motion.y >= 100)))

{

SDL_BlitSurface(im11,NULL,ecran,&positionim1);
Mix_PlayChannel(1, son, 0);
SDL_Flip(ecran);
}
else if (((event.motion.x >=270)&&(event.motion.x <=470))&&((event.motion.y <= 220)&&(event.motion.y >= 170)))

{

SDL_BlitSurface(im22,NULL,ecran,&positionim2);
SDL_BlitSurface(text,NULL,ecran,&pos_text);
Mix_PlayChannel(1, son, 0);
SDL_Flip(ecran);
}
else if (((event.motion.x >=270)&&(event.motion.x <=470))&&((event.motion.y <= 290)&&(event.motion.y >= 240)))

{

SDL_BlitSurface(im33,NULL,ecran,&positionim3);
SDL_BlitSurface(text,NULL,ecran,&pos_text);
 Mix_PlayChannel(1, son, 0);
SDL_Flip(ecran);
}
else if (((event.motion.x >=270)&&(event.motion.x <=470))&&((event.motion.y <= 360)&&(event.motion.y >= 310)))

{

SDL_BlitSurface(im44,NULL,ecran,&positionim4);
SDL_BlitSurface(text,NULL,ecran,&pos_text);
 Mix_PlayChannel(1, son, 0);
SDL_Flip(ecran);
}
else if (((event.motion.x >=270)&&(event.motion.x <=470))&&((event.motion.y <= 430)&&(event.motion.y >= 380)))

{

SDL_BlitSurface(im55,NULL,ecran,&positionim5);
SDL_BlitSurface(text,NULL,ecran,&pos_text);
 Mix_PlayChannel(1, son, 0);
SDL_Flip(ecran);
}
else if (((event.motion.x >=270)&&(event.motion.x <=470))&&((event.motion.y <= 500)&&(event.motion.y >= 450)))

{

SDL_BlitSurface(im66,NULL,ecran,&positionim6);
SDL_BlitSurface(text,NULL,ecran,&pos_text);
 Mix_PlayChannel(1, son, 0);
SDL_Flip(ecran);
}
else {

SDL_BlitSurface(im11,NULL,ecran,&positionim1);
Mix_PlayChannel(1, son, 0);
SDL_Flip(ecran);
}		



SDL_BlitSurface(im1,NULL,ecran,&positionim1);

SDL_BlitSurface(im2,NULL,ecran,&positionim2);

  

SDL_BlitSurface(im3,NULL,ecran,&positionim3);

 

SDL_BlitSurface(im4,NULL,ecran,&positionim4);

 

SDL_BlitSurface(im5,NULL,ecran,&positionim5);


SDL_BlitSurface(text,NULL,ecran,&pos_text);

   SDL_Flip(ecran);

}


            break;


} 
}
   SDL_Quit;
  
}

