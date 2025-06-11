GC := gcc
CFLAGS := -Wall

OBJS := main.o display.o
# Target to build the executable

cajero: ${OBJS}
	${GC} ${CFLAGS} -o cajero ${OBJS}

main.o: main.c mensajes.h display.h
	${GC} ${CFLAGS} -c main.c

display.o: display.c display.h
	${GC} ${CFLAGS} -c display.c

clear:
	rm *.o 
	rm cajero

