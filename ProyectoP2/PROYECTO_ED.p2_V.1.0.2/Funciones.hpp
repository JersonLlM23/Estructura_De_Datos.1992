#pragma once

#include "BTree.hpp"
#include "Libro.hpp"
#include "Autor.hpp"
#include <string>

// Declaraciones de funciones relacionadas con los autores
void insertarAutor(BTree<Autor*>& autores);
void buscarAutor(const BTree<Autor*>& autores);
void eliminarAutor(BTree<Autor*>& autores);
void mostrarAutores(const BTree<Autor*>& autores);
void guardarAutores(BTree<Autor*>& autores);

// Declaraciones de funciones relacionadas con los libros
void cargar(BTree<Libro*>& libros, BTree<Autor*>& autores, const std::string& directorio = ".");
void guardar(BTree<Libro*>& libros, BTree<Autor*>& autores, const std::string& directorio = ".", bool backup = false);
void mostrarBackups(BTree<Libro*>& libros, BTree<Autor*>& autores);
void filtrarLibrosPorAnio(BTree<Libro*>& libros);
void ordenarYMostrar(BTree<Libro*>& libros, std::function<bool(Libro*, Libro*)> criterio);

// Normalización de nombres
std::string normalizarNombre(const std::string& nombre);

// Menús
void manejarLibros(BTree<Libro*>& libros, BTree<Autor*>& autores);
void manejarAutores(BTree<Autor*>& autores);
