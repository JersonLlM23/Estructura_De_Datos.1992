/***********************************************************************
 * Module:  ListasCirculares.cpp
 * Author:  Maycol Celi,Erika Guayanay, Jerson Llumiquinga M.
 * Date: 25/11/2024
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/

#include "ListasCirculares.h"

ListaCircular::ListaCircular() {
    ultimo = nullptr;
}

ListaCircular::~ListaCircular() {
    if (ultimo) {
        Nodo* actual = ultimo->getSiguiente();
        Nodo* temp;
        while (actual != ultimo) {
            temp = actual;
            actual = actual->getSiguiente();
            delete temp;
        }
        delete ultimo;
    }
}

void ListaCircular::insertar(string cedula, string nombre, string apellido) {
    Nodo* nuevo = new Nodo(cedula, nombre, apellido);
    if (!ultimo) {
        ultimo = nuevo;
        ultimo->setSiguiente(nuevo);
    } else {
        nuevo->setSiguiente(ultimo->getSiguiente());
        ultimo->setSiguiente(nuevo);
        ultimo = nuevo;
    }
}

Nodo* ListaCircular::buscar(string cedula) {
    if (!ultimo) return nullptr;
    Nodo* actual = ultimo->getSiguiente();
    do {
        if (actual->getCedula() == cedula) return actual;
        actual = actual->getSiguiente();
    } while (actual != ultimo->getSiguiente());
    return nullptr;
}

bool ListaCircular::eliminar(string cedula) {
    if (!ultimo) return false;
    Nodo* actual = ultimo->getSiguiente();
    Nodo* anterior = ultimo;
    do {
        if (actual->getCedula() == cedula) {
            if (actual == ultimo->getSiguiente() && actual == ultimo) {
                // Único nodo
                delete actual;
                ultimo = nullptr;
            } else {
                anterior->setSiguiente(actual->getSiguiente());
                if (actual == ultimo) ultimo = anterior;
                delete actual;
            }
            return true;
        }
        anterior = actual;
        actual = actual->getSiguiente();
    } while (actual != ultimo->getSiguiente());
    return false;
}

void ListaCircular::mostrar() {
    if (!ultimo) {
        cout << "La lista está vacía.\n";
        return;
    }
    Nodo* actual = ultimo->getSiguiente();
    do {
        cout << "<Cedula: " << actual->getCedula()
             << ", Nombre: " << actual->getNombre()
             << ", Apellido: " << actual->getApellido() << ">\n";
        actual = actual->getSiguiente();
    } while (actual != ultimo->getSiguiente());
}

void ListaCircular::eliminarCaracter(string cedula, char caracter) {
    Nodo* encontrado = buscar(cedula);
    if (encontrado) {
        string nuevoNombre = "", nuevoApellido = "";

        // Eliminar el caracter del nombre
        for (char c : encontrado->getNombre()) {
            if (c != caracter) nuevoNombre += c;
        }
        encontrado->getNombre() = nuevoNombre;

        // Eliminar el caracter del apellido
        for (char c : encontrado->getApellido()) {
            if (c != caracter) nuevoApellido += c;
        }
        encontrado->getApellido() = nuevoApellido;

        cout << "Caracter eliminado del nombre y apellido.\n";
    } else {
        cout << "Error: Persona no encontrada.\n";
    }
}
