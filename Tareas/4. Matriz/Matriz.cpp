#include <iostream>
#include "Matriz.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

// Constructor para inicializar la matriz
template <typename T>
Matriz<T>::Matriz() {
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matriz[i][j] = rand() % 1000;
        }
    }
}
// Getter para obtener el valor
template <typename T>
T Matriz<T>::getElemento(int fila, int col) {
    if (fila >= 0 && fila < MAX && col >= 0 && col < MAX) {
        return matriz[fila][col];
    }
    return T(); // Valor por defecto para el tipo T
}

// Setter para establecer el valor
template <typename T>
void Matriz<T>::setElemento(int fila, int col, T valor) {
    if (fila >= 0 && fila < MAX && col >= 0 && col < MAX) {
        matriz[fila][col] = valor;
    }
}
//Imprime Matriz
template <typename T>
void Matriz<T>::imprimirMatriz() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}
template <typename T>
T Matriz<T>::sumaRecursivaMatrices(Matriz<T>& mat1, Matriz<T>& mat2, int f, int c) {
    if (f == 0 && c == 0)
        return mat1.getElemento(f, c) + mat2.getElemento(f, c);
    else {
        if (c > 0)
            return mat1.getElemento(f, c) + mat2.getElemento(f, c) + sumaRecursivaMatrices(mat1, mat2, f, c - 1);
        else
            return mat1.getElemento(f, c) + mat2.getElemento(f, c) + sumaRecursivaMatrices(mat1, mat2, f - 1, MAX - 1);
    }
}

// Necesario para la instanciación de templates en cpp
template class Matriz<int>;
