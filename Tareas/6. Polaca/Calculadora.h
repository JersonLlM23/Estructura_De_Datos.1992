/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 29 de noviembre de 2024
 * TEMA: Sumando elementos de las matrices usando plantillas
 * NRC: 1992
 *************************/
#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <string>
#include <stack>
#include <queue>

using namespace std;

class Calculadora
{
private:
    int obtenerPrecedencia(char operador); 
    bool esOperador(char c);               

    string infijoAPostfijo(const string &expresion);
    string infijoAPrefijo(const string &expresion);
    string postfijoAInfijo(const string &expresion);
    string prefijoAInfijo(const string &expresion);

public:
    string convertir(int opcion, const string &expresion); 
};

#endif 
