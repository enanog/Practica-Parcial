#include <stdio.h>
#include <stdlib.h>

typedef struct NODO_TAG
{
    int data;
    struct NODO_TAG *pNext;
}nodo_t;

int listAdd(nodo_t *first, int newData);

int main(void)
{
    nodo_t *lista = (nodo_t *)malloc(sizeof(nodo_t));
    lista->data = 1;
    lista->pNext = NULL;
    listAdd(lista, 12);
    listAdd(lista, -9);
    listAdd(lista, 711);

    nodo_t *aux = lista;
    printf("HOLA\n");
    while (aux != NULL) {
        printf("%d\t%p\n", aux->data, aux->pNext);
        aux = aux->pNext;
    }
    return 0;
}

int listAdd(nodo_t *first, int newData)
{
    if(first == NULL)
    {
        return 0; // Lista vacia
    }
    nodo_t *newNodo = (nodo_t *)malloc(sizeof(nodo_t));
    if(newNodo == NULL)
    {
        return 0;   // No se pudo crear el nuevo item  
    }
    
    newNodo->data = newData;
    newNodo->pNext = NULL;  // Ulitmo puntero

    // Busco el ultimo nodo de la lista
    nodo_t *aux = first;
    while(aux->pNext != NULL)
    {
        aux = aux->pNext;
    }
    // Actualizo a donde debe apuntar el ultimo nodo de la lista
    aux->pNext = newNodo;
    return 1;
}