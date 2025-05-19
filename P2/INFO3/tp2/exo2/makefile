exe : main.o file.o
	gcc -Wall -g main.o file.o -o exe
file.o : file.c file.h
	gcc -c -Wall -g file.c -o file.o
main.o : main.c file.h 
	gcc -c -Wall -g main.c -o main.o
clean :
	rm -f *.o
	rm -f exe
	clear
