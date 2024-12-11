/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 22 de noviembre de 2024
 * TEMA: Lista doblemente enlazada
 * NRC: 1992
 *************************/
#include "Lista_Doble.cpp"
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
        if (std::cin.fail())
        {
            std::cout << "No se ha ingresado un numero " << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }

        cout << "Opción inválida. Por favor, ingrese un número: ";
        cin.clear();
    }

    return opcion;
}

int main()
{
    Lista_Doble lista;
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
            lista.agregarCedula(id);
            nombre1 = ingresarLetras("Ingrese el primer nombre");
            nombre2 = ingresarLetras("Ingrese el segundo nombre");
            ape = ingresarLetras("Ingrese el apellido");
            id = ingresarNumeros("Ingrese la cedula");
            while (lista.validarCedula(id) == false)
            {
                cout << "Ingrese una cedula valida: ";
                id = ingresarNumeros("Ingrese la cedula");
            }
            lista.Insertar(nombre1, nombre2, ape, count, id);
            Passord(nombre1, nombre2, ape);
            break;
        }
        case 2:
        {
            string nombre1, nombre2, ape;
            cout << "Ingrese el primer nombre del nuevo nodo: ";
            cin >> nombre1;
            cout << "Ingrese el segundo nombre del nuevo nodo: ";
            cin >> nombre2;
            cout << "Ingrese el apellido del nuevo nodo: ";
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
        }
    } while (opcion != 5);

    return 0;
}
