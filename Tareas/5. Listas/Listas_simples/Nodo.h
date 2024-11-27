#pragma once
#include <string>

template <typename T>
class Nodo {
private:
    T dato;
    Nodo* siguiente;
public:
    Nodo(T _dato);
    T getDato();
    void setDato(T _dato);
    Nodo* getSiguiente();
    void setSiguiente(Nodo* _siguiente);
};

// Implementación
template<typename T>
Nodo<T>::Nodo(T _dato) : dato(_dato), siguiente(nullptr) {}

template<typename T>
T Nodo<T>::getDato() {
    return dato;
}

template<typename T>
void Nodo<T>::setDato(T _dato) {
    dato = _dato;
}

template<typename T>
Nodo<T>* Nodo<T>::getSiguiente() {
    return siguiente;
}

template<typename T>
void Nodo<T>::setSiguiente(Nodo* _siguiente) {
    siguiente = _siguiente;
}
