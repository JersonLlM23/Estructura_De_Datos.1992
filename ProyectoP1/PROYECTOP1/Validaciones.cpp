#include "Validaciones.h"
#include <regex>

// Valida que una cédula sea correcta (formato y lógica)
bool validarCedula(const string& cedula) {
    if (cedula.length() != 10) return false;
    if (!regex_match(cedula, regex("\\d{10}"))) return false;

    int suma = 0;
    for (int i = 0; i < 9; i++) {
        int digito = cedula[i] - '0';
        if (i % 2 == 0) {
            digito *= 2;
            if (digito > 9) digito -= 9;
        }
        suma += digito;
    }

    int ultimoDigito = cedula[9] - '0';
    int decenaSuperior = (suma + 9) / 10 * 10;
    return ultimoDigito == (decenaSuperior - suma);
}

// Valida que un texto contenga solo letras (incluye espacios)
bool validarTexto(const string& texto) {
    return regex_match(texto, regex("^[a-zA-ZáéíóúÁÉÍÓÚñÑ ]+$"));
}

// Valida que un string represente un número entero válido
bool validarEntero(const string& numero) {
    return regex_match(numero, regex("^-?\\d+$"));
}

// Valida que un string represente un número flotante válido
bool validarFlotante(const string& numero) {
    return regex_match(numero, regex("^-?\\d*\\.?\\d+$"));
}
