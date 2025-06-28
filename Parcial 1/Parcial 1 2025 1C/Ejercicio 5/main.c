#include <stdio.h>

#define BITCHECK(x, n) (((x) >> (n)) & 1)

int main(void)
{
    printf("E8 en el bit 3 devuelve %d\n", BITCHECK(0xE8, 3));
    printf("E8 en el bit 4 devuelve %d\n", BITCHECK(0xE8, 4));
    return 0;
}