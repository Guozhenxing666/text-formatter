CC := gcc
CFLAGS := -g -Wextra -Wall -O0


main: main.c formatter.c
	$(CC) $(CFLAGS) main.c formatter.c -o main
clear:
	rm -rf ./main