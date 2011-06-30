CC = gcc

PROGRAMS = GYM

all: $(PROGRAMS)

GYM: gym-main.c gym-control.c list.c
	$(CC) -Wall -g -o $@ $^

clean:
	rm -rf $(PROGRAMS)
