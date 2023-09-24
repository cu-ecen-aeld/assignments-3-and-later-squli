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

all:
	${CC} ${CFLAGS} ${INCLUDES} -o writer ${OBJS} ${LIBS}
writer:
	${CC} ${CFLAGS} ${INCLUDES} -o writer ${OBJS} ${LIBS}

clean:
	-rm -f *.o core *.core writer

.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
