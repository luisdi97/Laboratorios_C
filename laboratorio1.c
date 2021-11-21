#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Autor: Luis Diego Araya Campos

Este programa toma dos argumentos correspondientes a números enteros y devuelve
el máximo común divisor. Si la cantidad de argumentos es incorrecta da mensajes
de error. Si algunos de los valores o ambos son negativos también da un mensaje
de error.
*/

int MCD(int x, int y) {
    /*
    Esta función calcula el máximo común divisor de dos números enteros de
    forma recursiva.

    Parámetros:
    int x : valor 1
    int y : valor 2

    Devuelve:
    int : máximo común divisor de ambos valores
    */

    // x debe ser mayor que y, en caso contrario, el programa entra al
    // siguiente if donde los valores cambian de lugar
    if (y > x){
        int temp = x;
        x = y;
        y = temp;
    }

    // A continuación se muestra el algoritmo recursivo para calcular el máximo
    // común divisor
    if (y == 0) {
        return x;
    } else if (x >= y) {
        return MCD(y, x % y);
    }
}

int main(int argc, char *argv[]) {

    // Se inicializan dos booleanos como falso
    _Bool muchos = 0;
    _Bool pocos = 0;

    if (argc > 3){
        // Si hay más de tres argumentos, tomando en cuenta el primero que es
        // el nombre del ejecutable, se presenta un mensaje de error
        muchos = 1;
        printf("ERROR: Ingresó muchos argumentos, deben ser dos\n");
    } else if (argc < 3) {
      // Si hay menos de tres argumentos, tomando en cuenta el primero que es
      // el nombre del ejecutable, se presenta un mensaje de error
        pocos = 1;
        printf("ERROR: Ingresó pocos argumentos, deben ser dos\n");
    }

    if (!muchos && !pocos){
        // Si la cantidad de argumentos es correcta se convierten los valores
        // que ingresan como una cadena de caracteres a enteros
        int x = atoi(argv[1]);
        int y = atoi(argv[2]);

        if (x<0 || y<0){
            // Si alguno de los valores o ambos son negativos, se presenta un
            // mensaje de error
            printf("ERROR: Ambos valores deben ser positivos\n");
        } else{
            // Si los valores no son negativos se imprime el máximo común
            // divisor
            printf("MCD: %d\n", MCD(x, y));
        }
    }

    return 0;
}
