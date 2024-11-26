/***********************************************************************
 * Module:  mutua.cpp
 * Author:  Maycol Celi
 * Date: 13/11/2024
 * Purpose: Ver si un numero es par o impar
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/
#include <iostream>
using namespace std;

bool esImpar(int n);

bool esPar(int n) {
    if (n == 0) return true;
    return esImpar(n - 1);
}

bool esImpar(int n) {
    if (n == 0) return false;
    return esPar(n - 1);
}

int main() {
    int n;
    cout << "Ingresa un número para verificar si es par o impar: ";
    cin >> n;
    cout << n << (esPar(n) ? " es par." : " es impar.") << endl;
    return 0;
}
