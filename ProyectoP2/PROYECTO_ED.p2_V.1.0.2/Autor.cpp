#include "Autor.hpp"

Autor::Autor(const std::string& cedula, const std::string& nombre, const std::string& nombre2, const std::string& apellido)
    : cedula(cedula), nombre(nombre), nombre2(nombre2), apellido(apellido) {
}

Autor::Autor(const std::string& id, const std::string& nombre)
    : cedula(id), nombre(nombre), nombre2(""), apellido("") {}

const std::string& Autor::getId() const {
    return cedula;
}

const std::string& Autor::getNombre() const {
    return nombre;
}

const std::string& Autor::getNombre2() const {
    return nombre2;
}

const std::string& Autor::getApellido() const {
    return apellido;
}

void Autor::setId(const std::string& nuevoId) {
    cedula = nuevoId;
}

void Autor::setNombre(const std::string& nuevoNombre) {
    nombre = nuevoNombre;
}

void Autor::setNombre2(const std::string& nuevoNombre2) {
    nombre2 = nuevoNombre2;
}

void Autor::setApellido(const std::string& nuevoApellido) {
    apellido = nuevoApellido;
}

bool Autor::operator==(const Autor& otroAutor) const {
    return cedula == otroAutor.cedula;
}

std::ostream& operator<<(std::ostream& os, const Autor& autor) {
    os << "Id: " << autor.cedula << ", Nombre: " << autor.nombre << ", Apellido: " << autor.apellido << ", Libros:\n";
    autor.libros.print(); // Llama a la función print del árbol B
    return os;
}
