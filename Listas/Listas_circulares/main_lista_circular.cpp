#include <iostream>
#include <stdlib.h>
#include "Lista_Simple.h"

using namespace std;

int main() {
    // Instanciamos las listas circulares
    Lista_Simple<int>* lista_id = new Lista_Simple<int>();
    Lista_Simple<std::string>* lista_nombre = new Lista_Simple<std::string>();
    Lista_Simple<std::string>* lista_apellido = new Lista_Simple<std::string>();

    int opcion, dato_id;
    std::string dato_nombre, dato_apellido;
    char caracter;

    do {
        system("cls");
        cout << "*********** Listas Circulares ***********" << endl;
        cout << "1. Lista de ID (int)" << endl;
        cout << "2. Lista de Nombre (string)" << endl;
        cout << "3. Lista de Apellido (string)" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:  // Manejo de lista de ID
            do {
                system("cls");
                cout << "*********** Lista de ID ***********" << endl;
                cout << "1. Insertar" << endl;
                cout << "2. Buscar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Mostrar" << endl;
                cout << "5. Salir" << endl;
                cout << "Ingrese una opción: ";
                cin >> opcion;

                switch (opcion) {
                case 1:
                    cout << "Ingrese el ID a insertar: ";
                    cin >> dato_id;
                    lista_id->Insertar_cabeza(dato_id);
                    cout << "ID ingresado correctamente." << endl;
                    system("pause");
                    break;
                case 2:
                    cout << "Ingrese el ID a buscar: ";
                    cin >> dato_id;
                    lista_id->Buscar(dato_id);
                    system("pause");
                    break;
                case 3:
                    cout << "Ingrese el ID a eliminar: ";
                    cin >> dato_id;
                    lista_id->Eliminar(dato_id);
                    system("pause");
                    break;
                case 4:
                    lista_id->Mostrar();
                    system("pause");
                    break;
                }
            } while (opcion != 5);
            break;

        case 2:  // Manejo de lista de Nombre
        case 3: {  // Manejo de lista de Apellido
            Lista_Simple<std::string>* lista = (opcion == 2) ? lista_nombre : lista_apellido;
            string tipo = (opcion == 2) ? "Nombre" : "Apellido";

            do {
                system("cls");
                cout << "*********** Lista de " << tipo << " ***********" << endl;
                cout << "1. Insertar" << endl;
                cout << "2. Buscar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Mostrar" << endl;
                cout << "5. Eliminar un caracter" << endl;
                cout << "6. Salir" << endl;
                cout << "Ingrese una opción: ";
                cin >> opcion;

                switch (opcion) {
                case 1:
                    cout << "Ingrese el " << tipo << " a insertar: ";
                    cin.ignore();  // Para limpiar el buffer de entrada
                    getline(cin, dato_nombre);
                    lista->Insertar_cabeza(dato_nombre);
                    cout << tipo << " ingresado correctamente." << endl;
                    system("pause");
                    break;
                case 2:
                    cout << "Ingrese el " << tipo << " a buscar: ";
                    cin.ignore();
                    getline(cin, dato_nombre);
                    lista->Buscar(dato_nombre);
                    system("pause");
                    break;
                case 3:
                    cout << "Ingrese el " << tipo << " a eliminar: ";
                    cin.ignore();
                    getline(cin, dato_nombre);
                    lista->Eliminar(dato_nombre);
                    system("pause");
                    break;
                case 4:
                    lista->Mostrar();
                    system("pause");
                    break;
                case 5:
                    cout << "Ingrese el caracter a eliminar: ";
                    cin >> caracter;
                    lista->EliminarCaracter(caracter);
                    system("pause");
                    break;
                }
            } while (opcion != 6);
            break;
        }

        case 4:
            cout << "Gracias por usar el programa." << endl;
            break;

        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
            system("pause");
            break;
        }
    } while (opcion != 4);

    return 0;
}
