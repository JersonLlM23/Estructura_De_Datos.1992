#include "BTree.hpp"
#include "Libro.hpp"
#include "Autor.hpp"
#include "Validaciones.hpp"
#include "Funciones.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#define CLEAR_COMMAND "cls"
#include <conio.h>
#else
#define CLEAR_COMMAND "clear"

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
void cargar(BTree<Libro*>& libros, BTree<Autor*>& autores, const std::string& directorio) {
    // Cargar autores
    std::ifstream archivoAutores(directorio + "/autores.txt");
    std::string linea;
    while (getline(archivoAutores, linea)) {
        std::istringstream ss(linea);
        std::string cedula, nombre, nombre2, apellido;
        getline(ss, cedula, ',');
        getline(ss, nombre, ',');
        getline(ss, nombre2, ',');
        getline(ss, apellido);

        // Verificar si el autor ya existe
        Autor** autorPtr = autores.search([&](Autor* a) { return a->getId() == cedula; });
        if (!autorPtr) {
            autores.insert(new Autor(cedula, nombre, nombre2, apellido));
        }
    }
    archivoAutores.close();

    // Cargar libros
    std::ifstream archivoLibros(directorio + "/libros.txt");
    while (getline(archivoLibros, linea)) {
        std::istringstream ss(linea);
        std::string id, titulo, idAutor, tiempoS;
        getline(ss, id, ',');
        getline(ss, titulo, ',');
        getline(ss, idAutor, ',');
        getline(ss, tiempoS);

        std::time_t tiempo = std::stoll(tiempoS);

        // Verificar si el libro ya existe
        Libro** libroPtr = libros.search([&](Libro* l) { return l->getId() == id; });
        if (!libroPtr) {
            Autor** autorPtr = autores.search([&](Autor* a) { return a->getId() == idAutor; });
            if (autorPtr) {
                Autor* autor = *autorPtr;
                libros.insert(new Libro(id, titulo, autor, tiempo));
            }
        }
    }
    archivoLibros.close();
}

void guardar(BTree<Libro*>& libros, BTree<Autor*>& autores, const std::string& directorio, bool backup) {
    if (!directorio.empty()) {
        std::filesystem::create_directories(directorio);
    }

    // Guardar libros
    std::ofstream archivoLibros(directorio + "/libros.txt");
    libros.traverse([&archivoLibros](Libro* libro) {
        archivoLibros << libro->getId() << ","
            << libro->getTitulo() << ","
            << libro->getAutor()->getId() << ","
            << libro->getFecha().getTiempo() << "\n";
        });
    archivoLibros.close();

    // Guardar autores
    std::ofstream archivoAutores(directorio + "/autores.txt");
    autores.traverse([&archivoAutores](Autor* autor) {
        archivoAutores << autor->getId() << ","
            << autor->getNombre() << ","
            << autor->getNombre2() << ","
            << autor->getApellido() << "\n";
        });
    archivoAutores.close();

    // Crear un backup si se solicita
    if (backup) {
        // Obtener tiempo actual y formatearlo
        std::time_t t = std::time(nullptr);
        struct tm localTime;
        localtime_s(&localTime, &t); // Para sistemas Windows, usa localtime_r en Linux

        char buffer[100];
        strftime(buffer, sizeof(buffer), "%a %b %d %H.%M.%S %Y", &localTime); // Formato: Mon Dec 9 12.54.05 2024

        std::string backupDir = "backup/" + std::string(buffer);
        std::filesystem::create_directories(backupDir);

        std::filesystem::copy_file(directorio + "/libros.txt", backupDir + "/libros.txt");
        std::filesystem::copy_file(directorio + "/autores.txt", backupDir + "/autores.txt");
    }
}

void mostrarBackups(BTree<Libro*>& libros, BTree<Autor*>& autores) {
    int seleccion = 1;
    std::vector<std::string> backups;

    // Obtener lista de backups
    for (const auto& entry : std::filesystem::directory_iterator("backup")) {
        backups.push_back(entry.path().string());
    }

    backups.push_back("CANCELAR");

    bool salir = false;
    while (!salir) {
        system(CLEAR_COMMAND);
        std::cout << "============ ELEGIR BACKUP ============" << std::endl;

        for (size_t i = 0; i < backups.size(); ++i) {
            if (i + 1 == seleccion)
                std::cout << "> " << backups[i] << " <" << std::endl;
            else
                std::cout << "  " << backups[i] << std::endl;
        }

        char tecla = getch();
        switch (tecla) {
        case 72: // Flecha arriba
            if (seleccion > 1) seleccion--;
            break;
        case 80: // Flecha abajo
            if (seleccion < backups.size()) seleccion++;
            break;
        case 13: // Enter
            if (seleccion == backups.size()) {
                salir = true;
            }
            else {
                std::string backupDir = backups[seleccion - 1];
                cargar(libros, autores, backupDir);
                std::cout << "Backup cargado desde " << backupDir << std::endl;
                system("pause");
                salir = true;
            }
            break;
        }
    }
}

