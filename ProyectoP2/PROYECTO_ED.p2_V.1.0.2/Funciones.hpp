#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "BTree.hpp"
#include "Libro.hpp"
#include "Autor.hpp"
#include <string>

// Declaraciones
void cargar(BTree<Libro*>& libros, BTree<Autor*>& autores, const std::string& directorio = ".");
void guardar(BTree<Libro*>& libros, BTree<Autor*>& autores, const std::string& directorio = ".", bool backup = false);
void mostrarBackups(BTree<Libro*>& libros, BTree<Autor*>& autores);
void ordenarYMostrar(BTree<Libro*>& libros, std::function<bool(Libro*, Libro*)> criterio);
void manejarAutores(BTree<Autor*>& autores);

void insertarAutor(BTree<Autor*>& autores);
void buscarAutor(const BTree<Autor*>& autores);
void eliminarAutor(BTree<Autor*>& autores);
void mostrarAutores(const BTree<Autor*>& autores);
void guardarAutores(BTree<Autor*>& autores);
std::string normalizarNombre(const std::string& nombre);
#endif
