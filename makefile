CC = gcc
CFLAGS=-g

all: fmain.o jsonparserf.o list.o myhashmap.o listiterator.o
	$(CC) $(CFLAGS) fmain.o jsonparserf.o list.o myhashmap.o listiterator.o  -static -o test.exe

main:
	$(CC) $(CFLAGS) -c fmain.c
jsonparser: jsonparserf.c
	$(CC) $(CFLAGS) -c jsonparserf.c
list: list.c
	$(CC) $(CFLAGS) -c list.c
map: myhashmap.c
	$(CC) $(CFLAGS) -c myhashmap.c
listiterator: listiterator.c
	$(CC) $(CFLAGS) -c listiterator.c
