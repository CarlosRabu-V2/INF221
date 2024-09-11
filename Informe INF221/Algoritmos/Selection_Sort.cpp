#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm> 
#include "Selection_Sort.h"  // Incluir el archivo de cabecera de Selection_Sort

using namespace std;

/****/
// Nombre de función: Selection_Sort
// Descripción: Ordena el arreglo usando el algoritmo de selección, que encuentra el mínimo en cada iteración y lo coloca en la posición correcta.
// Tipo de función: void
// Entrada: array es el arreglo a ordenar, len es la longitud del arreglo.
// Retorno: No retorna ningún valor.
/****/
void Selection_Sort(std::vector<int>& array, int len) {
    for (int i = 0; i < len - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(array[i], array[minIndex]);
    }
}