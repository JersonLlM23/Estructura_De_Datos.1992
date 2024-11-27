#pragma once
#include "Nodo.h"

using namespace std;

class ListaDoble {
private:
    Nodo* primero;
    Nodo* ultimo;
public:
    ListaDoble();
    ~ListaDoble();
    void insertar(string, string, string);
    Nodo* buscar(string);
    bool eliminar(string);
    void mostrar();
    void eliminarCaracter(string, char);
    bool validarCedulaUnica(string);
};
