/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 10 de noviembre de 2024
 * Enunciado del problema: Mediante el uso de plantillas crear un programa que permita realizar operaciones con fracciones.
 * NRC: 1992
 *************************/

#include <iostream>
#include "Fraccion.h"
#include <stdio.h>
using namespace std;

// Constructor
template <typename T>
Fraccion<T>::Fraccion(T num, T den) : numerador(num), denominador(den) {
}

// Getters
template <typename T>
T Fraccion<T>::getNumerador() {
    return numerador;
}

template <typename T>
T Fraccion<T>::getDenominador() {
    return denominador;
}

// Setters
template <typename T>
void Fraccion<T>::setNumerador(T num) {
    numerador = num; 
}

template <typename T>
void Fraccion<T>::setDenominador(T den) {
    denominador = den; 
}

// Metodo para sumar dos fracciones
template <typename T>
void Fraccion<T>::sumar(Fraccion<T> f1, Fraccion<T> f2) {
    Fraccion<T> fr;
    fr.setNumerador(f1.numerador * f2.denominador + f2.numerador * f1.denominador);
    fr.setDenominador(f1.denominador * f2.denominador);
    cout << "resultado de la suma: " << fr.getNumerador() << "/" << fr.getDenominador() << endl;
}

// Metodo para restar dos fracciones
template <typename T>
void Fraccion<T>::restar(Fraccion<T> f1, Fraccion<T> f2) {
    Fraccion<T> fr; 
    fr.setNumerador(f1.numerador * f2.denominador - f2.numerador * f1.denominador);
    fr.setDenominador(f1.denominador * f2.denominador);
    cout << "resultado de la resta: " << fr.getNumerador() << "/" << fr.getDenominador() << endl;
}

// Metodo para multiplicar dos fracciones
template <typename T>
void Fraccion<T>::multiplicar(Fraccion<T> f1, Fraccion<T> f2) {
    Fraccion<T> fr; 
    fr.setNumerador(f1.numerador * f2.numerador);
    fr.setDenominador(f1.denominador * f2.denominador);
    cout << "resultado de la multiplicacion: " << fr.getNumerador() << "/" << fr.getDenominador() << endl;
}








