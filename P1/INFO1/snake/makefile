fonction.o: fonction.c fonction.h
    gcc -c -Wall fonction.c -o fonction.o
main.o: main.c fonction.h 
    gcc -c -Wall main.c  -o main.o
exe: fonction.o main.o
    gcc fonction.o main.o -o exe
clean:
    rm *.o 


