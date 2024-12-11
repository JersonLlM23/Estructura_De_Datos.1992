/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 10 de noviembre de 2024
 * Enunciado del problema: Mediante el uso de plantillas crear un programa que permita realizar operaciones con fracciones.
 * NRC: 1992
 *************************/
#include <iostream>
#include "Fraccion.cpp"  
#include <limits>
#include <string>
#include<conio.h>

// Función para verificar que la entrada sea un número entero válido

int ingresar_numero() {
    std::string entrada;
    char c;
    entrada.clear(); 

    while (true) {
        c = getch(); // Leer un carácter
        if (c >= '0' && c <= '9') { 
            // Permite agregar dígitos sin límite
            std::cout << c; 
            entrada += c; 
        } else if (c == 8 && !entrada.empty()) { // Permite retroceder (borrar)
            std::cout << "\b \b"; 
            entrada.pop_back();   
        } else if (c == 13 && !entrada.empty()) { // Valida que no se pueda presionar Enter con una entrada vacía
            std::cout << std::endl;
            break; 
        }
    }
    return std::stoi(entrada);
}

int main() {
    int num1, den1, num2, den2;

    // Entrada de la primera fracción
    std::cout << "Ingrese el numerador de la primera fracción: ";
    num1=ingresar_numero();
    std::cout << "Ingrese el denominador de la primera fracción: ";
    den1=ingresar_numero();
    while (den1 == 0) {
        std::cout << "El denominador no puede ser cero. Intente nuevamente: ";
        den1=ingresar_numero();
    }

    Fraccion<int> f1(num1, den1);

    // Entrada de la segunda fracción
    std::cout << "Ingrese el numerador de la segunda fracción: ";
    num2=ingresar_numero();
    std::cout << "Ingrese el denominador de la segunda fracción: ";
    den2=ingresar_numero();
    while (den2 == 0) {
        std::cout << "El denominador no puede ser cero. Intente nuevamente: ";
        den2=ingresar_numero();
    }

    Fraccion<int> f2(num2, den2);

    // Operaciones
    std::cout << "Resultados:\n";
    std::cout << "Suma: " << f1.sumar(f2).getNumerador()<<"/"<< f1.sumar(f2).getDenominador()<< "\n";
    std::cout << "Resta: " << f1.restar(f2).getNumerador()<<"/"<< f1.restar(f2).getDenominador()<< "\n";
    std::cout << "Multiplicación: " << f1.multiplicar(f2).getNumerador()<<"/"<< f1.multiplicar(f2).getDenominador()<< "\n";

    return 0;
}