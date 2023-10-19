# Define required macros here
SHELL = /bin/sh

OBJS =  writer.c
CFLAG = -Wall -g
CC=$(CROSS_COMPILE)gcc
INCLUDE =
LIBS = -lm 

CC = gcc
CFLAGS = -Wall

all: aesdsocket

aesdsocket: aesdsocket.c
	$(CC) $(CFLAGS) -o aesdsocket aesdsocket.c -lpthread

clean:
	rm -f aesdsocket
