all: project
project: prac14.o menu8.o globals2.o
	cc prac14.o menu8.o globals2.o -o project -lncurses -lmenu
prac14.o: prac14.c globals2.h menu8.h
	cc -c prac14.c
menu8.o: menu8.c menu8.h
	cc -c menu8.c
globals2.o: globals2.c globals2.h
	cc -c globals2.c
clean:
	rm *.o
	
