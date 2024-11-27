/***********************************************************************
 * Module:  R_Simple.cpp
 * Author:  Jerson Llumiquinga M.
 * Date: 20/11/2024
 * Purpose: Tipos de Recursividad
 * University: UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 ***********************************************************************/

/** Recursividad Simple **/
//Factorial

#include <iostream>
using namespace std;

// Función recursiva
int factorial(int n) {
    if (n <= 1) {
        return 1; // Caso base: el factorial de 0 o 1 es 1
    }
    // Llamada recursiva
    return n * factorial(n - 1);
}

int main() {
    int number;
    cout << "Introduce un numero: ";
    cin >> number;

    if (number < 0) {
        cout << "El factorial no esta definido para numeros negativos." << endl;
    } else {
        cout << "El factorial de " << number << " es: " << factorial(number) << endl;
    }
    return 0;
}

