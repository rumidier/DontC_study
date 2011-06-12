CC = gcc

PROGRAMS = list csv

all: $(PROGRAMS)

list: list_main.c list_func.c
	$(CC) -Wall -g -o $@ $^

csv: csv-parser.c
	$(CC) -Wall -g -o $@ $^

clean:
	rm -rf $(PROGRAMS)
