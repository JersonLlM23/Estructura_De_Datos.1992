/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 22 de noviembre de 2024
 * TEMA: Lista simple
 * NRC: 1992
 *************************/
#include "Nodo.cpp"
#include "I_Lista_Simple.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <set>

class Lista_Simple : public I_Lista_Simple
{
public:
    Lista_Simple();
    ~Lista_Simple();

    void Insertar(string &N1, string &N2, string &Ape, int count, string &ID);
    void Eliminar(string &N1, string &N2, string &Ape);
    void Buscar(string &N1, string &N2, string &Ape);
    void Comprobar_existencia(string &N1, string &N2, string &Ape, int count, Nodo *nodo, string &ID);
    string crearCorreo(string &N1, string &N2, string &Ape, int count, string dominio = "espe.edu.ec");
    void guardarArchivo(const string &nombreArchivo) const;
    void Mostrar() const;
    bool validarCedula(string &cedula);
    bool cedulaExistente(const string &cedula);
    void agregarCedula(const string &cedula);
    void Password(Nodo *nodo) override;

private:
    Nodo *cabeza;
    set<string> cedulasIngresadas;
};
