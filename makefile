CC = gcc
CFLAGS=-g

all: jsonparser.o list.o hash_map.o improved_list_iterator.o
	$(CC) $(CFLAGS) jsonparser.o list.o hash_map.o improved_list_iterator.o  -static -o test.exe
main: jsonparser.c
	$(CC) $(CFLAGS) -c jsonparser.c
list: list.c
	$(CC) $(CFLAGS) -c list.c
map: hash_map.c
	$(CC) $(CFLAGS) -c hash_map.c
improved_list_iterator:
	$(CC) $(CFLAGS) -c improved_list_iterator.c
