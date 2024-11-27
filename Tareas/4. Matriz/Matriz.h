#ifndef MATRIZ_H
#define MATRIZ_H
#define MAX 3

template <typename T>
class Matriz {

private:
    T matriz[MAX][MAX];

public:
    Matriz();
    // Getter para obtener el valor de un elemento en la matriz
    T getElemento(int fila, int col);
    // Setter para establecer el valor de un elemento en la matriz
    void setElemento(int fila, int col, T valor);
    void imprimirMatriz();
    T sumaRecursivaMatrices(Matriz<T>& mat1, Matriz<T>& mat2, int f, int c);
};
#endif
