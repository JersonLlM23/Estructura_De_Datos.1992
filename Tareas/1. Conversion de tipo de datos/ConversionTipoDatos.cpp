/***********************************************************************
 * Module:  ConversionTiposDatos.cpp
 * Author:  Jerson Llumiquinga M.
 * Date: 08/11/2024
 * Purpose: Conversion de tipo de datos
 * University: UNIVERSIDAD DE LAS FUERZAS ARMADAS - "ESPE"
 ***********************************************************************/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdexcept>
using namespace std;

char *ingresoDatos(int tipo);
int ingresarEntero(char *msj);
float ingresarFlotante(char *msj);
char *ingresarCadena(char *msj);

char *ingresoDatos(int tipo) {
    static char cad[50];
    char c;
    int i = 0;
    bool validacion = true;

    try {
        while ((c = getch()) != 13) {
            validacion = true;
            switch (tipo) {
                case 1:
                    if (c >= '0' && c <= '9') {
                        cad[i++] = c;
                        cout << c;
                        } else {
                        cout << "\nPor favor, ingrese solo numeros";
                        validacion = false;
                        }
                    break;

                case 2:
                    if ((c >= '0' && c <= '9') || c == '.') {
                        if (c == '.' && strchr(cad, '.')) {
                            validacion = false;
                        } else {
                            cad[i++] = c;
                            cout << c;
                            }
                    } else {
                        cout << "\nPor favor, solo ingrese numeros y un punto como maximo";
                        validacion = false;
                    }
                    break;

                case 3:
                    if (isalpha(c) || c == ' ') {
                        cad[i++] = c;
                        cout << c;
                    } else {
                        cout << "\nPor favor, solo ingresa texto";
                        validacion = false;
                    }
                    break;
            }

            if (!validacion) {
                throw invalid_argument("vuelve a ingresar correctamente:");
            }
        }
        cad[i] = '\0';
        return cad;
    } catch (const exception &e) {
        cout << "\n" << e.what();
        return ingresoDatos(tipo);
    }
}

int ingresarEntero(char *msj) {
    cout << msj;
    char cad1[50];
    int valor = atoi(strcpy(cad1, ingresoDatos(1)));
    cout << "\n";
    return valor;
}

float ingresarFlotante(char *msj) {
    cout << msj;
    char cad2[50];
    float valor = atof(strcpy(cad2, ingresoDatos(2)));
    cout << "\n";
    return valor;
}

char *ingresarCadena(char *msj) {
    cout << msj;
    static char cad3[50];
    strcpy(cad3, ingresoDatos(3));
    cout << "\n";
    return cad3;
}

int main() {
    cout << ingresarEntero("Ingrese un valor entero: ") << endl;
    cout << ingresarFlotante("Ingrese un valor flotante: ") << endl;
    cout << ingresarCadena("Ingrese una cadena de texto: ") << endl;

    return 0;
}
