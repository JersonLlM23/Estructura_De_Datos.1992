/***********************************************************************
 * Module:  denocola.cpp
 * Author:  Maycol Celi
 * Date: 13/11/2024
 * Purpose: Para calcular minimo comun divisor
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/
#include <iostream>
using namespace std;

int mcd(int a, int b) {
    if (b == 0) return a;
    return mcd(b, a % b);
}

int main() {
    int a, b;
    cout << "Ingresa dos números para calcular su MCD: ";
    cin >> a >> b;
    cout << "El MCD de " << a << " y " << b << " es: " << mcd(a, b) << endl;
    return 0;
}
