/***********************************************************************
 * Module:  main.cpp
 * Author:  Maycol Celi,Erika Guayanay, Jerson Llumiquinga M.
 * Date: 25/11/2024
 * Purpose: Lista de Personas con Listas Circulares
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/

#include "ListasCirculares.h"
#include <iostream>
#include <regex>
using namespace std;

bool validarCedula(string cedula) {
    return regex_match(cedula, regex("\\d{10}"));
}

bool validarSoloLetras(string texto) {
    return regex_match(texto, regex("[A-Za-z ]+"));
}

int main() {
    ListaCircular lista;
    string cedula, nombre, apellido;
    char caracter;
    int opcion;

    do {
        cout << "\n*** Menu de opciones ***\n";
        cout << "1. Insertar persona\n";
        cout << "2. Buscar persona\n";
        cout << "3. Eliminar persona\n";
        cout << "4. Mostrar lista\n";
        cout << "5. Eliminar caracter\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese cedula (10 dígitos): ";
                cin >> cedula;
                if (!validarCedula(cedula)) {
                    cout << "Error: La cedula debe contener 10 digitos.\n";
                    break;
                }
                cout << "Ingrese nombre: ";
                cin >> nombre;
                if (!validarSoloLetras(nombre)) {
                    cout << "Error: El nombre debe contener solo letras.\n";
                    break;
                }
                cout << "Ingrese apellido: ";
                cin >> apellido;
                if (!validarSoloLetras(apellido)) {
                    cout << "Error: El apellido debe contener solo letras.\n";
                    break;
                }
                lista.insertar(cedula, nombre, apellido);
                break;

            case 2:
                cout << "Ingrese cedula a buscar: ";
                cin >> cedula;
                if (lista.buscar(cedula) != nullptr) {
                    Nodo* encontrado = lista.buscar(cedula);
                    cout << "Persona encontrada: <Cedula: " << encontrado->getCedula()
                         << ", Nombre: " << encontrado->getNombre()
                         << ", Apellido: " << encontrado->getApellido() << ">\n";
                } else {
                    cout << "Persona no encontrada.\n";
                }
                break;

            case 3:
                cout << "Ingrese cedula a eliminar: ";
                cin >> cedula;
                if (lista.eliminar(cedula)) {
                    cout << "Persona eliminada correctamente.\n";
                } else {
                    cout << "Error: Persona no encontrada.\n";
                }
                break;

            case 4:
                cout << "\nLista de personas:\n";
                lista.mostrar();
                break;

            case 5:
                cout << "Ingrese cedula de la persona: ";
                cin >> cedula;
                cout << "Ingrese caracter a eliminar: ";
                cin >> caracter;
                lista.eliminarCaracter(cedula, caracter);
                break;

            case 6:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no valida. Por favor, intente nuevamente.\n";
        }
    } while (opcion != 6);

    return 0;
}
