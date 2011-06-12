CC = gcc

PROGRAMS = simple_linked malloc realloc calloc

all : $(PROGRAMS)

simple_linked: simple_linked.c
	$(CC) -Wall -o $@ $^

malloc: malloc.c
	$(CC) -Wall -o $@ $^

realloc: realloc.c
	$(CC) -Wall -o $@ $^

calloc: calloc.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
