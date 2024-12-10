/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 22 de noviembre de 2024
 * TEMA: Lista simple
 * NRC: 1992
 *************************/
#include "Lista_Simple.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

Lista_Simple::Lista_Simple() : cabeza(nullptr) {}

Lista_Simple::~Lista_Simple()
{
    while (cabeza != nullptr)
    {
        Nodo *temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
    }
}

void Lista_Simple::Insertar(string &N1, string &N2, string &Ape, int count, string &ID)
{
    Nodo *nuevoNodo = new Nodo(N1, N2, Ape, ID);
    if (cabeza == nullptr)
    {
        cabeza = nuevoNodo;
    }
    else
    {
        Nodo *actual = cabeza;
        while (actual->getSiguiente() != nullptr)
        {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevoNodo);
    }
    Comprobar_existencia(N1, N2, Ape, count, nuevoNodo, ID);
    Password(nuevoNodo);
}

bool Lista_Simple::validarCedula(string &cedula)
{
    if (cedula.length() != 10)
    {
        return false;
    }

    for (char c : cedula)
    {
        if (!isdigit(c))
        {
            cout << "Ingrese solo numeros";
            return false;
        }
    }

    int suma = 0;
    for (int i = 0; i < 9; i++)
    {
        int digito = cedula[i] - '0';
        if (i % 2 == 0)
        {
            digito *= 2;
            if (digito > 9)
            {
                digito -= 9;
            }
        }
        suma += digito;
    }

    int digitoVerificador = cedula[9] - '0';
    int resultado = 10 - (suma % 10);
    if (resultado == 10)
    {
        resultado = 0;
    }

    return digitoVerificador == resultado;
}

void Lista_Simple::Comprobar_existencia(string &N1, string &N2, string &Ape, int count, Nodo *nodo, string &ID)
{
    count = -1;
    Nodo *actual = cabeza;

    while (actual != nullptr)
    {
        if (actual->getNombre1() == N1 && actual->getNombre2() == N2 && actual->getApellido() == Ape)
        {
            count++;
        }
        actual = actual->getSiguiente();
    }

    if (cedulaExistente(ID))
    {
        cout << "La cédula ya ha sido ingresada anteriormente." << endl;
        cin >> ID;
    }
    else
    {
        agregarCedula(ID);
    }

    string correo = crearCorreo(N1, N2, Ape, count, "espe.edu.ec");
    nodo->setCorreo(correo);
}

bool Lista_Simple::cedulaExistente(const string &cedula)
{
    return cedulasIngresadas.find(cedula) != cedulasIngresadas.end();
}

void Lista_Simple::agregarCedula(const string &cedula)
{
    cedulasIngresadas.insert(cedula);
}

string Lista_Simple::crearCorreo(string &N1, string &N2, string &Ape, int count, string dominio)
{
    if (N1.empty() || N2.empty() || Ape.empty())
    {
        cerr << "Error: Los nombres y el apellido no deben estar vacíos" << endl;
    }

    char inicialN1 = tolower(N1[0]);
    char inicialN2 = tolower(N2[0]);

    string apellidoMinusculas = Ape;
    transform(apellidoMinusculas.begin(), apellidoMinusculas.end(), apellidoMinusculas.begin(), ::tolower);
    string correo;
    if (count <= 0)
    {
        correo = string(1, inicialN1) + string(1, inicialN2) + apellidoMinusculas + "@" + dominio;
    }
    else
    {
        correo = string(1, inicialN1) + string(1, inicialN2) + apellidoMinusculas + to_string(count) + "@" + dominio;
    }

    return correo;
}

char *ingresarLetras(const char *msj)
{
    static char dato[25];
    char c;
    int i = 0;
    cout << msj << ": ";

    while ((c = _getch()) != 13)
    {
        if (isalpha(c))
        {
            dato[i++] = c;
            cout << c;
        }
    }

    dato[i] = '\0';
    cout << endl;
    return dato;
}

char *ingresarNumeros(const char *msj)
{
    static char dato[25];
    char c;
    int i = 0;
    cout << msj << ": ";
    while ((c = _getch()) != 13)
    {
        if (c >= '0' && c <= '9')
        {
            dato[i++] = c;
            cout << c;
        }
    }
    dato[i] = '\0';
    cout << endl;
    return dato;
}

