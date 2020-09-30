# -* Makefile *-

all: main.o stack.o
	gcc main.o stack.o -o mainApp

main.o: main.c
	gcc -c main.c

stack.o: stack.c
	gcc -c stack.c

clean:
	rm *.o mainApp

leaks:
	valgrind --leak-check=yes ./mainApp
