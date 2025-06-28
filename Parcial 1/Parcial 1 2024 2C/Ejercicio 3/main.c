#include <stdio.h>

unsigned int flipBits(unsigned int num);

int main(void)
{
    unsigned int nums[] = {0x1, 0xFFFFFFFF, 0x1, 0x80000000, 0xF0F0F0F0, 0xAAAAAAAA};
    int n = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < n; ++i) {
        printf("flipBits(0x%08X) = 0x%08X\n", nums[i], flipBits(nums[i]));
    }
    return 0;
}

/*
 * @brief: Recibe el numero y devuelve dicho numero con los bits
 *         espejados. Funciona para cualquier plataforma.
 * @param: Numero entero a ser flipeado.
 * @return: Numero flipeado.
 */
unsigned int flipBits(unsigned int num)
{
    int result, i;
    for(i = 0, result = 0; i < sizeof(int) * 8; i++)
    {
        result = result << 1;
        result |= (num >> i) & 1;
    }
    return result;
}