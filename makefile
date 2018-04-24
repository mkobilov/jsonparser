CC = gcc
CFLAGS=-g

all: calc.o  calcf.o jsonparserf.o list.o myhashmap.o listiterator.o
	$(CC) $(CFLAGS) calc.o calcf.o jsonparserf.o list.o myhashmap.o listiterator.o  -static -o test.exe

main: calc.c
	$(CC) $(CFLAGS) -c calc.c
calcfunctions:calcf.c
	$(CC) $(CFLAGS) -c calcf.c
jsonparser: jsonparserf.c
	$(CC) $(CFLAGS) -c jsonparserf.c
list: list.c
	$(CC) $(CFLAGS) -c list.c
map: myhashmap.c
	$(CC) $(CFLAGS) -c myhashmap.c
listiterator: listiterator.c
	$(CC) $(CFLAGS) -c listiterator.c
