#include <stdio.h>

int cantUnique(char *str);

int main()
{
    char *str[] = {"Hola", "Hacha", "abracadabra pata de cabra", ""};
    for(int i = 0; i < 4; i++)
    {
        printf("Para %s devuelve %d\n", str[i], cantUnique(str[i]));
    }
    return 0;
}


/*
 * int cantUnique(char * str)
 * ---------------------------
 * @brief: Se le ingresa un string cualquiera y devuelve la cantidad de 
 * caracteres sin repetir hay.
 * 
 * @param: String a contar las letras
 * 
 * @return: Cantidad de letras unicas.
 */
int cantUnique(char *str)
{
    int i, j;
    int cant;
    for(i = 0, cant = 0; str[i] != '\0'; i++)
    {
        for(j = 0; j <= i; j++)
        {
            if(str[j] == str[i] && j != i)
            {
                break; // Aparecio antes
            }
            if(j == i)
            {
                cant++; // Primera vez que aparece
            }
        }
    }
    return cant;
}