/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 10 de noviembre de 2024
 * Enunciado del problema: Mediante el uso de plantillas crear un programa que permita realizar operaciones con fracciones.
 * NRC: 1992
 *************************/

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

    // Metodo para sumar dos fracciones
    void sumar(Fraccion<T> f1,Fraccion<T> f2);
    
    // Metodo para restar dos fracciones
    void restar(Fraccion<T> f1,Fraccion<T> f2);
    
    // Metodo para multiplicar dos fracciones
    void multiplicar(Fraccion<T> f1,Fraccion<T> f2);
    
private:
    T numerador;
    T denominador;
};

