prog:enigme.o main.o
	gcc enigme.o main.o -lSDL -lSDL_image -lSDL_ttf -o prog

main.o:main.c
	gcc -c -lSDL -lSDL_image -lSDL_ttf main.c

enigme.o:enigme.c
	gcc -c -lSDL -lSDL_image -lSDL_ttf enigme.c
