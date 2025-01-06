#include <chrono>
#include <ctime>
#include <iostream>

class Fecha {
private:
    std::time_t tiempo;

public:
    Fecha(); // Constructor por defecto
    Fecha(int day, int month, int year); // Constructor con parámetros
    Fecha(std::time_t tiempo);
    const std::time_t& getTiempo() const;
    void setTiempo(int day, int month, int year);
    void setTiempo(const std::time_t& nuevoTiempo);

    friend std::ostream& operator<<(std::ostream& os, const Fecha& fecha);
};
