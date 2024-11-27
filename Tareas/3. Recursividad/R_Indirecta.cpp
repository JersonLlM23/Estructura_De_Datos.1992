/***********************************************************************
 * Module:  R_Indirecta.cpp
 * Author:  Jerson Llumiquinga M.
 * Date: 20/11/2024
 * Purpose: Tipos de Recursividad
 * University: UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 ***********************************************************************/

/** Recursividad Indirecta **/

#include <iostream>
using namespace std;

// Declaración de las funciones para mostrar recursividad indirecta
void functionA(int n);
void functionB(int n);

// Función A: Llama a la función B
void functionA(int n) {
    if (n > 0) {
        cout << "Function A: " << n << endl;
        functionB(n - 1); // Llamada a la función B
    }
}

// Función B: Llama a la función A
void functionB(int n) {
    if (n > 0) {
        cout << "Function B: " << n << endl;
        functionA(n / 2); // Llamada a la función A
    }
}

int main() {
    int number;
    cout << "Introduce un número: ";
    cin >> number;

    cout << "Iniciando recursión indirecta:" << endl;
    functionA(number);

    return 0;
}

