/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  Maycol Celi,Erika Guayanay, Jerson Llumiquinga M.
 * Date: 25/11/2024
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/

#include "Nodo.h"

Nodo::Nodo(string cedula, string nombre, string apellido) {
    this->cedula = cedula;
    this->nombre = nombre;
    this->apellido = apellido;
    this->siguiente = nullptr;
}

string Nodo::getCedula() {
    return cedula;
}

string& Nodo::getNombre() {
    return nombre;
}

string& Nodo::getApellido() {
    return apellido;
}

Nodo* Nodo::getSiguiente() {
    return siguiente;
}

void Nodo::setSiguiente(Nodo* siguiente) {
    this->siguiente = siguiente;
}
void Nodo::setNombre(string nombre) {
    this->nombre = nombre;
}

void Nodo::setApellido(string apellido) {
    this->apellido = apellido;
}
