CC=gcc
CCFLG=-o
FILE=parse.c main.c
all:
	$(CC) $(FILE) $(CCFLG) main
