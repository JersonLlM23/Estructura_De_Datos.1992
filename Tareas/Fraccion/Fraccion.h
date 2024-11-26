/***********************************************************************
 * Module:  Fraccion.h
 * Author:  Maycol Celi
 * Date: 11/11/2024
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/
#ifndef FRACCION_H
#define FRACCION_H

#include <iostream>

template <typename T>
class Fraccion {
public:
    // Constructor y destructor opcional
    Fraccion(T numerador = 0, T denominador = 1);
    ~Fraccion();

    // Setters y getters
    void setNumerador(T numerador);
    void setDenominador(T denominador);
    T getNumerador() const;
    T getDenominador() const;

    // Método para procesar la suma de dos objetos Fraccion
    Fraccion<T> procesar(const Fraccion<T>& obj1, const Fraccion<T>& obj2);

private:
    T numerador;
    T denominador;
};

#endif
