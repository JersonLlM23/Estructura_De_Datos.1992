#include "Autor.hpp"

Autor::Autor(std::string cedula, std::string nombre, std::string nombre2, std::string apellido)
    : cedula(cedula), nombre(nombre), nombre2(nombre2), apellido(apellido), libros(3) // Inicializamos el BTree con grado m�nimo 3
{
}

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
    autor.libros.print(); // Llama a la funci�n print del �rbol B
    return os;
}
