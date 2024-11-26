/***********************************************************************
 * Module:  decola.cpp
 * Author:  Maycol Celi
 * Date: 13/11/2024
 * Purpose: Suma de digitos ingresados
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/
#include <iostream>
using namespace std;

int sumaDigitos(int n, int acumulador = 0) {
    if (n == 0) return acumulador;
    return sumaDigitos(n / 10, acumulador + (n % 10));
}

int main() {
    int n;
    cout << "Ingresa un número para calcular la suma de sus dígitos: ";
    cin >> n;
    cout << "La suma de los dígitos es: " << sumaDigitos(n) << endl;
    return 0;
}
