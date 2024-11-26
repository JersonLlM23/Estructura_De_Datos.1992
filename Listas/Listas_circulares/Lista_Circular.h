#pragma once
#include "Nodo.h"
#include <iostream>
#include <algorithm>
#include <type_traits>
#include <string>

template<typename T>
class Lista_Circular {
private:
    Nodo<T>* cabeza;
public:
    Lista_Circular();
    void Insertar(T);
    void Buscar(T);
    void Eliminar(T);
    void Mostrar();
    void EliminarCaracter(char);
};

// Implementación
template<typename T>
Lista_Circular<T>::Lista_Circular() : cabeza(nullptr) {}

template<typename T>
void Lista_Circular<T>::Insertar(T _dato) {
    Nodo<T>* nuevo = new Nodo<T>(_dato);
    if (cabeza == nullptr) {
        cabeza = nuevo;
        nuevo->setSiguiente(cabeza);  // El último nodo apunta a la cabeza (circular)
    } else {
        Nodo<T>* aux = cabeza;
        while (aux->getSiguiente() != cabeza) {  // Recorre hasta el último nodo
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
        nuevo->setSiguiente(cabeza);  // El nuevo nodo apunta de vuelta a la cabeza
    }
}

template<typename T>
void Lista_Circular<T>::Buscar(T _dato) {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }
    Nodo<T>* aux = cabeza;
    do {
        if (aux->getDato() == _dato) {
            std::cout << "El dato " << _dato << " sí se encuentra en la lista." << std::endl;
            return;
        }
        aux = aux->getSiguiente();
    } while (aux != cabeza);  // Vuelve a la cabeza, es una lista circular
    std::cout << "El dato " << _dato << " no se encuentra en la lista." << std::endl;
}

template<typename T>
void Lista_Circular<T>::Eliminar(T _dato) {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }
    Nodo<T>* aux = cabeza;
    Nodo<T>* anterior = nullptr;
    do {
        if (aux->getDato() == _dato) {
            if (anterior == nullptr) {  // Eliminar la cabeza
                if (aux->getSiguiente() == cabeza) {  // Solo un nodo en la lista
                    delete aux;
                    cabeza = nullptr;
                    std::cout << "El dato " << _dato << " se ha eliminado de la lista." << std::endl;
                    return;
                } else {
                    Nodo<T>* ultimo = cabeza;
                    while (ultimo->getSiguiente() != cabeza) {
                        ultimo = ultimo->getSiguiente();
                    }
                    cabeza = aux->getSiguiente();
                    ultimo->setSiguiente(cabeza);  // El último nodo apunta a la nueva cabeza
                    delete aux;
                    std::cout << "El dato " << _dato << " se ha eliminado de la lista." << std::endl;
                    return;
                }
            } else {
                anterior->setSiguiente(aux->getSiguiente());
                delete aux;
                std::cout << "El dato " << _dato << " se ha eliminado de la lista." << std::endl;
                return;
            }
        }
        anterior = aux;
        aux = aux->getSiguiente();
    } while (aux != cabeza);  // Recorre hasta volver a la cabeza
    std::cout << "El dato " << _dato << " no se encuentra en la lista." << std::endl;
}

template<typename T>
void Lista_Circular<T>::Mostrar() {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }
    Nodo<T>* aux = cabeza;
    do {
        std::cout << aux->getDato() << " -> ";
        aux = aux->getSiguiente();
    } while (aux != cabeza);  // Recorre hasta volver a la cabeza
    std::cout << "(circular)" << std::endl;
}

template<typename T>
void Lista_Circular<T>::EliminarCaracter(char caracter) {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }
    Nodo<T>* aux = cabeza;
    do {
        if constexpr (std::is_same<T, std::string>::value) {
            std::string dato = aux->getDato();
            dato.erase(std::remove(dato.begin(), dato.end(), caracter), dato.end());
            aux->setDato(dato);
        }
        aux = aux->getSiguiente();
    } while (aux != cabeza);  // Recorre hasta volver a la cabeza
    std::cout << "Se han eliminado todas las ocurrencias del caracter '" << caracter << "' en la lista." << std::endl;
}
