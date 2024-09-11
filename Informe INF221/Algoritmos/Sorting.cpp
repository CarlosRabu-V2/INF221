#include <iostream>
#include <vector>
#include <algorithm> // Para std::sort

using namespace std;

/****/
// Nombre de función: Sorting
// Descripción: Llama a la función sort de la librería de C++
// Tipo de función: Void
// Input: Vector que es el arreglo a ordenar de largo n
// Retorno: no
/****/
void Sorting(vector<int>& array){
    std::sort(array.begin(), array.end()); // Se llama a la función con el respectivo arreglo
}