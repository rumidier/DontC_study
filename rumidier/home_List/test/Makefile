CC = gcc

PROGRAMS = test

all: $(PROGRAMS)

test: test.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
