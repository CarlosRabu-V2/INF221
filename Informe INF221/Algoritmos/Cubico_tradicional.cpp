#include <iostream>
#include <vector>

using namespace std;

/****/
// Nombre de función: mulMat
// Descripción: Multiplica dos matrices clásicamente utilizando un triple bucle para las componentes.
// Tipo de función: vector<vector<int>>
// Input: mat1 y mat2 son las matrices a multiplicar.
// Retorno: Matriz resultante de la multiplicación o una matriz vacía si las dimensiones no son compatibles.
/****/
vector<vector<int>> mulMat(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int R1 = mat1.size();           // Número de filas en la primera matriz
    int C1 = mat1[0].size();        // Número de columnas en la primera matriz
    int R2 = mat2.size();           // Número de filas en la segunda matriz
    int C2 = mat2[0].size();        // Número de columnas en la segunda matriz

    // Verificación para asegurar que las matrices pueden ser multiplicadas
    if (C1 != R2) {
        cout << "Las matrices no pueden ser multiplicadas debido a sus dimensiones.\n";
        return vector<vector<int>>();  // Retorna una matriz vacía si no es posible la multiplicación
    }

    // Crear la matriz de resultados con las dimensiones correctas
    vector<vector<int>> rslt(R1, vector<int>(C2, 0));

    // Multiplicación de matrices
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            for (int k = 0; k < C1; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Retornar la matriz resultante
    return rslt;
}