/***********************************************************************
 * Module:  main.cpp
 * Author:  Jerson Llumiquinga M.
 * Date: 11/11/2024
 * Purpose: Sumar dos fracciones usando plantillas
 * University: UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 ***********************************************************************/

#include "Fraccion.cpp"
#include <iostream>
#include <limits>
#include <string>
#include <cctype>
using namespace std;

bool validarEntrada(int& valor) {
    string entrada;
    cin >> entrada;

    for (char c : entrada) {
        if (!isdigit(c) && c != '-') {
            if (c == '.' || c == ',') {
                return false;
            }
            return false;
        }
    }
    // Convertir la entrada válida en un número entero
    try {
        valor = stoi(entrada);  // Si la conversión es exitosa, es un número entero válido
    } catch (const invalid_argument& e) {
        return false;  // Si no se puede convertir, es una entrada no válida
    } catch (const out_of_range& e) {
        return false;
    }
    return true;  // La entrada es un número entero válido
}


int main() {
    try {
        int numerador1, denominador1, numerador2, denominador2;
        cout << "Ingrese el numerador de la primera fraccion: ";
        while (!validarEntrada(numerador1)) {
            cout << "Entrada inválida. Por favor, intente de nuevo:";
        }
        cout << "Ingrese el denominador de la primera fracción: ";
        while (!validarEntrada(denominador1) || denominador1 == 0) {
            cout << "Entrada inválida. Por favor, intente de nuevo:";
        }
        cout << "Ingrese el numerador de la segunda fraccion: ";
        while (!validarEntrada(numerador2)) {
            cout << "Entrada inválida. Por favor, intente de nuevo:";
        }

        cout << "Ingrese el denominador de la segunda fraccion: ";
        while (!validarEntrada(denominador2) || denominador2 == 0) {
            cout << "Entrada inválida. Por favor, intente de nuevo:";
        }

        Fraccion<int> fraccion1(numerador1, denominador1);
        Fraccion<int> fraccion2(numerador2, denominador2);
        Fraccion<int> resultado = fraccion1.procesar(fraccion1, fraccion2);

        cout << "La suma de las fracciones "
             << fraccion1.getNumerador() << "/" << fraccion1.getDenominador()<< " + "
             << fraccion2.getNumerador() << "/" << fraccion2.getDenominador() << " es: "
             << resultado.getNumerador() << "/" << resultado.getDenominador()
             << endl;

        double resultadoDecimal = static_cast<double>(resultado.getNumerador()) / resultado.getDenominador();
        cout << "El resultado en decimal es: " << resultadoDecimal << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
