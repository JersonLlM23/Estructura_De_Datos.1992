/***********************************************************************
 * Module:  Fraccion.h
 * Author:  Jerson Llumiquinga M.
 * Date: 11/11/2024
 * Purpose: Sumar dos fracciones usando plantillas
 * University: UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 ***********************************************************************/
#ifndef FRACCION_H
#define FRACCION_H
#include <iostream>

template <typename T>
class Fraccion {
public:
    // Constructor
    Fraccion(T numerador = 0, T denominador = 1);

    // Destructor
    ~Fraccion();

    // Setters:
    void setNumerador(T numerador);
    void setDenominador(T denominador);

    // Getters:
    T getNumerador() const;
    T getDenominador() const;

    // Método para procesar la suma de dos objetos Fraccion
    Fraccion<T> procesar(const Fraccion<T>& obj1, const Fraccion<T>& obj2);
private:
    T numerador;
    T denominador;
};

#endif
