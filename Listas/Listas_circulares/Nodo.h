/***********************************************************************
 * Module:  Nodo.h
 * Author:  Maycol Celi,Erika Guayanay, Jerson Llumiquinga M.
 * Date: 25/11/2024
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/

#ifndef NODO_H
#define NODO_H

#include <string>
using namespace std;

class Nodo {
private:
    string cedula, nombre, apellido;
    Nodo* siguiente;

public:
    Nodo(string cedula, string nombre, string apellido);
    string getCedula();
    string& getNombre();
    string& getApellido();
    Nodo* getSiguiente();
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setSiguiente(Nodo* siguiente);
};

#endif
