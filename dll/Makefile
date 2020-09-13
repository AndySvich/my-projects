# -* Makefile *-

GCC=gcc

all: main.o dll.o
	$(GCC) main.o dll.o -o mainApp

main.o: main.c
	$(GCC) -c main.c
	
dll.o: dll.c
	$(GCC) -c dll.c

clean: 
	rm *.o mainApp

leaks:
	valgrind --leak-check=yes ./mainApp
