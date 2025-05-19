exe: main.o fonction.o
	gcc -Wall fonction.o main.o -o exe
fonction.o: fonction.c fonction.h
	gcc -c fonction.c -o fonction.o -Wall
main.o: main.c fonction.h
	gcc -c main.c -o main.o -Wall
clean :
	rm -f *.o
	rm -f exe
	clear




