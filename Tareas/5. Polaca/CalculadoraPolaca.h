/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 23 de noviembre de 2024
 * TEMA: Calculadora Polaca
 * NRC: 1992
 *************************/
#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <string>

class Calculadora {
public:
    static bool esOperador(char c);
    static int obtenerPrecedencia(char op);
    static std::string infijaAPosfija(const std::string &infijo);
    static std::string infijaAPrefija(const std::string &infijo);
    static bool esExpresionValida(const std::string &expresion);
};

#endif // CALCULADORA_H