void filtrarLibrosPorAnio(BTree<Libro*>& libros) {
    int anioInicio, anioFin;

    std::cout << "Ingrese el año inicial del rango: ";
    std::cin >> anioInicio;
    std::cout << "Ingrese el año final del rango: ";
    std::cin >> anioFin;

    if (anioInicio > anioFin) {
        std::cout << "Rango de años no válido.\n";
        return;
    }

    std::cout << "Filtrando libros entre " << anioInicio << " y " << anioFin << ":\n";
    libros.traverse([&](Libro* libro) {
        int anioLibro = std::localtime(&libro->getFecha().getTiempo())->tm_year + 1900;
        if (anioLibro >= anioInicio && anioLibro <= anioFin) {
            std::cout << *libro << std::endl;
        }
        });
}
void ordenarYMostrar(BTree<Libro*>& libros, std::function<bool(Libro*, Libro*)> criterio) {
    if (libros.isEmpty()) {
        std::cout << "No hay libros registrados para ordenar.\n";
        return;
    }

    std::vector<Libro*> librosOrdenados;
    libros.traverse([&](Libro* libro) { librosOrdenados.push_back(libro); });
    std::sort(librosOrdenados.begin(), librosOrdenados.end(), criterio);

    for (const auto& libro : librosOrdenados) {
        std::cout << *libro << std::endl;
    }
    system("pause");
}


std::string normalizarNombre(const std::string& nombre) {
    std::string resultado;
    bool inicioPalabra = true;
    for (char c : nombre) {
        if (isspace(c)) {
            inicioPalabra = true;
            resultado += c;
        }
        else {
            resultado += inicioPalabra ? toupper(c) : tolower(c);
            inicioPalabra = false;
        }
    }
    return resultado;
}

void insertarAutor(BTree<Autor*>& autores) {
    std::cout << "Ingrese la cedula del autor: ";
    std::string cedula = Validaciones::leerCedula();
    std::cout << "Ingrese el nombre del autor: ";
    std::string nombre = Validaciones::leerLinea();


    Autor* nuevoAutor = new Autor(cedula, nombre);
    autores.insert(nuevoAutor);
    std::cout << "Autor insertado con éxito.\n";
}

void buscarAutor(const BTree<Autor*>& autores) {
    std::cout << "Ingrese la cédula del autor a buscar: ";
    std::string cedula = Validaciones::leerCedula();

    Autor** autorPtr = autores.search([&](Autor* autor) {
        return autor->getId() == cedula;
        });

    if (autorPtr) {
        std::cout << "Autor encontrado:\n" << **autorPtr << std::endl;
    }
    else {
        std::cout << "Autor no encontrado.\n";
    }

    system("pause");
}

void eliminarAutor(BTree<Autor*>& autores) {
    std::cout << "Ingrese la cédula del autor a eliminar: ";
    std::string cedula = Validaciones::leerCedula();

    bool eliminado = autores.remove([&](Autor* autor) {
        return autor->getId() == cedula;
        });

    if (eliminado) {
        std::cout << "Autor eliminado con éxito.\n";
    }
    else {
        std::cout << "Autor no encontrado.\n";
    }

    system("pause");
}

void mostrarAutores(const BTree<Autor*>& autores) {
    if (autores.isEmpty()) {
        std::cout << "No hay autores registrados.\n";
    }
    else {
        autores.traverse([](Autor* autor) {
            std::cout << *autor << std::endl;
            });
    }

    system("pause");
}

void guardarAutores(BTree<Autor*>& autores) {
    std::ofstream archivo("autores.txt");
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para guardar.\n";
        return;
    }

    autores.traverse([&](Autor* autor) {
        archivo << autor->getId() << ","
            << autor->getNombre() << "\n";
        });

    archivo.close();
    std::cout << "Autores guardados correctamente.\n";
    system("pause");
}

