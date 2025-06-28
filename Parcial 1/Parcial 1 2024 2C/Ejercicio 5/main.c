#include <stdio.h>

#define MOD(x) (((x) < 0)? -(x):(x))
#define M 5

int norma(int vec[], int m);
int normaMayor(int *matriz[M], int n);

int main(void)
{
    int v5[M] = {1, -2, 3, -4, 5};
    int v2[M] = {2, 2, 2, 2, 2};
    int v3[M] = {-1, -1, -1, -1, -1};
    int v4[M] = {10, 0, 0, 0, 0};
    int v1[M] = {0, 0, 0, 0, 0};
    int *matriz[M] = {v1, v2, v3, v4, v5};

    int fila = normaMayor(matriz, 5);
    printf("La fila con mayor norma es: %d\n", fila);
    return 0;
}

/*
 * @brief: Determina cual vector tiene mayor norma 1
 *         La norma uno es la suma de los valores abs
 * @param: 
 *        -matriz: Matriz de vectores a comparar
 *        -n: Cant de vectores a comparar
 * @return: Fila con mayor norma
 */
int normaMayor(int *matriz[M], int n)
{
    int mayorNorma;
    int filaMayor;
    int i;

    for(i = 0, filaMayor = 1, mayorNorma = 0; i < n; i++)
    {
        if(mayorNorma <= norma(matriz[i], M))   // Si el vector actual tiene mayor norma
        {
            mayorNorma = norma(matriz[i], M);   // Actualizo el valor mas alto
            filaMayor = i+1;                    // Guardo la fla
        }
    }
    return filaMayor;
}

int norma(int vec[], int m)
{
    int i, result;
    for(i = 0, result = 0; i < m; i++)
    {
        result += MOD(vec[i]);
    }
    return result;
}