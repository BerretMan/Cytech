fonction.o: fonction.c fonction.h
	gcc -c -Wall fonction.c -o fonction.o
trisLent.o: trisLent.c trisLent.h
	gcc -c -Wall trisLent.c -o trisLent.o
trisRapide.o: trisRapide.c trisRapide.h
	gcc -c -Wall trisRapide.c -o trisRapide.o	
main.o: main.c fonction.h trisLent.h trisRapide.h
	gcc -c main.c  -o main.o
exe: fonction.o trisLent.o main.o
	gcc trisLent.o trisRapide.o fonction.o main.o -o exe
clean:
    rm *.o 