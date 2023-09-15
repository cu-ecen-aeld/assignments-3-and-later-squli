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

writer:
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

clean:
	-rm -f *.o core *.core

.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
