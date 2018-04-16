CC = gcc
CFLAGS=-g

all: jsonparser.o list.o hash_map.o listiterator.o
	$(CC) $(CFLAGS) jsonparser.o list.o hash_map.o listiterator.o  -static -o test.exe
main: jsonparser.c
	$(CC) $(CFLAGS) -c jsonparser.c
list: list.c
	$(CC) $(CFLAGS) -c list.c
map: hash_map.c
	$(CC) $(CFLAGS) -c hash_map.c
listiterator: listiterator.c
	$(CC) $(CFLAGS) -c listiterator.c
