/***********************************************************************
 * Module:  mainMatriz.cpp
 * Author:  Maycol Celi
 * Date: 14/11/2024
 * Purpose: Sumar dos matrices con elementos aleatorios
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/
#include <iostream>
#include "Matriz.cpp"

using namespace std;

int main() {
    // Crear dos matrices de tipo int
    Matriz<int> mat1;
    Matriz<int> mat2;
    
    // Imprimir la primera matriz
    cout << "Matriz 1:" << endl;
    mat1.imprimirMatriz();
    cout << endl;

    // Imprimir la segunda matriz
    cout << "Matriz 2:" << endl;
    mat2.imprimirMatriz();
    cout << endl;

    // Sumar las matrices usando la suma recursiva
    int resultado = mat1.sumaRecursivaMatrices(mat1, mat2, MAX - 1, MAX - 1);
    cout << "Suma de las matrices es: " << resultado << endl;

    return 0;
}
