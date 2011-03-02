CC = gcc

PROGRAMS = exam9-01 exam9-02 exam9-03

all: $(PROGRAMS)

exam9-01: exam9-01.c
	$(CC) -Wall -o $@ $^

exam9-02: exam9-02.c
	$(CC) -Wall -o $@ $^

exam9-03: exam9-03.c
	$(CC) -Wall -o $@ -lm $^

clean:
	rm -rf $(PROGRAMS)
