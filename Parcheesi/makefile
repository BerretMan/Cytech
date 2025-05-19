exe : main.o fonctions.o
	gcc -Wall -g main.o fonctions.o -o exe
fonctions.o : fonctions.c fonctions.h
	gcc -c -Wall -g fonctions.c -o fonctions.o
main.o : main.c fonctions.h 
	gcc -c -Wall -g main.c -o main.o
clean :
	rm -f *.o
	rm -f exe
	clear