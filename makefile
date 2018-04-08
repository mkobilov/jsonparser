CC = g++
CFLAGS=-g

all: jsonparser.o list.o hash_map.o 
	g++ $(CFLAGS) jsonparser.o list.o hash_map.o  -static -o test.exe
main: jsonparser.c
	g++ $(CFLAGS) -c jsonparser.c
list: list.c
	g++ $(CFLAGS) -c list.c
map: hash_map.c
	g++ $(CFLAGS) -c hash_map.c

