#include <stdio.h>
#include <stdlib.h>

int comparar(const void *p1, const void *p2);

int main(int argc, char *argv[])
{
    int i;
    for(i = 1; i < argc; i++)
    {
        printf("%s ", argv[i]);
    }
    qsort(argv + 1, argc - 1, sizeof(char *),comparar);
    
    printf("\n\nLista reordenada:\n");

    for(i = 1; i < argc; i++)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");
    return 0;
}

int comparar(const void *p1, const void *p2)
{
    // casteo a un const char para poder ver la longuitud de los string sin modificarlo
    char *p1_aux = *(char **)p1;
    char *p2_aux = *(char **)p2; 

    unsigned int counterP1, counterP2;

    // Me fijo el largo de cada string
    for(counterP1 = 0; p1_aux[counterP1] != '\0'; counterP1++);
    for(counterP2 = 0; p2_aux[counterP2] != '\0'; counterP2++);
    
    // Si es de mismo largo devuelvo 0
    if(counterP1 == counterP2)
    {
        return 0;
    }

    // Si es mas largo el primer string devuelvo 1 sino -1
    return (counterP1 > counterP2)? 1: -1;
}