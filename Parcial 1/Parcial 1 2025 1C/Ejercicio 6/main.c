#include <stdio.h>

#define MOD(x) (((x) < 0 )? -(x):(x))

int mcd(int n1, int n2);

int main(void)
{
    int listMcd [5][2] = {{60, -48}, {0, 5}, {3,5}, {-16, -48}, {0, 0}};
    for(int i = 0; i < 5; i++)
    {
        printf("El mcd de %d y %d es %d\n", listMcd[i][0], listMcd[i][1], 
            mcd(listMcd[i][0], listMcd[i][1]));
    }

    return 0;
}

/*
 * int mcd(int n1, int n2)
 * -----------------------
 * @brief: Caclucla y edvuelve el maximmo comun denominador entre dos numeros enteros
 * @param: n1, n2 enteros a ser comparados
 * @return: devuelve el maximo comun denominador o 0 en caso de haber un error
 */
int mcd(int n1, int n2)
{
    if(!n1 || !n2)
    {
        return (n1 == 0)? n2: n1;
    }
    int i;
    for(i = (MOD(n1) < MOD(n2))? MOD(n1): MOD(n2); 1 < i; i--)
    {
        if(MOD(n1) % i == 0 && MOD(n2) % i == 0)
        {
            return i;
        }
    }
    return 1;
}