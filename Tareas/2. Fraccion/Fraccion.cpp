/***********************************************************************
 * Module:  Fraccion.cpp
 * Author:  Jerson Llumiquinga M.
 * Date: 11/11/2024
 * Purpose: Sumar dos fracciones usando plantillas
 * University: UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 ***********************************************************************/
#include "Fraccion.h"
#include <stdexcept>

// Constructor
template <typename T>
Fraccion<T>::Fraccion(T numerador, T denominador) : numerador(numerador), denominador(denominador) {
}

// Destructor
template <typename T>
Fraccion<T>::~Fraccion() {}

// Setters
template <typename T>
void Fraccion<T>::setNumerador(T numerador) {
    this->numerador = numerador;
}

// Getters
template <typename T>
T Fraccion<T>::getNumerador() const {
    return numerador;
}

template <typename T>
T Fraccion<T>::getDenominador() const {
    return denominador;
}

// Método para procesar la suma de dos fracciones
template <typename T>
Fraccion<T> Fraccion<T>::procesar(const Fraccion<T>& obj1, const Fraccion<T>& obj2) {
    T nuevoNumerador = obj1.numerador * obj2.denominador + obj2.numerador * obj1.denominador;
    T nuevoDenominador = obj1.denominador * obj2.denominador;
    return Fraccion<T>(nuevoNumerador, nuevoDenominador);
}
