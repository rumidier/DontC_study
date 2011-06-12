CC = gcc

PROGRAMS = phone

all: $(PROGRAMS)

phone: phone_main.c phone.c list.c
	$(CC) -Wall -g -O0 -o $@ $^

clean:
	rm -rf $(PROGRAMS)
