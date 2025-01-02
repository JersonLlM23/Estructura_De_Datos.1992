#pragma once

#include<string>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#include <conio.h> // Para Windows
#else
#include <termios.h>
#include <unistd.h>
int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

class Validaciones
{
public:

    static int leerEntero();
    static float leerFloat();
    static double leerDouble();
    static char leerLetra();
    static std::string leerPalabra();

    static std::string leerCedula();
    static std::string leerNumero();
    static bool validarCedula(std::string cedula);
    static std::string leerLinea();

};