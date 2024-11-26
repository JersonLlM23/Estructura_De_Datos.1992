/***********************************************************************
 * Module:  simple.cpp
 * Author:  Maycol Celi
 * Date: 13/11/2024
 * Purpose: Calcular pontencia de un numero
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/
#include <iostream>
using namespace std;

int potencia(int base, int exponente) {
    if (exponente == 0) return 1;
    return base * potencia(base, exponente - 1);
}

int main() {
    int base, exponente;
    cout << "Ingresa la base y el exponente: ";
    cin >> base >> exponente;
    cout << base << " elevado a " << exponente << " es: " << potencia(base, exponente) << endl;
    return 0;
}
