/***********************************************************************
 * Module:  mainLambda.cpp
 * Author:  Maycol Celi
 * Date: 19/11/2024
 * Purpose: Sumar matrices con Lambda
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/
#include "MatrizLambda.h"
#include <iostream>

using namespace std;

int main() {
    // Crear un objeto MatrizLambda con tipo int
    MatrizLambda<int> matriz;

    // Impresión de la primera matriz
    cout << "Matriz 1:" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << matriz.getElementoMat1(i, j) << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Impresión de la segunda matriz
    cout << "Matriz 2:" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << matriz.getElementoMat2(i, j) << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Definir una lambda que suma las matrices
    auto sumaLambda = [&matriz]() {
        int suma = 0;
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                suma += matriz.getElementoMat1(i, j) + matriz.getElementoMat2(i, j);
            }
        }
        return suma;
    };

    // Usar la lambda para realizar la suma
    cout << "Suma de Matrices es: " << sumaLambda() << endl;

    return 0;
}
