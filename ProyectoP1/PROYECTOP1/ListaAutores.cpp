#include "ListaAutores.h"
#include "Validaciones.h"
#include <iostream>

ListaAutores::ListaAutores() : cabeza(nullptr) {}

ListaAutores::~ListaAutores() {
    if (cabeza) {
        NodoAutores* actual = cabeza;
        do {
            NodoAutores* siguiente = actual->getSiguiente();
            delete actual;
            actual = siguiente;
        } while (actual != cabeza);
    }
}

bool ListaAutores::insertar(string cedula, string nombre, string apellido, string fechaPublicacion) {
    if (buscar(cedula)) {
        cout << "Error: Autor con cédula " << cedula << " ya existe.\n";
        return false;
    }

    NodoAutores* nuevo = new NodoAutores(cedula, nombre, apellido, fechaPublicacion);

    if (!cabeza) {
        cabeza = nuevo;
        cabeza->setSiguiente(cabeza);
        cabeza->setAnterior(cabeza);
    } else {
        NodoAutores* ultimo = cabeza->getAnterior();
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        nuevo->setSiguiente(cabeza);
        cabeza->setAnterior(nuevo);
    }
    guardarEnArchivo();
    return true;
}

NodoAutores* ListaAutores::buscar(string cedula) {
    if (!cabeza) return nullptr;

    NodoAutores* actual = cabeza;
    do {
        if (actual->getCedula() == cedula) {
            return actual;
        }
        actual = actual->getSiguiente();
    } while (actual != cabeza);
    return nullptr;
}

bool ListaAutores::eliminar(string cedula) {
    NodoAutores* encontrado = buscar(cedula);
    if (!encontrado) {
        cout << "Error: Autor no encontrado.\n";
        return false;
    }

    if (encontrado->getSiguiente() == encontrado) {
        cabeza = nullptr;
    } else {
        NodoAutores* anterior = encontrado->getAnterior();
        NodoAutores* siguiente = encontrado->getSiguiente();
        anterior->setSiguiente(siguiente);
        siguiente->setAnterior(anterior);
        if (cabeza == encontrado) {
            cabeza = siguiente;
        }
    }
    delete encontrado;
    guardarEnArchivo();
    return true;
}

void ListaAutores::mostrar() {
    if (!cabeza) {
        cout << "Lista de autores vacía.\n";
        return;
    }

    NodoAutores* actual = cabeza;
    do {
        cout << "Cédula: " << actual->getCedula()
             << ", Nombre: " << actual->getNombre()
             << ", Apellido: " << actual->getApellido()
             << ", Fecha de Publicación: " << actual->getFechaPublicacion() << "\n";
        actual = actual->getSiguiente();
    } while (actual != cabeza);
}

void ListaAutores::cargarDesdeArchivo() {
    ifstream archivo("autores.txt");
    if (!archivo.is_open()) return;

    string cedula, nombre, apellido, fechaPublicacion;
    while (archivo >> cedula >> nombre >> apellido >> fechaPublicacion) {
        insertar(cedula, nombre, apellido, fechaPublicacion);
    }
    archivo.close();
}

void ListaAutores::guardarEnArchivo() {
    ofstream archivo("autores.txt", ios::trunc);
    if (!archivo.is_open()) return;

    NodoAutores* actual = cabeza;
    if (cabeza) {
        do {
            archivo << actual->getCedula() << " "
                    << actual->getNombre() << " "
                    << actual->getApellido() << " "
                    << actual->getFechaPublicacion() << "\n";
            actual = actual->getSiguiente();
        } while (actual != cabeza);
    }
    archivo.close();
}
