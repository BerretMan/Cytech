exe : main.o arbre.o
	gcc -Wall -g main.o arbre.o -o exe
arbre.o : arbre.c arbre.h
	gcc -c -Wall -g arbre.c -o arbre.o
main.o : main.c arbre.h 
	gcc -c -Wall -g main.c -o main.o
clean :
	rm -f *.o
	rm -f exe
	clear