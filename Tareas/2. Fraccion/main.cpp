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

// Función para verificar que la entrada sea un número entero válido
void verificar(int &valor) {
    while (true) {
        std::cin >> valor;
        if (std::cin.fail()) { // Verifica si la entrada no es un número entero
            std::cout << "Error: debe ingresar un número entero. Intente nuevamente: ";
            std::cin.clear(); // Limpia el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada incorrecta
        } else {
            break; // Salir del bucle si la entrada es válida
        }
    }
}

int main() {
    int num1, den1, num2, den2;

    // Entrada de la primera fracción
    std::cout << "Ingrese el numerador de la primera fracción: ";
    verificar(num1);
    std::cout << "Ingrese el denominador de la primera fracción: ";
    verificar(den1);
    while (den1 == 0) {
        std::cout << "El denominador no puede ser cero. Intente nuevamente: ";
        verificar(den1);
    }

    Fraccion<int> f1(num1, den1);

    // Entrada de la segunda fracción
    std::cout << "Ingrese el numerador de la segunda fracción: ";
    verificar(num2);
    std::cout << "Ingrese el denominador de la segunda fracción: ";
    verificar(den2);
    while (den2 == 0) {
        std::cout << "El denominador no puede ser cero. Intente nuevamente: ";
        verificar(den2);
    }

    Fraccion<int> f2(num2, den2);

    // Operaciones con las fracciones
    Fraccion<int> operaciones;
    operaciones.sumar(f1, f2);
    operaciones.restar(f1, f2);
    operaciones.multiplicar(f1, f2);

    return 0;
}