CC = gcc
CFLAGS=-g

all: jsonparser.o list.o myhashmap.o listiterator.o
	$(CC) $(CFLAGS) jsonparser.o list.o myhashmap.o listiterator.o  -static -o test.exe
main: jsonparser.c
	$(CC) $(CFLAGS) -c jsonparser.c
list: list.c
	$(CC) $(CFLAGS) -c list.c
map: myhashmap.c
	$(CC) $(CFLAGS) -c myhashmap.c
listiterator: listiterator.c
	$(CC) $(CFLAGS) -c listiterator.c
