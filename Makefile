prog:main.o work.o
	gcc main.o work.o -o prog -lSDL -lSDL_image -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -g
text.o:text.c
	gcc -c work.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
