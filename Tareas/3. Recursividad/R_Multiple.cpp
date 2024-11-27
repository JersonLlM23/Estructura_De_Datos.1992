/***********************************************************************
 * Module:  R_Multiple.cpp
 * Author:  Jerson Llumiquinga M.
 * Date: 20/11/2024
 * Purpose: Tipos de Recursividad
 * University: UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 ***********************************************************************/

/** Recursividad Múltiple **/
// Fibonacci

#include <iostream>
using namespace std;

// Función recursiva
int fibonacci(int n) {
    if (n <= 1) {
        return n; // Caso base
    }
    // Llamadas recursivas múltiples
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int number;
    cout << "Introduce el número de términos para la serie de Fibonacci: ";
    cin >> number;

    cout << "Serie de Fibonacci: ";
    for (int i = 0; i < number; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}
