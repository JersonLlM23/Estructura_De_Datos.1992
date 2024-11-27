#pragma once
#include "Nodo.h"
#include <iostream>
#include <algorithm>
#include <type_traits>
#include <string>

template<typename T>
class Lista_Simple {
private:
    Nodo<T>* cabeza;
public:
    Lista_Simple();
    void Insertar_cabeza(T);
    void Buscar(T);
    void Eliminar(T);
    void Mostrar();
    void EliminarCaracter(char);
};

// Implementación
template<typename T>
Lista_Simple<T>::Lista_Simple() : cabeza(nullptr) {}

template<typename T>
void Lista_Simple<T>::Insertar_cabeza(T _dato) {
    Nodo<T>* nuevo = new Nodo<T>(_dato);
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        Nodo<T>* aux = cabeza;
        while (aux->getSiguiente() != nullptr) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
}

template<typename T>
void Lista_Simple<T>::Buscar(T _dato) {
    Nodo<T>* aux = cabeza;
    while (aux != nullptr) {
        if (aux->getDato() == _dato) {
            std::cout << "El dato " << _dato << " sí se encuentra en la lista." << std::endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    std::cout << "El dato " << _dato << " no se encuentra en la lista." << std::endl;
}

template<typename T>
void Lista_Simple<T>::Eliminar(T _dato) {
    Nodo<T>* aux = cabeza;
    Nodo<T>* anterior = nullptr;
    while (aux != nullptr) {
        if (aux->getDato() == _dato) {
            if (anterior == nullptr) {
                cabeza = aux->getSiguiente();
            } else {
                anterior->setSiguiente(aux->getSiguiente());
            }
            delete aux;
            std::cout << "El dato " << _dato << " se ha eliminado de la lista." << std::endl;
            return;
        }
        anterior = aux;
        aux = aux->getSiguiente();
    }
    std::cout << "El dato " << _dato << " no se encuentra en la lista." << std::endl;
}

template<typename T>
void Lista_Simple<T>::Mostrar() {
    Nodo<T>* aux = cabeza;
    while (aux != nullptr) {
        std::cout << aux->getDato() << " -> ";
        aux = aux->getSiguiente();
    }
    std::cout << "NULL" << std::endl;
}

template<typename T>
void Lista_Simple<T>::EliminarCaracter(char caracter) {
    Nodo<T>* aux = cabeza;
    while (aux != nullptr) {
        if constexpr (std::is_same<T, std::string>::value) {
            std::string dato = aux->getDato();
            dato.erase(std::remove(dato.begin(), dato.end(), caracter), dato.end());
            aux->setDato(dato);
        }
        aux = aux->getSiguiente();
    }
    std::cout << "Se han eliminado todas las ocurrencias del caracter '" << caracter << "' en la lista." << std::endl;
}
