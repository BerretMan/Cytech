exe : main.o liste.o
	gcc -Wall -g main.o liste.o -o exe
liste.o : liste.c liste.h
	gcc -c -Wall -g liste.c -o liste.o
main.o : main.c liste.h 
	gcc -c -Wall -g main.c -o main.o
clean :
	rm -f *.o
	rm -f exe
	clear