#include <stdio.h>

void gswap(void *p1, void *p2, unsigned int size);

int main(void)
{
    char a = 'A';
    char b = 'B';
    printf("a: %c\tb: %c\n", a, b);
    gswap(&a, &b, sizeof(char));
    printf("a: %c\tb: %c\n", a, b);
    return 0;
}

void gswap(void *p1, void *p2, unsigned int size)
{
    if(!p1 || !p2 || size <= 0)
    {
        return;
    }

    char *p1_aux =  (char *)p1;
    char *p2_aux =  (char *)p2;
    char aux = *p1_aux;

    *(p1_aux++) = *p2_aux;
    *(p2_aux++) = aux;

    gswap(p1_aux, p2_aux, size - 1);   
}