#pragma once
#include "NodoLibros.h"
#include "ListaAutores.h"
#include <string>
#include <fstream>
using namespace std;

class ListaLibros {
private:
    NodoLibros* cabeza;

public:
    ListaLibros();
    ~ListaLibros();

    bool insertar(string titulo, string autor, string isbn, string genero, int anioLanzamiento, float precio, float calificacion);
    NodoLibros* buscar(string isbn);
    bool eliminar(string isbn);
    void mostrar();
    void cargarDesdeArchivo();
    void guardarEnArchivo();
    string seleccionarAutor(ListaAutores& listaAutores);
};
