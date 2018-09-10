all: run

run: main.o function.o 
	gcc main.o function.o -o run

main.o: main.c
	gcc -c main.c

function.o: function.c
	gcc -c function.c

clean:
	rm *o run
