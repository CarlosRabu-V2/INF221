#include <iostream>
#include <vector>

using namespace std;

/****/
// Nombre de función: merge
// Descripción: Une dos subarreglos de vec. El primer subarreglo es vec[left..mid] y el segundo subarreglo es vec[mid+1..right].
// Tipo de función: void
// Entrada: vec es el arreglo completo, left es el índice de inicio del primer subarreglo, mid es el índice final del primer subarreglo, right es el índice final del segundo subarreglo.
// Retorno: No retorna ningún valor.
/****/
void merge(vector<int>& vec, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crear vectores temporales
    vector<int> leftVec(n1), rightVec(n2);

    // Copiar datos a los vectores temporales
    for (i = 0; i < n1; i++)
        leftVec[i] = vec[left + i];
    for (j = 0; j < n2; j++)
        rightVec[j] = vec[mid + 1 + j];

    // Unir los vectores temporales de nuevo en vec[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de leftVec[], si los hay
    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de rightVec[], si los hay
    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

/****/
// Nombre de función: mergeSort
// Descripción: Ordena el subarreglo de vec en el rango de índices [left..right] usando el algoritmo de merge sort.
// Tipo de función: void
// Entrada: vec es el arreglo a ordenar, left es el índice inicial del subarreglo, right es el índice final del subarreglo.
// Retorno: No retorna ningún valor.
/****/
void mergeSort(vector<int>& vec, int left, int right) {
    if (left < right) {
      
        // Calcular el punto medio
        int mid = left + (right - left) / 2;

        // Ordenar las dos mitades
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        // Unir las mitades ordenadas
        merge(vec, left, mid, right);
    }
}
