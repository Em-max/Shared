run : all
	./main
	
all: main

main: main.o file.o prio.o
	gcc -Wall -g -o main main.o file.o
	
file.o: file.c file.h
	gcc -Wall -g -c file.c
	
main.o: main.c file.h prio.h
	gcc -Wall -g -c main.c
	
prio.o: prio.c file.h prio.h
	gcc -Wall -g -c prio.c
	
clean:
	rm -f *.o
	rm -f main
