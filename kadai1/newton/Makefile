CC := gcc
CFLAGS := -Wall -I ./ -lm -g

#build:
#	$(CC) *.o
#	$(CC) Newton

newton: 1.o newton.o

1.o: 1.c newton.h

newton.o: newton.c

clean:
	$(RM) *.o

run:
	./a.out 1
