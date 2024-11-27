/***********************************************************************
 * Module:  main.cpp
 * Author:  Maycol Celi,Erika Guayanay, Jerson Llumiquinga M.
 * Date: 22/11/2024
 * Purpose: Lista de Personas con Listas Circulares
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/
#include "ListasDoble.h"
#include "Validaciones.h"
#include <iostream>
using namespace std;


int main() {
    ListaDoble lista;
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
            case 1: {
                long int cedulaNumerica = ingresarCedula();
                if (!validarCedulaReal(cedulaNumerica)) {
                    imprimirResultadoCedula(false);
                    break;
                }
                imprimirResultadoCedula(true);
                cout << "Ingrese nombre: ";
                cin >> nombre;
                if (!validarTexto(nombre)) {
                    cout << "Error: El nombre debe contener solo letras.\n";
                    break;
                }
                cout << "Ingrese apellido: ";
                cin >> apellido;
                if (!validarTexto(apellido)) {
                    cout << "Error: El apellido debe contener solo letras.\n";
                    break;
                }
                lista.insertar(to_string(cedulaNumerica), nombre, apellido);
                break;
            }

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
        system("pause");
    } while (opcion != 6);

    return 0;
}
