/***********************************************************************
 * Module:  Matriz.h
 * Author:  Maycol Celi
 * Date: 14/11/2024
 * University: Universidad de las Fuerzas Armadas - ESPE
 ***********************************************************************/
#ifndef MATRIZ_H
#define MATRIZ_H

#define MAX 3

template <typename T>
class Matriz {
private:
    T matriz[MAX][MAX]; // Matriz 3x3 de tipo genérico

public:
    // Constructor para inicializar la matriz con valores aleatorios
    Matriz();

    // Getter para obtener el valor de un elemento en la matriz
    T getElemento(int fila, int col);

    // Setter para establecer el valor de un elemento en la matriz
    void setElemento(int fila, int col, T valor);

    // Método para imprimir la matriz
    void imprimirMatriz();

    // Método recursivo para sumar dos matrices
    T sumaRecursivaMatrices(Matriz<T>& mat1, Matriz<T>& mat2, int f, int c);
};

#endif // MATRIZ_H
