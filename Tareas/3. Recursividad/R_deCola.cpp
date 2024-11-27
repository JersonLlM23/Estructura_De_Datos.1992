/***********************************************************************
 * Module:  R_deCola.cpp
 * Author:  Jerson Llumiquinga M.
 * Date: 20/11/2024
 * Purpose: Tipos de Recursividad
 * University: UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 ***********************************************************************/

/** Recursividad De Cola **/
// Factorial

#include <iostream>
using namespace std;

// Función auxiliar para implementar recursividad de cola
int factorialTailRec(int n, int result) {
    if (n == 0 || n == 1) {
        return result; // Caso base
    }
    // Llamada recursiva con la acumulación del resultado
    return factorialTailRec(n - 1, n * result);
}

// Función principal para calcular el factorial
int factorial(int n) {
    return factorialTailRec(n, 1);
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

