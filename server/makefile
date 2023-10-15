# Define required macros here
SHELL = /bin/sh

OBJS =  writer.c
CFLAG = -Wall -g
ifeq ($(CROSS_COMPILE),aarch64-none-linux-gnu-)
$(info "cross")
CC = aarch64-none-linux-gnu-gcc
else
CC = gcc
endif
INCLUDE =
LIBS = -lm 

CC = gcc
CFLAGS = -Wall

all: aesdsocket

aesdsocket: aesdsocket.c
	$(CC) $(CFLAGS) -o aesdsocket aesdsocket.c -lpthread

clean:
	rm -f aesdsocket
