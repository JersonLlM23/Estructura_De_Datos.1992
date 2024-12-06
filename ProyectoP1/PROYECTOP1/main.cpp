#include "ListaAutores.h"
#include "ListaLibros.h"
#include "Validaciones.h"
#include <iostream>
#include <cstdlib> // Para system()

using namespace std;

// Función para limpiar la pantalla
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls"); // Para Windows
    #else
        system("clear"); // Para Linux y macOS
    #endif
}

// Función para pausar el sistema y esperar una tecla
void pausarSistema() {
    cout << "Presione Enter para continuar... ";
    cin.ignore(); // Ignora cualquier entrada previa en el buffer
    getchar();    // Espera a que el usuario presione una tecla
}

void imprimirMenu() {
    cout << "\n--- MENÚ ---\n";
    cout << "1. Insertar Autor\n";
    cout << "2. Buscar Autor\n";
    cout << "3. Eliminar Autor\n";
    cout << "4. Mostrar Autores\n";
    cout << "5. Insertar Libro\n";
    cout << "6. Buscar Libro\n";
    cout << "7. Eliminar Libro\n";
    cout << "8. Mostrar Libros\n";
    cout << "9. Salir\n";
    cout << "Ingrese una opción: ";
}

int main() {
    ListaAutores listaAutores;
    ListaLibros listaLibros;

    listaAutores.cargarDesdeArchivo();
    listaLibros.cargarDesdeArchivo();

    int opcion;
    
    // Imprimir el menú solo una vez al inicio
    imprimirMenu();

    do {
        cin >> opcion;

        // Procesar la opción seleccionada
        switch (opcion) {
        case 1: {
            string cedula, nombre, apellido, fechaPublicacion;
            cout << "Ingrese cédula: ";
            cin >> cedula;
            cout << "Ingrese nombre: ";
            cin >> nombre;
            cout << "Ingrese apellido: ";
            cin >> apellido;
            cout << "Ingrese fecha de publicación: ";
            cin >> fechaPublicacion;

            if (!validarCedula(cedula) || !validarTexto(nombre) || !validarTexto(apellido)) {
                cout << "Error: Datos inválidos.\n";
                break;
            }
            listaAutores.insertar(cedula, nombre, apellido, fechaPublicacion);
            break;
        }
        case 2: {
            string cedula;
            cout << "Ingrese cédula del autor: ";
            cin >> cedula;
            NodoAutores* autor = listaAutores.buscar(cedula);
            if (autor) {
                cout << "Autor encontrado: " << autor->getNombre() << " " << autor->getApellido() << "\n";
            } else {
                cout << "Autor no encontrado.\n";
            }
            break;
        }
        case 3: {
            string cedula;
            cout << "Ingrese cédula del autor a eliminar: ";
            cin >> cedula;
            listaAutores.eliminar(cedula);
            break;
        }
        case 4:
            listaAutores.mostrar();
            break;
        case 5: {
            string titulo, isbn, genero;
            int anioLanzamiento;
            float precio, calificacion;

            string autor = listaLibros.seleccionarAutor(listaAutores);
            if (autor.empty()) break;

            cout << "Ingrese título: ";
            cin >> titulo;
            cout << "Ingrese ISBN: ";
            cin >> isbn;
            cout << "Ingrese género: ";
            cin >> genero;
            cout << "Ingrese año de lanzamiento: ";
            cin >> anioLanzamiento;
            cout << "Ingrese precio: ";
            cin >> precio;
            cout << "Ingrese calificación: ";
            cin >> calificacion;

            listaLibros.insertar(titulo, autor, isbn, genero, anioLanzamiento, precio, calificacion);
            break;
        }
        case 6: {
            string isbn;
            cout << "Ingrese ISBN del libro: ";
            cin >> isbn;
            NodoLibros* libro = listaLibros.buscar(isbn);
            if (libro) {
                cout << "Libro encontrado: " << libro->getTitulo() << ", Autor: " << libro->getAutor() << "\n";
            } else {
                cout << "Libro no encontrado.\n";
            }
            break;
        }
        case 7: {
            string isbn;
            cout << "Ingrese ISBN del libro a eliminar: ";
            cin >> isbn;
            listaLibros.eliminar(isbn);
            break;
        }
        case 8:
            listaLibros.mostrar();
            break;
        case 9:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opción no válida.\n";
        }

        // Pausar después de procesar la opción
        pausarSistema();

        // Limpiar la pantalla y volver a imprimir el menú
        limpiarPantalla();
        imprimirMenu();

    } while (opcion != 9);

    return 0;
}