string cifradoCesar(const string &texto, int desplazamiento)
{
    string resultado = texto;

    for (char &c : resultado)
    {
        if (isalpha(c))
        {
            char limite = isupper(c) ? 'A' : 'a';
            int nuevaPosicion = c - limite + desplazamiento;

            if (nuevaPosicion >= 26)
            {
                nuevaPosicion -= 26;
            }
            else if (nuevaPosicion < 0)
            {
                nuevaPosicion += 26;
            }

            c = limite + nuevaPosicion;
        }
    }

    return resultado;
}

void Lista_Simple::Password(Nodo *nodo)
{
    string N1 = nodo->getNombre1();
    string N2 = nodo->getNombre2();
    string Ape = nodo->getApellido();

    char ultimaLetraApe = tolower(Ape.back());
    char primeraLetraN1 = tolower(N1.front());
    char ultimaLetraN2 = tolower(N2.back());
    string apellidoInverso = Ape.substr(0, Ape.length() - 1);
    reverse(apellidoInverso.begin(), apellidoInverso.end());
    string concatenacion = string(1, ultimaLetraApe) + primeraLetraN1 + ultimaLetraN2 + apellidoInverso;
    cout << concatenacion << endl;
    int desplazamiento = 2;
    string password = cifradoCesar(concatenacion, desplazamiento);

    cout << "Contraseña generada: " << password << endl;
}

void Lista_Simple::Eliminar(string &N1, string &N2, string &Ape)
{
    Nodo *actual = cabeza;
    Nodo *anterior = nullptr;

    while (actual != nullptr)
    {
        if (actual->getNombre1() == N1 && actual->getNombre2() == N2 && actual->getApellido() == Ape)
        {
            if (anterior != nullptr)
            {
                anterior->setSiguiente(actual->getSiguiente());
            }
            else
            {
                cabeza = actual->getSiguiente();
            }
            delete actual;
            cout << "Nodo eliminado" << endl;
            cout << "Correo del nodo eliminado: " << endl;
            return;
        }
        anterior = actual;
        actual = actual->getSiguiente();
    }
    cout << "Nodo no encontrado para eliminar" << endl;
}

void Lista_Simple::Buscar(string &N1, string &N2, string &Ape)
{
    Nodo *actual = cabeza;
    while (actual != nullptr)
    {
        if (actual->getNombre1() == N1 && actual->getNombre2() == N2 && actual->getApellido() == Ape)
        {
            cout << "Nodo encontrado:\n"
                 << "Nombre1 = " << actual->getNombre1()
                 << ", Nombre2 = " << actual->getNombre2()
                 << ", Apellido = " << actual->getApellido()
                 << ", Correo = " << actual->getCorreo()
                 << endl;
            return;
        }
        actual = actual->getSiguiente();
    }
    cout << "Nodo no encontrado" << endl;
}

void Lista_Simple::guardarArchivo(const string &nombreArchivo) const
{
    ofstream archivo(nombreArchivo, std::ios::app); // Abrir en modo "append"
    if (!archivo)
    {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    Nodo *actual = cabeza;
    while (actual != nullptr)
    {
        archivo << "Nombre1: " << actual->getNombre1()
                << ", Nombre2: " << actual->getNombre2()
                << ", Apellido: " << actual->getApellido()
                << ", Correo: " << actual->getCorreo()
                << ", Cedula: " << actual->getCedula()
                << endl;
        actual = actual->getSiguiente();
    }

    archivo.close();
    cout << "Datos guardados en el archivo: " << nombreArchivo << endl;
}

void Lista_Simple::Mostrar() const
{
    Nodo *actual = cabeza;
    while (actual != nullptr)
    {
        cout << "Nombre1: " << actual->getNombre1()
             << ", Nombre2: " << actual->getNombre2()
             << ", Apellido: " << actual->getApellido()
             << " -> ";
        actual = actual->getSiguiente();
    }
    cout << "nullptr" << endl;
}