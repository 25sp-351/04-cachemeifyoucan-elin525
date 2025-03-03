CC = gcc
CFLAGS = -Wall -Wextra

all: rod_cut_fifo rod_cut_lru

rod_cut_fifo: main.c rod_cut.c cache_fifo.c
	$(CC) $(CFLAGS) -o rod_cut_fifo main.c rod_cut.c cache_fifo.c

rod_cut_lru: main.c rod_cut.c cache_lru.c
	$(CC) $(CFLAGS) -o rod_cut_lru main.c rod_cut.c cache_lru.c

clean:
	rm -f rod_cut_fifo rod_cut_lru


