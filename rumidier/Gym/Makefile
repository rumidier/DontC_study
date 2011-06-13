CC = gcc

PROGRAMS = GYM

all: $(PROGRAMS)

GYM: gym-main.c gym-control.c file_control.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
