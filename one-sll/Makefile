# -* Makefile *-

GCC=gcc

all: mainApp

mainApp: main.o sll.o
	$(GCC) main.o sll.o -o mainApp
	
main.o: main.c
	$(GCC) -c main.c
	
sll.o: sll.c sll.h
	$(GCC) -c sll.c
	
clean:
	rm *.o mainApp
