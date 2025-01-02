#include "BTree.hpp"
#include "Funciones.hpp"
#include "Libro.hpp"
#include "Autor.hpp"
#include "Validaciones.hpp"
#include <iostream>
#include <functional>
#include <ctime>
#include <iomanip>

#define CLEAR_COMMAND "cls" // Cambia a "clear" si usas Linux


inline void imprimirMenu(const std::string& menu, int seleccion) {
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

void manejarLibros(BTree<Libro*>& libros, BTree<Autor*>& autores) {
    const std::string menuLibros =
        "1. Insertar\n"
        "2. Buscar\n"
        "3. Eliminar\n"
        "4. Mostrar\n"
        "5. Guardar\n"
        "6. Filtrar por Fecha (year)\n"
        "7. Ordenar Libros\n"
        "8. Volver\n";


    int opcion = 1;
    bool salir = false;

    while (!salir) {
        system(CLEAR_COMMAND);
        std::cout << "============ LISTA LIBROS ============" << std::endl;
        imprimirMenu(menuLibros, opcion);

        char tecla = getch();
        switch (tecla) {
        case 72: // Flecha arriba
            if (opcion > 1) opcion--;
            break;
        case 80: // Flecha abajo
            if (opcion < 8) opcion++;
            break;
        case 13: // Enter
            switch (opcion) {
            case 1: { // Insertar libro
                std::cout << "Ingrese el ID del libro (solo números): ";
                std::string id = Validaciones::leerNumero();

                std::cout << "Ingrese el titulo del libro: ";
                std::string titulo = Validaciones::leerLinea();

                std::cout << "Ingrese la cédula del autor: ";
                std::string cedulaAutor = Validaciones::leerCedula();

                Autor** autorPtr = autores.search([&](Autor* a) { return a->getId() == cedulaAutor; });
                if (autorPtr) {
                    Autor* autor = *autorPtr;
                    Libro* nuevoLibro = new Libro(id, titulo, autor, std::time(nullptr));
                    libros.insert(nuevoLibro);
                    autor->libros.insert(nuevoLibro);
                    std::cout << "Libro insertado con éxito.\n";
                }
                else {
                    std::cout << "Autor no encontrado.\n";
                }
                system("pause");
                break;
            }
            case 2: { // Buscar libro
                std::cout << "Ingrese el ID del libro a buscar: ";
                std::string id = Validaciones::leerNumero();

                Libro** libroPtr = libros.search([&](Libro* l) { return l->getId() == id; });
                if (libroPtr) {
                    std::cout << "Libro encontrado:\n" << **libroPtr << std::endl;
                }
                else {
                    std::cout << "Libro no encontrado.\n";
                }
                system("pause");
                break;
            }
            case 3: { // Eliminar libro
                std::cout << "Ingrese el ID del libro a eliminar: ";
                std::string id = Validaciones::leerNumero();

                bool eliminado = libros.remove([&](Libro* l) { return l->getId() == id; });
                if (eliminado) {
                    std::cout << "Libro eliminado correctamente.\n";
                }
                else {
                    std::cout << "Libro no encontrado.\n";
                }
                system("pause");
                break;
            }
            case 4: { // Mostrar libros
                if (libros.isEmpty()) {
                    std::cout << "No hay libros registrados.\n";
                }
                else {
                    libros.traverse([](Libro* libro) {
                        std::cout << *libro << std::endl;
                        });
                }
                system("pause");
                break;
            }
            case 5: { // Guardar libros
                guardar(libros, autores, ".", true); // Generar el backup
                std::cout << "Libros guardados correctamente.\n";
                system("pause");
                break;
            }
            case 6: { // Filtrar por año
                int anioInicio, anioFin;

                // Solicitar el año inicial con validación
                do {
                    std::cout << "Ingrese el anio inicial del rango (mínimo 1900): ";
                    anioInicio = Validaciones::leerEntero();
                    if (anioInicio < 1900) {
                        std::cout << "El anio inicial no puede ser menor a 1900. Inténtelo nuevamente.\n";
                    }
                } while (anioInicio < 1900);

                // Solicitar el año final con validación
                do {
                    std::cout << "Ingrese el anio final del rango (máximo 2100): ";
                    anioFin = Validaciones::leerEntero();
                    if (anioFin > 2100) {
                        std::cout << "El anio final no puede ser mayor a 2100. Inténtelo nuevamente.\n";
                    }
                    if (anioFin < anioInicio) {
                        std::cout << "El anio final no puede ser menor al anio inicial. Inténtelo nuevamente.\n";
                    }
                } while (anioFin > 2100 || anioFin < anioInicio);

                // Filtrar y mostrar libros en el rango de años
                bool encontrado = false;
                libros.traverse([&](Libro* libro) {
                    int anioLibro = libro->getFecha().getAnio();
                    if (anioLibro >= anioInicio && anioLibro <= anioFin) {
                        std::cout << *libro << std::endl;
                        encontrado = true; // Marcamos que al menos un libro fue encontrado
                    }
                    });

                if (!encontrado) {
                    std::cout << "No se encontraron libros en el rango especificado.\n";
                }

                system("pause");
                break;
            }
            case 7: { // Ordenar libros
                const std::string menuOrdenar =
                    "1. ID\n"
                    "2. Titulo\n"
                    "3. Autor\n"
                    "4. Fecha\n"
                    "5. Cancelar\n";

                int opcionOrdenar = 1;
                bool salirOrdenar = false;

                while (!salirOrdenar) {
                    system(CLEAR_COMMAND);
                    std::cout << "============ POR MIEMBRO ============" << std::endl;
                    imprimirMenu(menuOrdenar, opcionOrdenar);

                    char tecla = getch();
                    switch (tecla) {
                    case 72: // Flecha arriba
                        if (opcionOrdenar > 1) opcionOrdenar--;
                        break;
                    case 80: // Flecha abajo
                        if (opcionOrdenar < 5) opcionOrdenar++;
                        break;
                    case 13: // Enter
                        switch (opcionOrdenar) {
                        case 1: // Ordenar por ID
                            ordenarYMostrar(libros, [](Libro* a, Libro* b) { return a->getId() < b->getId(); });
                            break;
                        case 2: // Ordenar por Título
                            ordenarYMostrar(libros, [](Libro* a, Libro* b) { return a->getTitulo() < b->getTitulo(); });
                            break;
                        case 3: // Ordenar por Autor
                            ordenarYMostrar(libros, [](Libro* a, Libro* b) { return a->getAutor()->getNombre() < b->getAutor()->getNombre(); });
                            break;
                        case 4: // Ordenar por Fecha
                            ordenarYMostrar(libros, [](Libro* a, Libro* b) { return a->getFecha().getTiempo() < b->getFecha().getTiempo(); });
                            break;
                        case 5: // Cancelar
                            salirOrdenar = true;
                            break;
                        }
                        break;
                    }
                }
                break;
            }
            case 8: { // Volver
                salir = true;
                break;
            }
                  break;
            }
        }
    }
}

void manejarAutores(BTree<Autor*>& autores) {
    const std::string menuAutores =
        "1. Insertar\n"
        "2. Buscar\n"
        "3. Eliminar\n"
        "4. Mostrar\n"
        "5. Guardar\n"
        "6. Volver\n";

    int opcion = 1;
    bool salir = false;

    while (!salir) {
        system(CLEAR_COMMAND);
        std::cout << "============ LISTA AUTORES ============" << std::endl;
        imprimirMenu(menuAutores, opcion);

        char tecla = getch();
        switch (tecla) {
        case 72: // Flecha arriba
            if (opcion > 1) opcion--;
            break;
        case 80: // Flecha abajo
            if (opcion < 6) opcion++;
            break;
        case 13: // Enter
            switch (opcion) {
            case 1: { // Insertar autor
                std::string cedula;
                do {
                    std::cout << "Ingrese la cédula del autor (10 dígitos): ";
                    cedula = Validaciones::leerCedula();

                    if (cedula.length() != 10) {
                        std::cout << "La cédula debe tener exactamente 10 dígitos. Intente nuevamente.\n";
                        system("pause");
                    }
                } while (cedula.length() != 10);

                // Verificar si ya existe un autor con esta cédula
                Autor** autorPtr = autores.search([&](Autor* a) { return a->getId() == cedula; });
                if (autorPtr) {
                    std::cout << "Error: Ya existe un autor con esta cédula.\n";
                    system("pause");
                    break;
                }

                std::string nombre, segundoNombre, apellido;

                do {
                    std::cout << "Ingrese el primer nombre del autor: ";
                    nombre = Validaciones::leerLinea();
                    nombre = normalizarNombre(nombre);

                    if (!Validaciones::esNombreValido(nombre)) {
                        std::cout << "El nombre no puede contener números.\n";
                        system("pause");
                    }
                } while (!Validaciones::esNombreValido(nombre));

                do {
                    std::cout << "Ingrese el segundo nombre del autor (opcional, presione Enter para omitir): ";
                    segundoNombre = Validaciones::leerLinea();
                    segundoNombre = normalizarNombre(segundoNombre);

                    if (!segundoNombre.empty() && !Validaciones::esNombreValido(segundoNombre)) {
                        std::cout << "El segundo nombre no puede contener números.\n";
                        system("pause");
                    }
                } while (!segundoNombre.empty() && !Validaciones::esNombreValido(segundoNombre));

                do {
                    std::cout << "Ingrese el apellido del autor: ";
                    apellido = Validaciones::leerLinea();
                    apellido = normalizarNombre(apellido);

                    if (!Validaciones::esNombreValido(apellido)) {
                        std::cout << "El apellido no puede contener números.\n";
                        system("pause");
                    }
                } while (!Validaciones::esNombreValido(apellido));

                Autor* nuevoAutor = new Autor(cedula, nombre, segundoNombre, apellido);
                autores.insert(nuevoAutor);
                std::cout << "Autor insertado con éxito.\n";
                system("pause");
                break;
            }
            case 2: { // Buscar autor
                std::string cedula;
                do {
                    std::cout << "Ingrese la cédula del autor a buscar (10 dígitos): ";
                    cedula = Validaciones::leerCedula();

                    if (cedula.length() != 10) {
                        std::cout << "La cédula debe tener exactamente 10 dígitos. Intente nuevamente.\n";
                        system("pause");
                    }
                } while (cedula.length() != 10);

                Autor** autorPtr = autores.search([&](Autor* a) { return a->getId() == cedula; });
                if (autorPtr) {
                    std::cout << "Autor encontrado:\n" << **autorPtr << std::endl;
                }
                else {
                    std::cout << "Autor no encontrado.\n";
                }
                system("pause");
                break;
            }
            case 3: { // Eliminar autor
                std::string cedula;
                do {
                    std::cout << "Ingrese la cédula del autor a eliminar (10 dígitos): ";
                    cedula = Validaciones::leerCedula();

                    if (cedula.length() != 10) {
                        std::cout << "La cédula debe tener exactamente 10 dígitos. Intente nuevamente.\n";
                        system("pause");
                    }
                } while (cedula.length() != 10);

                bool eliminado = autores.remove([&](Autor* a) { return a->getId() == cedula; });
                if (eliminado) {
                    std::cout << "Autor eliminado correctamente.\n";
                }
                else {
                    std::cout << "Autor no encontrado.\n";
                }
                system("pause");
                break;
            }
            case 4: { // Mostrar autores
                if (autores.isEmpty()) {
                    std::cout << "No hay autores registrados.\n";
                }
                else {
                    autores.traverse([](Autor* autor) { std::cout << *autor << std::endl; });
                }
                system("pause");
                break;
            }
            case 5: { // Guardar autores
                guardarAutores(autores);
                std::cout << "Autores guardados correctamente.\n";
                system("pause");
                break;
            }
            case 6: // Volver
                salir = true;
                break;
            }
            break;
        }
    }
}


int main() {
    BTree<Libro*> listaLibros(3);
    BTree<Autor*> listaAutores(3);

    cargar(listaLibros, listaAutores);

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
        case 72: // Flecha arriba
            if (opcion > 1) opcion--;
            break;
        case 80: // Flecha abajo
            if (opcion < 4) opcion++;
            break;
        case 13: // Enter
            switch (opcion) {
            case 1:
                manejarLibros(listaLibros, listaAutores);
                break;
            case 2:
                manejarAutores(listaAutores);
                break;
            case 3:
                mostrarBackups(listaLibros, listaAutores);
                break;
            case 4:
                guardar(listaLibros, listaAutores, ".", false);
                salir = true;
                break;
            }
            break;
        }
    }

    return 0;
}
