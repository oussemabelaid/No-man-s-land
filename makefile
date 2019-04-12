game:timetest.o  vie.o clock.o score.o
	gcc timetest.o   vie.o  clock.o score.o -o game  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf  -lm -g 


vie.o:vie.c
	gcc vie.c -c  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm  -g

timetest.o:timetest.c
	gcc timetest.c -c  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf  -lm  -g


clock.o:clock.c
	gcc clock.c -c  -lSDL -lSDL_image  -lSDL_ttf -lSDL_mixer -lSDL_ttf  -lm  -g



score.o:score.c
	gcc score.c -c  -lSDL -lSDL_image  -lSDL_ttf -lSDL_mixer -lSDL_ttf  -lm  -g
