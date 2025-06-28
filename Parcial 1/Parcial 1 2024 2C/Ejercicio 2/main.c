#include <stdio.h>
// No esta creada la variable i
// No se inicializa veces
// El largo se inicializa mal ya que sizeof(str-1) 
// da una direccion de memoria
// Se puede hacer que el for reccorra hasta encontrar el terminador '\0'
// Se sobrescribe el string en vez de ver si es igual al caracter
 int cantRepe(char str[], char c)
 {
    int veces, i;
    for(i = 0, veces  = 0; str[i] != '\0'; i++)
    {
        veces += (str[i] == c);
    }
    return veces;
 }