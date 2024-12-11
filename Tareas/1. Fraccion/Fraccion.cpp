/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 10 de noviembre de 2024
 * Enunciado del problema: Mediante el uso de plantillas crear un programa que permita realizar operaciones con fracciones.
 * NRC: 1992
 *************************/
//fraccion.cpp
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

// Operaciones con fracciones
template <typename T>
Fraccion<T> Fraccion<T>::sumar(const Fraccion<T>& f) const {
    T num = numerador * f.denominador + f.numerador * denominador;
    T den = denominador * f.denominador;
    return Fraccion<T>(num, den);
}

template <typename T>
Fraccion<T> Fraccion<T>::restar(const Fraccion<T>& f) const {
    T num = numerador * f.denominador - f.numerador * denominador;
    T den = denominador * f.denominador;
    return Fraccion<T>(num, den);
}

template <typename T>
Fraccion<T> Fraccion<T>::multiplicar(const Fraccion<T>& f) const {
    T num = numerador * f.numerador;
    T den = denominador * f.denominador;
    return Fraccion<T>(num, den);
}










