/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 22 de noviembre de 2024
 * TEMA: Lista doblemente enlazada
 * NRC: 1992
 *************************/
#include "Nodo.cpp"
#include <string>
#include <algorithm>
#include <cctype>
#include <set>

class Lista_Doble
{
public:
    Lista_Doble();
    ~Lista_Doble();

    void Insertar(string &N1, string &N2, string &Ape, int count, string &ID);
    void Eliminar(string &N1, string &N2, string &Ape);
    void Buscar(string &N1, string &N2, string &Ape);
    void Comprobar_existencia(string &N1, string &N2, string &Ape, int count, Nodo *nodo, string &ID);
    string crearCorreo(string &N1, string &N2, string &Ape, int count, string dominio = "espe.edu.ec");
    void Mostrar() const;
    bool validarCedula(string &cedula);
    bool cedulaExistente(const string &cedula);
    void agregarCedula(const string &cedula);

private:
    Nodo *cabeza;
    Nodo *cola;
    set<string> cedulasIngresadas;
};
