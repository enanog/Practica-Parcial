#include <stdio.h>

void printNum(unsigned int num);

int main(void)
{
    printNum(5500);
    return 0;
}

void printNum(unsigned int num)
{
    if(num < 10)
    {
        putchar(num + '0');     // Caso base
        return;
    }

    printNum(num / 10);         // Divido hasta quedarme con el primer digito 
    putchar((num % 10) + '0');  // Voy imprimiendo digito desde el mas significativo
}
