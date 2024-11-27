/***********************************************************************
 * Module:  mainMatriz.cpp
 * Author:  Jerson Llumiquinga M
 * Date: 22/11/2024
  * Purpose: Sumando elementos de las matrices usando plantillas
 * University: UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 ***********************************************************************/
#include <iostream>
#include "Matriz.cpp"

using namespace std;

int main() {
    // Crear dos matrices de tipo int
    Matriz<int> mat1;
    Matriz<int> mat2;

    cout << "Matriz 1:" << endl;
    mat1.imprimirMatriz();
    cout << endl;

    cout << "Matriz 2:" << endl;
    mat2.imprimirMatriz();
    cout << endl;

    int resultado = mat1.sumaRecursivaMatrices(mat1, mat2, MAX - 1, MAX - 1);
    cout << "Suma de las matrices es: " << resultado << endl;

    return 0;
}
