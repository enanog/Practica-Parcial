#include <stdio.h>

int main(void)
{
    int mat[3][2] = {{1,2},{3,4},{5,6}};
    char *ptr;

    ptr = (char *)mat + 11;  //utilizando mat, hacer que ptr apunte al ultimo byte de mat
    *(int *)(ptr - 11) = -4;  // utilizando ptr, se le asigna -4 al primer elemento de mat

    printf("%p\n", mat+1);      // imprime -> 2004?
    printf("%p\n", mat[2]-1);   // imprime -> 2006?
    printf("%p\n", &mat+1);     // imprime -> 200C?
    printf("%p\n", *mat+1);     // imprime -> 2002?
    return 0;
}