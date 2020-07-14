CC=gcc --std=c99 -g

all: test_dynarray test_list

test_dynarray: test_dynarray.c test_data.h dynarray.o
	$(CC) test_dynarray.c dynarray.o -o test_dynarray

test_list: test_list.c test_data.h list.o
	$(CC) test_list.c list.o -o test_list

dynarray.o: dynarray.c dynarray.h
	$(CC) -c dynarray.c

list.o: list.c list.h
	$(CC) -c list.c

clean:
	rm -f dynarray.o list.o test_dynarray test_list
