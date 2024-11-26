/***********************************************************************
 * Module:  MatrizLambda.cpp
 * Author:  Maycol Celi
 * Date: 19/11/2024
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/
#include "MatrizLambda.h"
#include <ctime>
#include <cstdlib>

// Constructor que inicializa las matrices con valores aleatorios
template <typename T>
MatrizLambda<T>::MatrizLambda() {
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            mat1[i][j] = rand() % 100; // Números aleatorios entre 0 y 99
            mat2[i][j] = rand() % 100;
        }
    }
}

// Getters
template <typename T>
T MatrizLambda<T>::getElementoMat1(int f, int c) const {
    return mat1[f][c];
}

template <typename T>
T MatrizLambda<T>::getElementoMat2(int f, int c) const {
    return mat2[f][c];
}

// Setters
template <typename T>
void MatrizLambda<T>::setElementoMat1(int f, int c, T valor) {
    mat1[f][c] = valor;
}

template <typename T>
void MatrizLambda<T>::setElementoMat2(int f, int c, T valor) {
    mat2[f][c] = valor;
}

// Método de suma recursiva
template <typename T>
T MatrizLambda<T>::sumaRecursivaMatrices(int f, int c) const {
    if (f == 0 && c == 0) {
        return mat1[f][c] + mat2[f][c];
    }
    if (c > 0) {
        return mat1[f][c] + mat2[f][c] + sumaRecursivaMatrices(f, c - 1);
    } else if (f > 0) {
        return mat1[f][c] + mat2[f][c] + sumaRecursivaMatrices(f - 1, MAX - 1);
    }
    return 0; // Retorno para evitar advertencias
}
