/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 29 de noviembre de 2024
 * TEMA: Sumando elementos de las matrices usando plantillas
 * NRC: 1992
 *************************/
#include "Calculadora.h"
#include <algorithm>
#include <stdexcept>

int Calculadora::obtenerPrecedencia(char operador)
{
    if (operador == '+' || operador == '-')
        return 1;
    if (operador == '*' || operador == '/')
        return 2;
    return 0;
}

bool Calculadora::esOperador(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string Calculadora::infijoAPostfijo(const string &expresion)
{
    stack<char> pila;
    string resultado;

    for (char c : expresion)
    {
        if (isalnum(c))
        {
            resultado += c;
        }
        else if (c == '(')
        {
            pila.push(c);
        }
        else if (c == ')')
        {
            while (!pila.empty() && pila.top() != '(')
            {
                resultado += pila.top();
                pila.pop();
            }
            pila.pop(); // Quitar '('
        }
        else if (esOperador(c))
        {
            while (!pila.empty() && obtenerPrecedencia(pila.top()) >= obtenerPrecedencia(c))
            {
                resultado += pila.top();
                pila.pop();
            }
            pila.push(c);
        }
    }

    while (!pila.empty())
    {
        resultado += pila.top();
        pila.pop();
    }

    return resultado;
}

string Calculadora::infijoAPrefijo(const string &expresion)
{
    string expresionReversa = expresion;
    reverse(expresionReversa.begin(), expresionReversa.end());

    for (char &c : expresionReversa)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    string postfijo = infijoAPostfijo(expresionReversa);
    reverse(postfijo.begin(), postfijo.end());

    return postfijo;
}

string Calculadora::postfijoAInfijo(const string &expresion)
{
    stack<string> pila;

    for (char c : expresion)
    {
        if (isalnum(c))
        {
            pila.push(string(1, c));
        }
        else if (esOperador(c))
        {
            string op2 = pila.top();
            pila.pop();
            string op1 = pila.top();
            pila.pop();
            string subExpresion = "(" + op1 + c + op2 + ")";
            pila.push(subExpresion);
        }
    }

    return pila.top();
}

string Calculadora::prefijoAInfijo(const string &expresion)
{
    stack<string> pila;

    for (auto it = expresion.rbegin(); it != expresion.rend(); ++it)
    {
        char c = *it;

        if (isalnum(c))
        {
            pila.push(string(1, c));
        }
        else if (esOperador(c))
        {
            string op1 = pila.top();
            pila.pop();
            string op2 = pila.top();
            pila.pop();
            string subExpresion = "(" + op1 + c + op2 + ")";
            pila.push(subExpresion);
        }
    }

    return pila.top();
}

string Calculadora::convertir(int opcion, const string &expresion)
{
    switch (opcion)
    {
    case 1:
        return infijoAPrefijo(expresion);
    case 2:
        return infijoAPostfijo(expresion);
    case 3:
        return postfijoAInfijo(expresion);
    case 4:
        return prefijoAInfijo(expresion);
    default:
        throw runtime_error("Opción inválida.");
    }
}
