prog: main.o display.o
	gcc -o prog -Wall main.o display.o

main.o: main.c display.h mensajes.h
	gcc main.c -c -Wall

display.o: display.c display.h
	gcc display.c -c -Wall

clean:
	rm -f *.o prog

# Si se modifija mensajes.h las reglas que se ven afectadas son:
# main.o y el archivo ejecutable prog

