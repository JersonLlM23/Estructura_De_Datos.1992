/***********************************************************************
 * Module:  R_Anidada.cpp
 * Author:  Jerson Llumiquinga M.
 * Date: 20/11/2024
 * Purpose: Tipos de Recursividad
 * University: UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 ***********************************************************************/

/** Recursividad Anidada **/
// Secuencia numérica

#include <iostream>
using namespace std;

int nestedRecursion(int n) {
    if (n > 100) {
        return n - 10; // Caso base
    } else {
        // Llamada recursiva anidada
        return nestedRecursion(nestedRecursion(n + 11));
    }
}
int main() {
    int input;
    cout << "Introduce un numero: ";
    cin >> input;
    int result = nestedRecursion(input);
    cout << "Resultado: " << result << endl;
    return 0;
}

