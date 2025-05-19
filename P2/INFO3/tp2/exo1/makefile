exe : main.o pile.o
	gcc -Wall -g main.o pile.o -o exe
pile.o : pile.c pile.h
	gcc -c -Wall -g pile.c -o pile.o
main.o : main.c pile.h 
	gcc -c -Wall -g main.c -o main.o
clean :
	rm -f *.o
	rm -f exe
	clear
