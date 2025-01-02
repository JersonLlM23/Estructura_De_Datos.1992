#include "BTree.hpp"
#include "Funciones.hpp"
#include "Libro.hpp"
#include "Autor.hpp"
#include "Validaciones.hpp"
#include <iostream>
#include <conio.h> // Para getch() en Windows

#define CLEAR_COMMAND "cls" // Cambia a "clear" si usas Linux

void imprimirMenu(const std::string& menu, int seleccion) {
    std::stringstream ss(menu);
    std::string linea;
    int opcion = 1;
    while (getline(ss, linea)) {
        if (opcion == seleccion)
            std::cout << "> " << linea << " <" << std::endl;
        else
            std::cout << "  " << linea << std::endl;
        opcion++;
    }
}

int main() {
    // Árboles para gestionar los datos
    BTree<Libro*> listaLibros(3);
    BTree<Autor*> listaAutores(3);

    // Cambia aquí la llamada a `cargar` para incluir el directorio
    cargar(listaLibros, listaAutores, ".");

    const std::string menuPrincipal =
        "1. Libros\n"
        "2. Autores\n"
        "3. Backup\n"
        "4. Salir\n";

    int opcion = 1;
    bool salir = false;

    while (!salir) {
        system(CLEAR_COMMAND);
        std::cout << "============ MENÚ PRINCIPAL ============" << std::endl;
        imprimirMenu(menuPrincipal, opcion);

        char tecla = getch();

        switch (tecla) {
        case 72:
            if (opcion > 1) opcion--;
            break;
        case 80:
            if (opcion < 4) opcion++;
            break;
        case 13:
            switch (opcion) {
            case 1: {
                const std::string menuLibros =
                    "1. Insertar\n"
                    "2. Mostrar\n"
                    "3. Guardar\n"
                    "4. Volver\n";

                int opcionLibros = 1;
                bool salirLibros = false;
                while (!salirLibros) {
                    system(CLEAR_COMMAND);
                    std::cout << "============ LISTA LIBROS ============" << std::endl;
                    imprimirMenu(menuLibros, opcionLibros);

                    char teclaLibros = getch();
                    switch (teclaLibros) {
                    case 72:
                        if (opcionLibros > 1) opcionLibros--;
                        break;
                    case 80:
                        if (opcionLibros < 4) opcionLibros++;
                        break;
                    case 13:
                        switch (opcionLibros) {
                        case 1: {
                            std::string id, titulo, cedulaAutor;
                            std::cout << "Ingrese el ID del libro: ";
                            id = Validaciones::leerLinea();
                            std::cout << "Ingrese el título del libro: ";
                            titulo = Validaciones::leerLinea();
                            std::cout << "Ingrese la cédula del autor: ";
                            cedulaAutor = Validaciones::leerLinea();

                            Autor** autorPtr = listaAutores.search([&](Autor* a) { return a->getId() == cedulaAutor; });
                            if (autorPtr) {
                                Autor* autor = *autorPtr;
                                Libro* nuevoLibro = new Libro(id, titulo, autor, std::time(nullptr));
                                listaLibros.insert(nuevoLibro);
                                autor->libros.insert(nuevoLibro);
                            }
                            else {
                                std::cout << "Autor no encontrado.\n";
                            }
                            system("pause");
                            break;
                        }
                        case 2:
                            listaLibros.traverse([](Libro* libro) { std::cout << *libro << std::endl; });
                            system("pause");
                            break;
                        case 3:
                            // Cambia aquí la llamada a `guardar` para incluir el directorio y `backup`
                            guardar(listaLibros, listaAutores, ".", true);
                            break;
                        case 4:
                            salirLibros = true;
                            break;
                        }
                        break;
                    }
                }
                break;
            }
            case 2: {
                const std::string menuAutores =
                    "1. Insertar\n"
                    "2. Mostrar\n"
                    "3. Guardar\n"
                    "4. Volver\n";

                int opcionAutores = 1;
                bool salirAutores = false;
                while (!salirAutores) {
                    system(CLEAR_COMMAND);
                    std::cout << "============ LISTA AUTORES ============" << std::endl;
                    imprimirMenu(menuAutores, opcionAutores);

                    char teclaAutores = getch();
                    switch (teclaAutores) {
                    case 72:
                        if (opcionAutores > 1) opcionAutores--;
                        break;
                    case 80:
                        if (opcionAutores < 4) opcionAutores++;
                        break;
                    case 13:
                        switch (opcionAutores) {
                        case 1: {
                            std::string cedula, nombre, nombre2, apellido;
                            do {
                                std::cout << "Ingrese la cédula (10 dígitos): ";
                                cedula = Validaciones::leerCedula();
                            } while (!Validaciones::validarCedula(cedula));

                            std::cout << "Ingrese el nombre: ";
                            nombre = Validaciones::leerLinea();
                            std::cout << "Ingrese el segundo nombre: ";
                            nombre2 = Validaciones::leerLinea();
                            std::cout << "Ingrese el apellido: ";
                            apellido = Validaciones::leerLinea();

                            listaAutores.insert(new Autor(cedula, nombre, nombre2, apellido));
                            break;
                        }
                        case 2:
                            listaAutores.traverse([](Autor* autor) { std::cout << *autor << std::endl; });
                            system("pause");
                            break;
                        case 3:
                            guardar(listaLibros, listaAutores, ".", true);
                            break;
                        case 4:
                            salirAutores = true;
                            break;
                        }
                        break;
                    }
                }
                break;
            }
            case 3:
                mostrarBackups(listaLibros, listaAutores);
                break;
            case 4:
                salir = true;
                break;
            }
            break;
        }
    }

    return 0;
}
