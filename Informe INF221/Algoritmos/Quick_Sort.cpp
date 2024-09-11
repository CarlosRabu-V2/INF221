#include <bits/stdc++.h>
using namespace std;

/****/
// Nombre de función: partition
// Descripción: Divide el arreglo en dos subarreglos basados en un pivote. Los elementos menores al pivote se colocan a la izquierda y los mayores a la derecha.
// Tipo de función: int
// Entrada: arr es el arreglo, low es el índice de inicio, high es el índice de fin.
// Retorno: Índice de la posición del pivote después de la partición.
/****/
int partition(vector<int>& arr, int low, int high) {
  
    // Elegir el pivote
    int pivot = arr[high];
  
    // Índice del elemento menor y posición
    // derecha del pivote encontrada hasta ahora
    int i = low - 1;

    // Recorrer arr[low..high] y mover todos los elementos menores
    // al lado izquierdo. Los elementos desde low hasta 
    // i son menores después de cada iteración
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Mover el pivote después de los elementos menores y
    // retornar su posición
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

/****/
// Nombre de función: Quick_Sort
// Descripción: Ordena el arreglo usando el algoritmo de QuickSort, que es un algoritmo de ordenación eficiente basado en partición.
// Tipo de función: void
// Entrada: arr es el arreglo a ordenar, low es el índice inicial, high es el índice final.
// Retorno: No retorna ningún valor.
/****/
void Quick_Sort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi es el índice de partición retornado del pivote
        int pi = partition(arr, low, high);

        // Llamadas recursivas para elementos menores
        // y elementos mayores o iguales
        Quick_Sort(arr, low, pi - 1);
        Quick_Sort(arr, pi + 1, high);
    }
}