/*
Autor: Luis Diego Araya Campos

Este programa toma una cadena por la línea de comandos e imprime todas las
permutaciones tomando en cuenta todos sus caracteres, si hay caracteres
repetidos imprimirá permutaciones repetidas. Si se ingresan más o menos
argumentos que una cadena, se imprime un mensaje de error.
*/

#include <stdio.h>
#include <string.h>

void intercambiar_caracteres(char *caracter1, char *caracter2){
    /*
    Esta función toma dos punteros hacia caracteres de una cadena y los
    intercambia.

    Parámetros:
    char *caracter1 : puntero hacia caracter 1 por intercambiar en la cadena
    char *caracter2 : puntero hacia caracter 2 por intercambiar en la cadena

    Devuelve:
    void : no devuelve nada
    */

    // Se define un caracter temporal para guardar uno de los caracteres y no
    // se pierda su valor durante el intercambio
    char caracter_temporal;
    caracter_temporal = *caracter1;
    // Sobreescribo el caracter 2 sobre el caracter 1
    *caracter1 = *caracter2;
    // Defino el caracter 2 como el caracter temporal que contiene el caracter
    // 1 inicial
    *caracter2 = caracter_temporal;
}

void imprimir_permutaciones(char *cadena,
                            int indice_inicial,
                            int indice_final){
    /*
    Esta función toma una cadena (la cual es un puntero), un índice incial y
    uno final, e imprime los caracteres antes del índice inicial con las
    permutaciones de los caracteres que van desde el índice inicial al final
    más los caracteres que van desde el siguientes del índice final al último
    caracter de la cadena.

    Ejemplo:

    cadena = "123456"

    indice_inicial = 2

    indice_final = 4

    Salida:

    123456
    123546
    124356
    124536
    125436
    125346

    Parámetros:
    char *cadena : cadena sobre la cual se quiere hacer permutaciones
    int indice_inicial : índice inicial para hacer las permutaciones
    int indice_final : índice final para hacer las permutaciones

    Devuelve:
    void : no devuelve nada
    */

    // Al nivel de algoritmo esta función es recursiva ya que se llama a ella
    // misma. Lo que hace es variar el caracter inicial y hacer permutaciones
    // con los caracteres restantes hasta el caracter final, asociados a los
    // índices inicial y final. Donde las permutaciones de los caracteres
    // restantes es variar el primer caracter y hacer permutaciones con los
    // restantes, de ahí la recursividad.

    // Se define un entero para usar en un for
    int n;

    if (indice_inicial == indice_final){
        // Una vez que el índice inicial es igual al final, las permutaciones
        // de un caracter es el mismo caracter, entonces se imprime la cadena
        // resultante de las permutaciones anteriores en sus caracteres
        printf("%s\n", cadena);
    } else {
        for (n = indice_inicial; n <= indice_final; n = n+1){
            // Se intercambia el caracter en el índice inicial por cada uno de
            // los caracteres restantes, desde el índice inicial al final,
            // nótese que al intercambiar el caracter en el índice inicial por
            // el caracter en el índice inicial, no se realiza ningún cambio
            intercambiar_caracteres(cadena + indice_inicial, cadena + n);

            // Se ingresa nuevamente a la función para imprimir permutaciones,
            // pero aumentando el índice inicial en uno para que se realicen
            // las permutaciones con los caracteres restantes, desde el nuevo
            // índice inicial al final
            imprimir_permutaciones(cadena, indice_inicial + 1, indice_final);

            // Se intercambian los caracteres que se intercambiaron hace dos
            // líneas de código, para que al ingresar de nuevo al for la cadena
            // esté en el estado original y se pueda seguir realizando los
            // intercambios en los caracteres de forma ordenada
            intercambiar_caracteres(cadena + indice_inicial, cadena + n);
        }
    }
}

int main(int argc, char *argv[]) {

    // Se inicializan dos booleanos como falso
    _Bool muchos = 0;
    _Bool pocos = 0;

    if (argc > 2){
        // Si hay más de dos argumentos, tomando en cuenta el primero que es
        // el nombre del ejecutable, se presenta un mensaje de error
        muchos = 1;
        printf("ERROR: Ingresó muchos argumentos, debe ser uno\n");
    } else if (argc < 2) {
      // Si hay menos de dos argumentos, tomando en cuenta el primero que es
      // el nombre del ejecutable, se presenta un mensaje de error
        pocos = 1;
        printf("ERROR: Ingresó pocos argumentos, debe ser uno\n");
    }

    if (!muchos && !pocos){
        // Si la cantidad de argumentos es correcta se guarda la cadena de
        // caracteres, ingresada como argumento por la línea de comandos, el
        // cual es un puntero, en otro puntero llamado cadena.
        char *cadena = argv[1];
        // Se define el índice máximo para recorrer la cadena como el largo de
        // la cadena menos 1 ya que los índices en C empiezan en cero.
        int indice_max = strlen(cadena) - 1;
        // Se introduce la cadena, el índice inicial que es 1 y el índice
        // máximo calculado antes. Para que se impriman las permutaciones de
        // todos los caracteres de la cadena.
        imprimir_permutaciones(cadena, 0, indice_max);
    }

    return 0;
}
