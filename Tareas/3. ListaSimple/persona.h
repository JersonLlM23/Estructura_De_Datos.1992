/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * ALUMNO:  Jerson Llumiquinga M.
 * FECHA CREACION: 22 de noviembre de 2024
 * TEMA: Lista simple
 * NRC: 1992
 *************************/
#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona {
private:
    string cedula;
    string apellido;
    string nombre;

public:
    // Constructor
    Persona(string cedula, string apellido, string nombre);

    // Getters
    string getCedula() const;
    string getApellido() const;
    string getNombre() const;

    // Setters
    void setCedula(string cedula);
    void setApellido(string apellido);
    void setNombre(string nombre);
};

#endif
