eya:initialisation.o test01.o
	gcc initialisation.o test01.o -o eya -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
test01.o:test01.c
	gcc -c test01.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
initialisation.o:initialisation.c
	gcc -c initialisation.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
