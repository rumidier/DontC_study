CC = gcc

PROGRMAS = name-card

all: $(PROGRMAS)

name-card: card-main.c file_control.c nc_control.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRMAS)
