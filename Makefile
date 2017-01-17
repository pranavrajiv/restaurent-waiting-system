restaurent:	2.o 3.o 4.o
			gcc -o restaurent 2.o 3.o 4.o

2.o:		2.c 1.h
			gcc -c 2.c

3.o:		3.c 1.h
			gcc -c 3.c

4.o:		4.c 1.h
			gcc -c 4.c
