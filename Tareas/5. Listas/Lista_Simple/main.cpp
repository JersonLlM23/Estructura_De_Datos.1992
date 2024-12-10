/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 22 de noviembre de 2024
 * TEMA: Lista simple
 * NRC: 1992
 *************************/
#include "Lista_Simple.cpp"
#include <iostream>
#include <string>

using namespace std;

int menu()
{
    int opcion;
    cout << "\n--- Menú ---" << endl;
    cout << "1. Insertar Nodo" << endl;
    cout << "2. Eliminar Nodo" << endl;
    cout << "3. Buscar Nodo" << endl;
    cout << "4. Mostrar Lista" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese su opción: ";

    while (!(cin >> opcion))
    {
        cout << "Opción inválida. Por favor, ingrese un número: ";
        cin.clear();
        cin.ignore(123, '\n');
    }

    return opcion;
}

int main()
{
    Lista_Simple lista;
    int count = 0;

    int opcion;
    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 1:
        {
            string nombre1, nombre2, ape, id;
            nombre1 = ingresarLetras("Ingrese el primer nombre");
            nombre2 = ingresarLetras("Ingrese el segundo nombre");
            ape = ingresarLetras("Ingrese el apellido");
            id = ingresarNumeros("Ingrese la cédula");
            while (!lista.validarCedula(id))
            {
                cout << "Ingrese una cédula válida: ";
                id = ingresarNumeros("Ingrese la cédula");
            }
            lista.Insertar(nombre1, nombre2, ape, count, id);
            break;
        }
        case 2:
        {
            string nombre1, nombre2, ape;
            cout << "Ingrese el primer nombre del nodo a eliminar: ";
            cin >> nombre1;
            cout << "Ingrese el segundo nombre del nodo a eliminar: ";
            cin >> nombre2;
            cout << "Ingrese el apellido del nodo a eliminar: ";
            cin >> ape;
            lista.Eliminar(nombre1, nombre2, ape);
            break;
        }
        case 3:
        {
            string nombre1, nombre2, ape;
            cout << "Ingrese el primer nombre del nodo a buscar: ";
            cin >> nombre1;
            cout << "Ingrese el segundo nombre del nodo a buscar: ";
            cin >> nombre2;
            cout << "Ingrese el apellido del nodo a buscar: ";
            cin >> ape;
            lista.Buscar(nombre1, nombre2, ape);
            break;
        }
        case 4:
            cout << "Lista actual: ";
            lista.Mostrar();
            break;
        case 5:
            cout << "Saliendo del programa...." << endl;
            break;
        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
            break;
        }
    } while (opcion != 6);

    return 0;
}
