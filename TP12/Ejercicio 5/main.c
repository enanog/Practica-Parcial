#include <stdio.h>

typedef struct 
{
    char tecla;
    int (*action) (void);
}menu_t;

int borrar(void);
int aceptar(void);

int main(void)
{
    menu_t menu_list[] ={
        {'*', borrar},
        {'#', aceptar}
    };

    return 0;
}

