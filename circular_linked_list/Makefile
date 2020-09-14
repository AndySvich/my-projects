# -* Makefile *-

GCC=gcc

all: main.o cll.o
	$(GCC) main.o cll.o -o mainApp

main.o: main.c
	$(GCC) -c main.c
	
cll.o: cll.c
	$(GCC) -c cll.c

clean: 
	rm *.o mainApp

leaks:
	valgrind --leak-check=yes ./mainApp
