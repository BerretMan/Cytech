exe : main.o arbre.o abr.o
	gcc -Wall -g main.o arbre.o abr.o -o exe
arbre.o : arbre.c arbre.h
	gcc -c -Wall -g arbre.c -o arbre.o
abr.o: abr.c abr.h
	gcc -c -Wall -g abr.c -o abr.o
main.o : main.c arbre.h abr.h
	gcc -c -Wall -g main.c -o main.o
clean :
	rm -f *.o
	rm -f exe
	clear