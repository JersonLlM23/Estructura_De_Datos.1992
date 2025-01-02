#pragma once

#include "BTree.hpp"
#include "Libro.hpp"
#include <string>
#include <iostream>

class Autor {
private:
    std::string cedula;
    std::string nombre;
    std::string nombre2;
    std::string apellido;

public:
    BTree<Libro*> libros;

public:
    Autor() : cedula(""), nombre(""), nombre2(""), apellido("") {}
    Autor(const std::string& cedula, const std::string& nombre, const std::string& nombre2, const std::string& apellido);
    Autor(const std::string& id, const std::string& nombre); // Declaración del constructor adicional

    const std::string& getId() const;
    const std::string& getNombre() const;
    const std::string& getNombre2() const;
    const std::string& getApellido() const;
    void setId(const std::string& nuevoId);
    void setNombre(const std::string& nuevoNombre);
    void setNombre2(const std::string& nuevoNombre2);
    void setApellido(const std::string& nuevoApellido);

    bool operator==(const Autor& otroAutor) const;

    // Operadores para comparar autores
    bool operator<(const Autor& otro) const {
        return cedula < otro.cedula;
    }

    bool operator>(const Autor& otro) const {
        return cedula > otro.cedula;
    }

    friend std::ostream& operator<<(std::ostream& os, const Autor& autor);
};
