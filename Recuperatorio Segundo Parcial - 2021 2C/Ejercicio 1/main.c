#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define DEAD 0
#define ALIVE 1
uint8_t *worldInit(uint32_t high, uint32_t width);
void printWorld(uint8_t *world, uint32_t high, uint32_t width);

int main(void)
{
    uint8_t *world = worldInit(5,5);

    printWorld(world, 5, 5);

    return 0; 
}

void printWorld(uint8_t *world, uint32_t high, uint32_t width) 
{
    for (uint32_t i = 0; i < high; i++) {
        for (uint32_t j = 0; j < width; j++) {
            printf("%d ", world[i * width + j]);
        }
        printf("\n");
    }
}

uint8_t *worldInit(uint32_t high, uint32_t width)
{
    // Creo el mundo en el heap
    uint8_t *world = (uint8_t *)malloc(high*width*sizeof(uint8_t));
    if(world == NULL)
    {
            return NULL;    // Fallo la creacion del mundo
    }

    // Inicializo el random a partir del tiempo en el que se ejecuto
    srand(time(NULL));
    uint32_t i;
    for(i = 0; i < high*width; i++)
    {
        // Asigno valor si la celula empieza viva o muerta
        world[i] = rand()%2;
    }
    return world;
}