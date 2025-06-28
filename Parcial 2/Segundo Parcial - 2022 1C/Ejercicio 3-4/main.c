#include <stdio.h>
#include <stdlib.h>

typedef struct NODO_TAG // Define a structure for a node in a linked list
{
    double value;
    struct NODO_TAG *pNext; // Pointer to the next node
}nodo_t;

nodo_t *listAddLast(nodo_t *list, double nVal);

int main(void)
{
    return 0;
}

nodo_t *listAddLast(nodo_t *list, double nVal)
{
    // Agrego en el heap el nuevo nodo
    nodo_t *pNodo = (nodo_t *)malloc(sizeof(nodo_t));
    if(pNodo ==  NULL)
    {
        return NULL;        // Si no se pudo crear devuelvo NULL
    }
    
    pNodo->value = nVal;    // Guardo el valor del nuevo nodo
    pNodo->pNext = NULL;    // Apunto a Null ya que es es el ultimo nodo guardado

    if(list == NULL)
    {
        list = pNodo;       // Si la lista esta vacia la creo
        return pNodo;       // Como el primer nodo es el que cree devuelvo eso
    }

    nodo_t *pLast = list;   // Guardo el origen de la lista

    while(pLast->pNext != NULL)
    {
        pLast = pLast->pNext;   // Avanzo de nodo
    }

    pLast->pNext = pNodo;       // Guardo la direccion a donde apunta el ultimo nodo

    return list;                // Devuelvo a donde apunta el primer nodo
}
