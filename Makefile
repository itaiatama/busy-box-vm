CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
LIBS =
SRC = $(wildcard src/*.c)
OUT = bbox

build: $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC) $(LIBS)
