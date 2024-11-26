/***********************************************************************
 * Module:  ListasCirculares.h
 * Author:  Maycol Celi,Erika Guayanay, Jerson Llumiquinga M.
 * Date: 25/11/2024
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/

#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include "Nodo.h"
#include <string>
#include <iostream>
using namespace std;

class ListaCircular {
private:
    Nodo* ultimo;

public:
    ListaCircular();
    ~ListaCircular();
    void insertar(string cedula, string nombre, string apellido);
    Nodo* buscar(string cedula);
    bool eliminar(string cedula);
    void mostrar();
    void eliminarCaracter(string cedula, char caracter);
};

#endif
