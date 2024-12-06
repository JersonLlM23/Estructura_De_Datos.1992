#pragma once
#include "NodoAutores.h"
#include <string>
#include <fstream>
using namespace std;

class ListaAutores {
private:
    NodoAutores* cabeza;

public:
    ListaAutores();
    ~ListaAutores();

    bool insertar(string cedula, string nombre, string apellido, string fechaPublicacion);
    NodoAutores* buscar(string cedula);
    bool eliminar(string cedula);
    void mostrar();
    void cargarDesdeArchivo();
    void guardarEnArchivo();
};
