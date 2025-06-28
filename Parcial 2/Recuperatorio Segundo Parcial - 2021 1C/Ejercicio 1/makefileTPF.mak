GCC := gcc 
CFLAGS := -Wall

OBJ := main.o frontend.o backend.o

tpf: ${OBJ}
	${GCC} ${CFLAGS} ${OBJ} -o tpf

main.o: main.c backend.h frontend.h
	${GCC} ${CFLAGS} main.c -c

backend.o: backend.c backend.h
	${GCC} ${CFLAGS} backend.c -c

frontend.o: frontend.c frontend.h
	${GCC} ${CFLAGS} frontend.c -c

clear:
	rm -f *.o
	rm tpf