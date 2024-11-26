/***********************************************************************
 * Module:  multiple.cpp
 * Author:  Maycol Celi
 * Date: 13/11/2024
 * Purpose: Calcular la posicion para numero de Tribonacci
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/
#include <iostream>
using namespace std;

int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}

int main() {
    int n;
    cout << "Ingresa la posición para el número de Tribonacci: ";
    cin >> n;
    cout << "El número de Tribonacci en la posición " << n << " es: " << tribonacci(n) << endl;
    return 0;
}
