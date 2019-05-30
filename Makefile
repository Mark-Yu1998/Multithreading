CC=g++
LDFLAGS= -lpthread
CFLAGS= -c -std=c++11

all: staplemax

staplemax: staplemax.o
		$(CC) $(LDFLAGS) staplemax.o -o staplemax

staplemax.o: staplemax.cpp
	$(CC) $(CFLAGS) staplemax.cpp  

clean:
	rm -r *.o
	rm -r staplemax
