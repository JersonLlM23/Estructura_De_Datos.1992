/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 29 de noviembre de 2024
 * TEMA: Sumando elementos de las matrices usando plantillas
 * NRC: 1992
 *************************/
#include "Calculadora.cpp"
#include <iostream>

using namespace std;

int main()
{
    Calculadora calculadora;
    string expresion;
    int opcion;

    cout << "Conversor de Notación Matemática" << endl;
    cout << "Opciones disponibles:" << endl;
    cout << "1. Infijo a Prefijo" << endl;
    cout << "2. Infijo a Postfijo" << endl;
    cout << "3. Postfijo a Infijo" << endl;
    cout << "4. Prefijo a Infijo" << endl;
    cout << "5. Salir" << endl;

    while (true)
    {
        cout << "\nSeleccione una opción (1-5): ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 5)
        {
            cout << "Saliendo del programa..." << endl;
            break;
        }

        cout << "Introduzca la expresión: ";
        getline(cin, expresion);

        try
        {
            string resultado = calculadora.convertir(opcion, expresion);
            cout << "Resultado: " << resultado << endl;
        }
        catch (const runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    return 0;
}
