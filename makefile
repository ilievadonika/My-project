CC = gcc
CFILE = CODE.c functions.c
TARGET = main

all:
	$(CC) $(CFILE) -o $(TARGET)

clean:
	del main.exe