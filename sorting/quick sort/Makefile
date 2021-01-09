# -* Makefile *-

all: main.o
	gcc main.o -o mainApp

main.o: main.c
	gcc -c main.c

clean:
	rm *.o mainApp

leaks:
	valgrind --leak-check=yes ./mainApp
