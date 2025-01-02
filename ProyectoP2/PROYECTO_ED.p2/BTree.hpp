#pragma once

#include <vector>
#include <iostream>
#include <functional>

// Clase nodo para el B-Tree
template <typename T>
class BTreeNode {
public:
    bool isLeaf;                     // Indica si el nodo es una hoja
    std::vector<T> keys;             // Llaves (datos)
    std::vector<BTreeNode*> children; // Hijos (punteros)

    BTreeNode(bool isLeaf);
};

// Implementación de BTreeNode
template <typename T>
BTreeNode<T>::BTreeNode(bool isLeaf) : isLeaf(isLeaf) {}

// Clase B-Tree
template <typename T>
class BTree {
private:
    int minDegree;                    // Grado mínimo (t)
    BTreeNode<T>* root;               // Raíz del árbol

    void insertNonFull(BTreeNode<T>* node, const T& key);
    void splitChild(BTreeNode<T>* node, int i, BTreeNode<T>* child);
    void traverse(std::function<void(const T&)> func, BTreeNode<T>* node) const;

public:
    BTree() : minDegree(2), root(nullptr) {} // Constructor por defecto
    BTree(int degree);
    ~BTree();

    void insert(const T& key);
    T* search(const std::function<bool(const T&)>& match) const; // Búsqueda con función lambda
    void traverse(std::function<void(const T&)> func) const;     // Recorrido con función lambda
    void print() const;
};

// Constructor del BTree con parámetro
template <typename T>
BTree<T>::BTree(int degree) : minDegree(degree), root(nullptr) {}

// Destructor del BTree
template <typename T>
BTree<T>::~BTree() {
    // Liberar memoria de los nodos si es necesario
}

// Inserción en el árbol
template <typename T>
void BTree<T>::insert(const T& key) {
    if (!root) {
        root = new BTreeNode<T>(true);
        root->keys.push_back(key);
    }
    else {
        if (root->keys.size() == 2 * minDegree - 1) {
            BTreeNode<T>* newRoot = new BTreeNode<T>(false);
            newRoot->children.push_back(root);
            splitChild(newRoot, 0, root);
            int i = (newRoot->keys[0] < key) ? 1 : 0;
            insertNonFull(newRoot->children[i], key);
            root = newRoot;
        }
        else {
            insertNonFull(root, key);
        }
    }
}

// Inserta en un nodo no lleno
template <typename T>
void BTree<T>::insertNonFull(BTreeNode<T>* node, const T& key) {
    int i = node->keys.size() - 1;
    if (node->isLeaf) {
        node->keys.push_back(key);
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
    }
    else {
        while (i >= 0 && node->keys[i] > key)
            i--;
        i++;
        if (node->children[i]->keys.size() == 2 * minDegree - 1) {
            splitChild(node, i, node->children[i]);
            if (node->keys[i] < key)
                i++;
        }
        insertNonFull(node->children[i], key);
    }
}

// Divide un nodo hijo lleno
template <typename T>
void BTree<T>::splitChild(BTreeNode<T>* node, int i, BTreeNode<T>* child) {
    BTreeNode<T>* newNode = new BTreeNode<T>(child->isLeaf);
    for (int j = 0; j < minDegree - 1; j++)
        newNode->keys.push_back(child->keys[j + minDegree]);
    if (!child->isLeaf) {
        for (int j = 0; j < minDegree; j++)
            newNode->children.push_back(child->children[j + minDegree]);
    }
    child->keys.resize(minDegree - 1);
    child->children.resize(minDegree);
    node->children.insert(node->children.begin() + i + 1, newNode);
    node->keys.insert(node->keys.begin() + i, child->keys[minDegree - 1]);
}

// Busca un valor en el árbol
template <typename T>
T* BTree<T>::search(const std::function<bool(const T&)>& match) const {
    BTreeNode<T>* current = root;
    while (current) {
        int i = 0;
        while (i < current->keys.size() && !match(current->keys[i])) {
            i++;
        }
        if (i < current->keys.size() && match(current->keys[i])) {
            return &(current->keys[i]);
        }
        if (current->isLeaf) {
            return nullptr;
        }
        current = current->children[i];
    }
    return nullptr;
}

// Recorre el árbol y aplica una función a cada elemento
template <typename T>
void BTree<T>::traverse(std::function<void(const T&)> func) const {
    traverse(func, root);
}

template <typename T>
void BTree<T>::traverse(std::function<void(const T&)> func, BTreeNode<T>* node) const {
    if (!node) return;
    for (size_t i = 0; i < node->keys.size(); ++i) {
        if (!node->isLeaf) traverse(func, node->children[i]);
        func(node->keys[i]);
    }
    if (!node->isLeaf) traverse(func, node->children[node->keys.size()]);
}

// Imprime el árbol
template <typename T>
void BTree<T>::print() const {
    traverse([](const T& key) { std::cout << key << " "; });
    std::cout << std::endl;
}
