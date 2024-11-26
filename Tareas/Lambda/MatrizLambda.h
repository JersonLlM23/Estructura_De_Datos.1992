/***********************************************************************
 * Module:  MatrizLambda.h
 * Author:  Maycol Celi
 * Date: 19/11/2024
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/
#ifndef MATRIZLAMBDA_H
#define MATRIZLAMBDA_H

#include <iostream>
#define MAX 3

template <typename T>
class MatrizLambda {
private:
    T mat1[MAX][MAX];
    T mat2[MAX][MAX];

public:
    // Constructor
    MatrizLambda();

    // Getters
    T getElementoMat1(int f, int c) const;
    T getElementoMat2(int f, int c) const;

    // Setters
    void setElementoMat1(int f, int c, T valor);
    void setElementoMat2(int f, int c, T valor);

    // Método de suma recursiva
    T sumaRecursivaMatrices(int f, int c) const;
};

#include "MatrizLambda.cpp" // Incluir implementación del template
#endif // MATRIZLAMBDA_H
