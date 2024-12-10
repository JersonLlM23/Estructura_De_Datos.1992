/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 22 de noviembre de 2024
 * TEMA: Lista simple
 * NRC: 1992
 *************************/
 
#ifndef I_LISTA_SIMPLE_H
#define I_LISTA_SIMPLE_H

#include <string>
using namespace std;

class Nodo;

class I_Lista_Simple
{
public:
    virtual ~I_Lista_Simple() {}

    virtual void Password(Nodo *nodo) = 0;
};

#endif
