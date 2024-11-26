#include "Lista_Circular.h"
#include <iostream>

using namespace std;

template <typename T>
Lista_Simple<T>::Lista_Simple() {
    cabeza = nullptr;
}

template <typename T>
void Lista_Simple<T>::Insertar_cabeza(T _dato) {
    Nodo<T>* nuevo = new Nodo<T>(_dato);
    if (cabeza == nullptr) {
        cabeza = nuevo;
        nuevo->setSiguiente(cabeza);  // El nodo último apunta a la cabeza (circular)
    } else {
        Nodo<T>* aux = cabeza;
        while (aux->getSiguiente() != cabeza) {  // Recorre hasta el último nodo
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
        nuevo->setSiguiente(cabeza);  // El nuevo nodo apunta a la cabeza, haciendo circular la lista
    }
}

template<typename T>
void Lista_Simple<T>::Buscar(T _dato) {
    if (cabeza == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }
    Nodo<T>* aux = cabeza;
    do {
        if (aux->getDato() == _dato) {
            cout << "El dato " << _dato << " sí se encuentra en la lista." << endl;
            return;
        }
        aux = aux->getSiguiente();
    } while (aux != cabeza);  // Vuelve a la cabeza (lista circular)
    cout << "El dato " << _dato << " no se encuentra en la lista." << endl;
}

template<typename T>
void Lista_Simple<T>::Eliminar(T _dato) {
    if (cabeza == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }

    Nodo<T>* aux = cabeza;
    Nodo<T>* anterior = nullptr;

    do {
        if (aux->getDato() == _dato) {
            if (anterior == nullptr) {  // Si es la cabeza
                if (aux->getSiguiente() == cabeza) {  // Solo hay un nodo en la lista
                    delete aux;
                    cabeza = nullptr;
                    cout << "El dato " << _dato << " se ha eliminado de la lista." << endl;
                    return;
                } else {
                    Nodo<T>* ultimo = cabeza;
                    while (ultimo->getSiguiente() != cabeza) {  // Busca el último nodo
                        ultimo = ultimo->getSiguiente();
                    }
                    cabeza = aux->getSiguiente();  // Actualiza la cabeza
                    ultimo->setSiguiente(cabeza);  // El último nodo apunta a la nueva cabeza
                    delete aux;
                    cout << "El dato " << _dato << " se ha eliminado de la lista." << endl;
                    return;
                }
            } else {
                anterior->setSiguiente(aux->getSiguiente());  // Elimina el nodo en medio
                delete aux;
                cout << "El dato " << _dato << " se ha eliminado de la lista." << endl;
                return;
            }
        }
        anterior = aux;
        aux = aux->getSiguiente();
    } while (aux != cabeza);  // Vuelve a la cabeza (lista circular)
    cout << "El dato " << _dato << " no se encuentra en la lista." << endl;
}

template<typename T>
void Lista_Simple<T>::Mostrar() {
    if (cabeza == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }
    Nodo<T>* aux = cabeza;
    do {
        cout << aux->getDato() << " -> ";
        aux = aux->getSiguiente();
    } while (aux != cabeza);  // Vuelve a la cabeza (lista circular)
    cout << "(circular)" << endl;
}
