CC = gcc

PROGRAMS = inch_change_cm byte_ch_byte c_to_f time_to_sec

all: $(PROGRAMS)

inch_change_cm: inch_change_cm.c
	$(CC) -Wall -o $@ $^

byte_ch_byte: byte_ch_byte.c
	$(CC) -Wall -o $@ $^

c_to_f: c_to_f.c
	$(CC) -Wall -o $@ $^

time_to_sec: time_to_sec.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
