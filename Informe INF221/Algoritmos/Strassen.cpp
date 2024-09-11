#include "Strassen.h"
#include <vector>

using namespace std;

/****/
// Nombre de función: add_matrix
// Descripción: Suma dos matrices de forma componente a componente, con un multiplicador opcional para la segunda matriz.
// Tipo de función: vector<vector<int>>
// Input: matrix_A y matrix_B son las matrices a sumar, split_index es el tamaño de las submatrices, multiplier es el factor de multiplicación para matrix_B (por defecto 1).
// Retorno: Matriz resultante de la suma
/****/
vector<vector<int>> add_matrix(const vector<vector<int>>& matrix_A, const vector<vector<int>>& matrix_B, int split_index, int multiplier = 1) {
    vector<vector<int>> result(matrix_A.size(), vector<int>(matrix_A[0].size(), 0));
    for (int i = 0; i < split_index; i++) {
        for (int j = 0; j < split_index; j++) {
            result[i][j] = matrix_A[i][j] + multiplier * matrix_B[i][j];
        }
    }
    return result;
}

/****/
// Nombre de función: multiply_matrix
// Descripción: Multiplica dos matrices utilizando el algoritmo de Strassen para submatrices cuando sea posible.
// Tipo de función: vector<vector<int>>
// Input: matrix_A y matrix_B son las matrices a multiplicar.
// Retorno: Matriz resultante de la multiplicación
/****/
vector<vector<int>> multiply_matrix(const vector<vector<int>>& matrix_A, const vector<vector<int>>& matrix_B) {
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    int row_2 = matrix_B.size();

    if (col_1 != row_2) {
        return {}; // Error: incompatible matrices
    }

    vector<int> row_vector(col_2, 0);
    vector<vector<int>> result_matrix(row_1, row_vector);

    if (col_1 == 1) {
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
    } else {
        int split_index = col_1 / 2;

        vector<vector<int>> a00(split_index, vector<int>(split_index));
        vector<vector<int>> a01(split_index, vector<int>(split_index));
        vector<vector<int>> a10(split_index, vector<int>(split_index));
        vector<vector<int>> a11(split_index, vector<int>(split_index));
        vector<vector<int>> b00(split_index, vector<int>(split_index));
        vector<vector<int>> b01(split_index, vector<int>(split_index));
        vector<vector<int>> b10(split_index, vector<int>(split_index));
        vector<vector<int>> b11(split_index, vector<int>(split_index));

        for (int i = 0; i < split_index; i++) {
            for (int j = 0; j < split_index; j++) {
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + split_index];
                a10[i][j] = matrix_A[split_index + i][j];
                a11[i][j] = matrix_A[i + split_index][j + split_index];
                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + split_index];
                b10[i][j] = matrix_B[split_index + i][j];
                b11[i][j] = matrix_B[i + split_index][j + split_index];
            }
        }

        vector<vector<int>> p = multiply_matrix(a00, add_matrix(b01, b11, split_index, -1));
        vector<vector<int>> q = multiply_matrix(add_matrix(a00, a01, split_index), b11);
        vector<vector<int>> r = multiply_matrix(add_matrix(a10, a11, split_index), b00);
        vector<vector<int>> s = multiply_matrix(a11, add_matrix(b10, b00, split_index, -1));
        vector<vector<int>> t = multiply_matrix(add_matrix(a00, a11, split_index), add_matrix(b00, b11, split_index));
        vector<vector<int>> u = multiply_matrix(add_matrix(a01, a11, split_index, -1), add_matrix(b10, b11, split_index));
        vector<vector<int>> v = multiply_matrix(add_matrix(a00, a10, split_index, -1), add_matrix(b00, b01, split_index));

        vector<vector<int>> result_matrix_00 = add_matrix(add_matrix(add_matrix(t, s, split_index), u, split_index), q, split_index, -1);
        vector<vector<int>> result_matrix_01 = add_matrix(p, q, split_index);
        vector<vector<int>> result_matrix_10 = add_matrix(r, s, split_index);
        vector<vector<int>> result_matrix_11 = add_matrix(add_matrix(add_matrix(t, p, split_index), r, split_index, -1), v, split_index, -1);

        for (int i = 0; i < split_index; i++) {
            for (int j = 0; j < split_index; j++) {
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j + split_index] = result_matrix_01[i][j];
                result_matrix[split_index + i][j] = result_matrix_10[i][j];
                result_matrix[i + split_index][j + split_index] = result_matrix_11[i][j];
            }
        }
    }
    return result_matrix;
}