#include "ListaLibros.h"
#include <iostream>

ListaLibros::ListaLibros() : cabeza(nullptr) {}

ListaLibros::~ListaLibros() {
    if (cabeza) {
        NodoLibros* actual = cabeza;
        do {
            NodoLibros* siguiente = actual->getSiguiente();
            delete actual;
            actual = siguiente;
        } while (actual != cabeza);
    }
}

bool ListaLibros::insertar(string titulo, string autor, string isbn, string genero, int anioLanzamiento, float precio, float calificacion) {
    if (buscar(isbn)) {
        cout << "Error: Libro con ISBN " << isbn << " ya existe.\n";
        return false;
    }

    NodoLibros* nuevo = new NodoLibros(titulo, autor, isbn, genero, anioLanzamiento, precio, calificacion);

    if (!cabeza) {
        cabeza = nuevo;
        cabeza->setSiguiente(cabeza);
        cabeza->setAnterior(cabeza);
    } else {
        NodoLibros* ultimo = cabeza->getAnterior();
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        nuevo->setSiguiente(cabeza);
        cabeza->setAnterior(nuevo);
    }
    guardarEnArchivo();
    return true;
}

NodoLibros* ListaLibros::buscar(string isbn) {
    if (!cabeza) return nullptr;

    NodoLibros* actual = cabeza;
    do {
        if (actual->getIsbn() == isbn) {
            return actual;
        }
        actual = actual->getSiguiente();
    } while (actual != cabeza);
    return nullptr;
}

bool ListaLibros::eliminar(string isbn) {
    NodoLibros* encontrado = buscar(isbn);
    if (!encontrado) {
        cout << "Error: Libro no encontrado.\n";
        return false;
    }

    if (encontrado->getSiguiente() == encontrado) {
        cabeza = nullptr;
    } else {
        NodoLibros* anterior = encontrado->getAnterior();
        NodoLibros* siguiente = encontrado->getSiguiente();
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

void ListaLibros::mostrar() {
    if (!cabeza) {
        cout << "Lista de libros vacía.\n";
        return;
    }

    NodoLibros* actual = cabeza;
    do {
        cout << "Título: " << actual->getTitulo()
             << ", Autor: " << actual->getAutor()
             << ", ISBN: " << actual->getIsbn()
             << ", Género: " << actual->getGenero()
             << ", Año de Lanzamiento: " << actual->getAnioLanzamiento()
             << ", Precio: " << actual->getPrecio()
             << ", Calificación: " << actual->getCalificacion() << "\n";
        actual = actual->getSiguiente();
    } while (actual != cabeza);
}

void ListaLibros::cargarDesdeArchivo() {
    ifstream archivo("libros.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de libros.\n";
        return;
    }

    string titulo, autor, isbn, genero;
    int anioLanzamiento;
    float precio, calificacion;

    while (getline(archivo, titulo) && 
           getline(archivo, autor) && 
           getline(archivo, isbn) && 
           getline(archivo, genero) && 
           archivo >> anioLanzamiento >> precio >> calificacion) {

        // Limpiar el buffer para capturar correctamente el salto de línea
        archivo.ignore(); 

        insertar(titulo, autor, isbn, genero, anioLanzamiento, precio, calificacion);
    }

    archivo.close();
}

void ListaLibros::guardarEnArchivo() {
    ofstream archivo("libros.txt", ios::trunc);
    if (!archivo.is_open()) return;

    NodoLibros* actual = cabeza;
    if (cabeza) {
        do {
            archivo << actual->getTitulo() << " "
                    << actual->getAutor() << " "
                    << actual->getIsbn() << " "
                    << actual->getGenero() << " "
                    << actual->getAnioLanzamiento() << " "
                    << actual->getPrecio() << " "
                    << actual->getCalificacion() << "\n";
            actual = actual->getSiguiente();
        } while (actual != cabeza);
    }
    archivo.close();
}

string ListaLibros::seleccionarAutor(ListaAutores& listaAutores) {
    cout << "Seleccione un autor de la lista:\n";
    listaAutores.mostrar();

    string cedula;
    cout << "Ingrese la cédula del autor: ";
    cin >> cedula;

    NodoAutores* autor = listaAutores.buscar(cedula);
    if (autor) {
        return autor->getNombre() + " " + autor->getApellido();
    } else {
        cout << "Error: Autor no encontrado.\n";
        return "";
    }
}
