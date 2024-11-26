/***********************************************************************
 * Module:  lambda.cpp
 * Author:  Maycol Celi
 * Date: 19/11/2024
 * Purpose: Lambda como argumento para una función (suma de matrices)
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/
#include <iostream>
#include <ctime>
#define MAX 3

using namespace std;

// Función que toma una lambda como argumento
void procesarMatriz(int mat1[MAX][MAX], int mat2[MAX][MAX], auto lambda) {
    // Mostrar las matrices antes de sumar
    cout << "Matriz 1:" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << mat1[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nMatriz 2:" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << mat2[i][j] << "\t";
        }
        cout << endl;
    }

    // Mostrar el resultado de la suma
    cout << "\nSuma de todos los elementos: " << lambda(mat1, mat2) << endl;
}

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX];
    srand(time(NULL));

    // Llenado de las matrices con valores aleatorios
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            mat1[i][j] = rand() % 100;
            mat2[i][j] = rand() % 100;
        }
    }

    // Definición de la lambda para sumar las matrices
    auto sumaMatrices = [](int mat1[MAX][MAX], int mat2[MAX][MAX]) {
        int suma = 0;
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                suma += mat1[i][j] + mat2[i][j];
            }
        }
        return suma;
    };

    // Llamada a la función usando la lambda
    procesarMatriz(mat1, mat2, sumaMatrices);

    return 0;
}
