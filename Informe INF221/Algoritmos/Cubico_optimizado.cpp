#include <iostream>
#include <vector>

using namespace std;

/****/
// Nombre de función: transpose
// Descripción: Trasponer una matriz dada, intercambiando filas por columnas.
// Tipo de función: vector<vector<int>>
// Input: Matriz original de dimensiones m x n
// Retorno: Matriz transpuesta de dimensiones n x m
/****/
vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> transposed(cols, vector<int>(rows));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

/****/
// Nombre de función: mulOp
// Descripción: Realiza la multiplicación de dos matrices optimizada usando la transposición de la segunda matriz.
// Tipo de función: vector<vector<int>>
// Input: Dos matrices, mat1 de dimensiones R1 x C1 y mat2 de dimensiones R2 x C2
// Retorno: Matriz resultante de la multiplicación de dimensiones R1 x C2
/****/
vector<vector<int>> mulOp(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int R1 = mat1.size();           // Número de filas en la primera matriz
    int C1 = mat1[0].size();        // Número de columnas en la primera matriz
    int R2 = mat2.size();           // Número de filas en la segunda matriz
    int C2 = mat2[0].size();        // Número de columnas en la segunda matriz

    // Verificación para asegurar que las matrices pueden ser multiplicadas
    if (C1 != R2) {
        cout << "Las matrices no pueden ser multiplicadas debido a sus dimensiones.\n";
        return vector<vector<int>>();  // Retorna una matriz vacía si no es posible la multiplicación
    }

    // Trasponer la segunda matriz
    vector<vector<int>> mat2T = transpose(mat2);

    // Crear la matriz de resultados con las dimensiones correctas
    vector<vector<int>> rslt(R1, vector<int>(C2, 0));

    // Multiplicación de matrices optimizada
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            for (int k = 0; k < C1; k++) {
                rslt[i][j] += mat1[i][k] * mat2T[j][k];
            }
        }
    }

    // Retornar la matriz resultante
    return rslt;
}