/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 10 de noviembre de 2024
 * Enunciado del problema: Mediante el uso de plantillas crear un programa que permita realizar operaciones con fracciones.
 * NRC: 1992
 *************************/
//fraccion.h
#ifndef FRACCION_H
#define FRACCION_H

#include <iostream>
#include <stdio.h>


template <typename T>
class Fraccion {
public:
    // Constructor
    Fraccion(T numerador = 0, T denominador = 1);

    // Getters y Setters
    T getNumerador();
    void setNumerador(T numerador);
    T getDenominador();
    void setDenominador(T denominador);

    // Métodos para operaciones
    Fraccion<T> sumar(const Fraccion<T>& f) const;
    Fraccion<T> restar(const Fraccion<T>& f) const;
    Fraccion<T> multiplicar(const Fraccion<T>& f) const;

private:
    T numerador;
    T denominador;
};
#endif
