#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm> 
#include <chrono> // Para medir el tiempo de ejecución
#include "Selection_Sort.h"  // Incluir el archivo de cabecera de Selection_Sort
#include "Merge_Sort.h"  // Incluir el archivo de cabecera de Merge_Sort
#include "Quick_Sort.h"  // Incluir el archivo de cabecera de Quick_Sort
#include "Sorting.h"  // Incluir el archivo de cabecera de Sorting
#include "Cubico_tradicional.h"  // Incluir el archivo de cabecera de Cubico_tradicional
#include "Cubico_optimizado.h"  // Incluir el archivo de cabecera de Cubico_optimizado
#include "Strassen.h"  // Incluir el archivo de cabecera de Strassen

using namespace std;

// Función para convertir una cadena de texto que representa un arreglo a un vector de enteros
vector<int> ArrayInput(const string &input) {
    vector<int> result;
    // Eliminar los corchetes '[' y ']'
    stringstream ss(input.substr(1, input.length() - 2));
    string temp;
    // Leer los elementos separados por coma y convertirlos a enteros
    while (getline(ss, temp, ',')) {
        result.push_back(stoi(temp));
    }
    return result;
}

// Función para ingresar una matriz de tamaño rows x cols desde la entrada estándar
vector<vector<int>> MatrixInput(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Ingresa los elementos de la matriz, fila por fila (separados por espacios):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

int main() {
    while (true) {
        int option;
        // Menú de opciones para seleccionar el algoritmo a ejecutar
        cout << "Selecciona el algoritmo que deseas ejecutar:\n";
        cout << "1. Selection_Sort\n";
        cout << "2. Merge_Sort\n";
        cout << "3. Quick_Sort\n";
        cout << "4. Función_Sorting_C++\n";
        cout << "5. Algoritmo_Multiplicacion_Matrices_Tradicional\n";
        cout << "6. Algoritmo_Multiplicacion_Matrices_Optimizado\n";
        cout << "7. Algoritmo_Multiplicacion_Matrices_Strassen\n";
        cout << "8. Salir\n";
        cout << "Opción: ";
        cin >> option;
        cin.ignore(); // Limpiar el buffer de entrada después de leer el número

        if (option == 8) {
            break; // Salir del bucle y terminar el programa
        }

        if (option >= 1 && option <= 4) { // Opciones para algoritmos de ordenación
            string arrayInput;
            cout << "Ingresa el arreglo en formato [1, 2, 3, ..., n]: ";
            getline(cin, arrayInput); // Leer la entrada como una cadena
            vector<int> array = ArrayInput(arrayInput); // Convertir la cadena a un vector de enteros
            int len = array.size();
            auto start = chrono::high_resolution_clock::now(); // Iniciar la medición del tiempo
            switch (option) {
                case 1:
                    Selection_Sort(array, len); // Llamar a la función de ordenación por selección
                    break;
                case 2:
                    mergeSort(array, 0, len-1); // Llamar a la función de Merge Sort
                    break;
                case 3:
                    Quick_Sort(array, 0, len-1); // Llamar a la función de Quick Sort
                    break;
                case 4:
                    Sorting(array); // Llamar a la función de Sorting (general)
                    break;
            }
            auto stop = chrono::high_resolution_clock::now(); // Detener la medición del tiempo
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); // Calcular la duración
            cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << endl;
            cout << "Arreglo ordenado: ";
            for (int num : array) {
                cout << num << " "; // Mostrar el arreglo ordenado
            }
            cout << endl;
        } else if (option > 4) { // Opciones para algoritmos de multiplicación de matrices
            int tam;
            cout << "Ingresa el número de filas y columnas: ";
            cin >> tam;

            vector<vector<int>> matrix;
            vector<vector<int>> matrix1 = MatrixInput(tam, tam); // Ingresar la primera matriz
            vector<vector<int>> matrix2 = MatrixInput(tam, tam); // Ingresar la segunda matriz
            auto start = chrono::high_resolution_clock::now(); // Iniciar la medición del tiempo
            if (option == 5) {
                // Algoritmo tradicional de multiplicación de matrices
                matrix = mulMat(matrix1, matrix2);
            } else if (option == 6) {
                // Algoritmo optimizado de multiplicación de matrices
                matrix = mulOp(matrix1, matrix2);
            } else if (option == 7) {
                // Algoritmo de Strassen para multiplicación de matrices
                matrix = multiply_matrix(matrix1, matrix2);
            }
            auto stop = chrono::high_resolution_clock::now(); // Detener la medición del tiempo
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); // Calcular la duración
            cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << endl;
            cout << "Matriz procesada:\n";
            for (const auto &row : matrix) {
                for (int val : row) {
                    cout << val << " "; // Mostrar los elementos de la matriz procesada
                }
                cout << endl;
            }
        } else {
            cout << "Opción inválida. Intenta de nuevo.\n"; // Mensaje en caso de opción inválida
        }
    }

    return 0;
}