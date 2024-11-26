/***********************************************************************
 * Module:  lambdatemplate.cpp
 * Author:  Maycol Celi
 * Date: 19/11/2024
 * Purpose: Suma de matrices con template y lambda
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/
#include <iostream>
#include <ctime>

using namespace std;

// Plantilla de la función que toma una lambda como argumento
template <typename T, int MAX, typename Lambda>
void procesarMatriz(T mat1[MAX][MAX], T mat2[MAX][MAX], Lambda lambda) {
    cout << "Suma de todos los elementos: " << lambda(mat1, mat2) << endl;
}

int main() {
    const int MAX = 3;  // Puedes cambiar el tamaño de la matriz aquí
    int mat1[MAX][MAX], mat2[MAX][MAX];
    srand(time(NULL));

    // Llenado de las matrices con valores aleatorios
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            mat1[i][j] = rand() % 100;
            mat2[i][j] = rand() % 100;
        }
    }

    // Impresión de la primera matriz
    cout << "Matriz 1:" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << mat1[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Impresión de la segunda matriz
    cout << "Matriz 2:" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << mat2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Definición de la lambda para sumar las matrices
    auto sumaMatrices = [](int mat1[MAX][MAX], int mat2[MAX][MAX]) -> int {
        int suma = 0;
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                suma += mat1[i][j] + mat2[i][j];
            }
        }
        return suma;
    };

    // Llamada a la función de plantilla usando la lambda
    procesarMatriz(mat1, mat2, sumaMatrices);

    return 0;
}
