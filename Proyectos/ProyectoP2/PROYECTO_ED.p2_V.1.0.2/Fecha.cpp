#include "Fecha.hpp"

Fecha::Fecha(int day, int month, int year) {
    struct tm datetime = {};
    datetime.tm_year = year - 1900; // Ajustar el año (desde 1900)
    datetime.tm_mon = month - 1;    // Ajustar el mes (0-11)
    datetime.tm_mday = day;
    datetime.tm_hour = 0;
    datetime.tm_min = 0;
    datetime.tm_sec = 0;

    tiempo = mktime(&datetime);
}

Fecha::Fecha() : tiempo(std::time(nullptr)) {}

Fecha::Fecha(std::time_t tiempo) : tiempo(tiempo) {}

const time_t& Fecha::getTiempo() const {
    return tiempo;
}

void Fecha::setTiempo(int day, int month, int year) {
    struct tm datetime = {};
    datetime.tm_year = year - 1900;
    datetime.tm_mon = month - 1;
    datetime.tm_mday = day;
    datetime.tm_hour = 0;
    datetime.tm_min = 0;
    datetime.tm_sec = 0;

    tiempo = mktime(&datetime);
}

void Fecha::setTiempo(const std::time_t& nuevoTiempo) {
    tiempo = nuevoTiempo;
}

// Obtener el año de la fecha almacenada
int Fecha::getAnio() const {
    struct tm* timeinfo = localtime(&tiempo);
    return 1900 + timeinfo->tm_year; // Devolver el año
}

std::ostream& operator<<(std::ostream& os, const Fecha& fecha) {
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &fecha.tiempo); // Formatear la fecha
    os << buffer;
    return os;
}
