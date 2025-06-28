#include <stdio.h>
#include <stdlib.h>

#define LEN 1

typedef struct {
    double *vec;
    unsigned int len;
} vecgen_t;

int removeElement(vecgen_t *vec, unsigned int elem);
int compLargo(const void *vec1, const void *vec2);

void printVecgenList(vecgen_t *list, size_t n) {
        for (size_t i = 0; i < n; i++) {
            printf("Vector %zu de longitud %u: {", i, list[i].len);
            for (unsigned int j = 0; j < list[i].len; j++) {
                printf(" %.3lf ", list[i].vec[j]);
            }
            printf("}\n");
        }
    }

int main(void)
{
    vecgen_t vector = {(double *)malloc(LEN*sizeof(double)), LEN};
    printf("Vector de longuitud %d: {", vector.len);
    for(int i = 0; i < vector.len; i++)
    {
        vector.vec[i] = i+1;
        printf(" %.3lf ", vector.vec[i]);
    }
    printf("}\n");

    if(!removeElement(&vector, 0))
    {
        printf("No se pudo borrar el elemento\n");
        return 1;
    }

    printf("Nuevo vector de longuitud %d: {", vector.len);
    for(int i = 0; i < vector.len; i++)
    {
        printf(" %.3lf ", vector.vec[i]);
    }
    printf("}\n");

    double vec1[] = {0.0 ,1.0 ,2.0 ,3.0};
    double vec2[] = {0.0 ,1.0};
    double vec3[] = {0.0 ,1.0, 2.0};
    double vec4[] = {0.0};

    vecgen_t listVector[] = {{vec1, 4}, {vec2, 2}, {vec3, 3}, {vec1, 1}};

    printVecgenList(listVector, 4);
    printf("Ordenando por largo...\n");
    // Ordenar el vector de estructuras vecgen_t por largo
    // Usando qsort y la funcion compLargo definida abajo
    // La funcion compLargo compara dos estructuras vecgen_t y devuelve
    // 0 si son iguales, 1 si el primero es mas largo y -1 si el segundo es mas largo
    // La funcion qsort recibe el puntero al vector, la cantidad de elementos,
    // el tamaño de cada elemento y la funcion de comparacion

    qsort(listVector, 4, sizeof(vecgen_t), compLargo);

    printVecgenList(listVector, 4);

    return 0;
}

int removeElement(vecgen_t *vec, unsigned int elem)
{
    if(elem >= vec->len)
    {
        return 0;       // Si el elemento es mayor al largo no se puede borrar
    }
    else if(!elem && vec->len == 1)
    {
        printf("Se vacio el vector\n");
        vec->len = 0;       // Si hay un unico elemento en el vector
        vec->vec = NULL;    // El elemento se borra y apunta el vector a NULL
        return 1;
    }

    // Creo un vector auxiliar donde voy a guardar el nuevo vector,
    // El vector va a ser de longuitud uno menos del que tenia
    double *aux = (double *)malloc((vec->len - 1) * sizeof(double)); 
    if(aux == NULL)
    {
        return 0;   // Si se ejecuta mal el malloc devuelve 0
    }
    int i, j;
    for(i = 0, j = 0; i < vec->len; i++)
    {
        // Guardo todos los vectores menos el que voy a borrar
        if(i == elem)
        {
            continue;
        }
        aux[j++] = vec->vec[i];
    }

    // Libero el vector anterior y guardo el nuevo en su posicion
    free(vec->vec);
    vec->vec = aux;
    vec->len--;

    return 1;
}

int compLargo(const void *vec1, const void *vec2)
{
    vecgen_t *v1 = (vecgen_t *)vec1;
    vecgen_t *v2 = (vecgen_t *)vec2;

    if(v1->len == v2->len)
    {
        return 0;
    }

    return (v1->len > v2->len )? 1: -1;
}
