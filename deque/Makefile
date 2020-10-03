# -* Makefile *-

all: main.o dll.o deque.o
	gcc main.o dll.o deque.o -o mainApp

main.o: main.c
	gcc -c main.c

deque.o: deque.c
	gcc -c deque.c

dll.o: dll.c
	gcc -c dll.c

clean:
	rm *.o mainApp

leaks:
	valgrind --leak-check=yes ./mainApp
