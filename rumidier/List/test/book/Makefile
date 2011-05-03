CC = gcc

PROGRAMS = test

all: $(PROGRAMS)

test: test.c list.c book.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
