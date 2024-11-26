/***********************************************************************
 * Module:  indirecta.cpp
 * Author:  Maycol Celi
 * Date: 13/11/2024
 * Purpose: Ver si un numero es divisible para 3
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/
#include <iostream>
using namespace std;

bool divisiblePor3(int n);
bool divisiblePor3aux(int n);

bool divisiblePor3(int n) {
    if (n == 0) return true;
    if (n == 1 || n == 2) return false;
    return divisiblePor3aux(n - 3);
}

bool divisiblePor3aux(int n) {
    return divisiblePor3(n);
}

int main() {
    int n;
    cout << "Ingresa un número para verificar si es divisible por 3: ";
    cin >> n;
    cout << n << (divisiblePor3(n) ? " es divisible por 3." : " no es divisible por 3.") << endl;
    return 0;
}
