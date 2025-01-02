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

#endif
