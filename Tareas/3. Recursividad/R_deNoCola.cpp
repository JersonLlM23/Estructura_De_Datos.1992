/***********************************************************************
 * Module:  R_deNoCola.cpp
 * Author:  Jerson Llumiquinga M.
 * Date: 20/11/2024
 * Purpose: Tipos de Recursividad
 * University: UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 ***********************************************************************/

/** Recursividad De No Cola **/
// Suma de números naturales

#include <iostream>
using namespace std;

// Función recursiva
int sum(int n) {
    if (n == 0) {
        return 0; // Caso base
    }
    // Llamada recursiva no de cola
    return n + sum(n - 1);
}

int main() {
    int number;
    cout << "Introduce un numero: ";
    cin >> number;

    if (number < 0) {
        cout << "La suma no esta definida para números negativos." << endl;
    } else {
        cout << "La suma de los numeros naturales hasta " << number << " es: " << sum(number) << endl;
    }

    return 0;
}
