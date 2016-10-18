all: try
try: prac8.o
	cc prac8.o -o try -lncurses
prac8.o: prac8.c
	cc -c prac8.c
clean:
	rm *.o
	
