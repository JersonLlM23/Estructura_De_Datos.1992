#pragma once
#include <string>
using namespace std;

class NodoLibros {
private:
    string titulo;
    string autor;
    string isbn;
    string genero;
    int anioLanzamiento;
    float precio;
    float calificacion;
    NodoLibros* siguiente;
    NodoLibros* anterior;

public:
    NodoLibros(string, string, string, string, int, float, float);
    string getTitulo();
    string getAutor();
    string getIsbn();
    string getGenero();
    int getAnioLanzamiento();
    float getPrecio();
    float getCalificacion();
    NodoLibros* getSiguiente();
    NodoLibros* getAnterior();
    void setSiguiente(NodoLibros*);
    void setAnterior(NodoLibros*);
};
