#include <stdlib.h>
#include <stdio.h>

void flipArr(double arr[], int n);

int main(void)
{
    double arr[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
    flipArr(arr, n);
    printf("Flipped array:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
    return 0;
}

/*
 * Escribir de manera recursiva una función que invierta la posición de los elementos 
 * de un arreglo de double de n elementos, para todo n>0.  
 * El prototipo debe ser void flipArr (double arr[], int n). 
*/
void flipArr(double arr[], int n)
{
    if (n <= 0 || arr == NULL) {
        printf("Invalid input: negative size or null array\n");
        return; // Invalid input: negative size or null array
    }
    if (n == 1) {
        return; // Base case: single element, nothing to flip
    }
    // Swap the first and last elements
    double temp = arr[0];
    arr[0] = arr[n - 1];
    arr[n - 1] = temp;
    // Recursively call flipArr on the subarray excluding the first and last elements
    flipArr(arr + 1, n - 2);
}