
/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 22 de noviembre de 2024
 * TEMA: Sumando elementos de las matrices usando plantillas
 * NRC: 1992
 *************************/
#include <iostream>
#include <conio.h>

using namespace std;

template<typename T>
class Validation
{
private:
    T data;
public:
    Validation();
    
    T enter_a_number(char *data_type);
    T enter_a_char_or_string_with_may(int data_size);
    T enter_a_char_or_string(int data_size);
    T data_convertion_to_number(char *cad, char *data_type);
    T primera_letra_a_mayuscula();
};


