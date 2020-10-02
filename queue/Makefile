# -* Makefile *-

all: main.o cll.o queue.o
	gcc main.o cll.o queue.o -o mainApp

main.o: main.c
	gcc -c main.c

queue.o: queue.c
	gcc -c queue.c

cll.o: cll.c
	gcc -c cll.c

clean:
	rm *.o mainApp

leaks:
	valgrind --leak-check=yes ./mainApp
