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

    // Métodos auxiliares para eliminación
    bool removeFromNode(BTreeNode<T>* node, std::function<bool(const T&)> criterio);
    bool removeInternalNode(BTreeNode<T>* node, int idx);
    void fixUnderflow(BTreeNode<T>* node, int idx);
    void merge(BTreeNode<T>* node, int idx);
    void borrowFromPrev(BTreeNode<T>* node, int idx);
    void borrowFromNext(BTreeNode<T>* node, int idx);

    T getPredecessor(BTreeNode<T>* node, int idx);
    T getSuccessor(BTreeNode<T>* node, int idx);
    void deleteNode(BTreeNode<T>* node);

public:
    BTree() : minDegree(2), root(nullptr) {} // Constructor por defecto
    BTree(int degree);
    ~BTree();

    void insert(const T& key);
    T* search(const std::function<bool(const T&)>& match) const; // Búsqueda con función lambda
    void traverse(std::function<void(const T&)> func) const;     // Recorrido con función lambda
    void print() const;
    bool isEmpty() const;
    bool remove(std::function<bool(const T&)> criterio);
};

// Constructor del BTree con parámetro
template <typename T>
BTree<T>::BTree(int degree) : minDegree(degree), root(nullptr) {}

// Destructor del BTree
template <typename T>
BTree<T>::~BTree() {
    deleteNode(root);
}

template <typename T>
void BTree<T>::deleteNode(BTreeNode<T>* node) {
    if (!node) return;
    for (auto child : node->children) {
        deleteNode(child);
    }
    delete node;
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

// Búsqueda
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

// Recorrido
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

// Imprimir
template <typename T>
void BTree<T>::print() const {
    traverse([](const T& key) { std::cout << key << " "; });
    std::cout << std::endl;
}

// Eliminación
template <typename T>
bool BTree<T>::remove(std::function<bool(const T&)> criterio) {
    if (!root) {
        std::cout << "El árbol está vacío.\n";
        return false;
    }
    return removeFromNode(root, criterio);
}

template <typename T>
bool BTree<T>::removeFromNode(BTreeNode<T>* node, std::function<bool(const T&)> criterio) {
    int idx = 0;

    // Encontrar la clave que cumple el criterio
    while (idx < node->keys.size() && !criterio(node->keys[idx])) {
        idx++;
    }

    if (idx < node->keys.size() && criterio(node->keys[idx])) {
        if (node->isLeaf) {
            node->keys.erase(node->keys.begin() + idx);
            return true;
        }
        else {
            return removeInternalNode(node, idx);
        }
    }

    if (!node->isLeaf) {
        bool result = removeFromNode(node->children[idx], criterio);
        if (node->children[idx]->keys.size() < minDegree - 1) {
            fixUnderflow(node, idx);
        }
        return result;
    }

    return false; // No encontrado
}

// Funciones auxiliares de eliminación
template <typename T>
bool BTree<T>::removeInternalNode(BTreeNode<T>* node, int idx) {
    T key = node->keys[idx];
    if (node->children[idx]->keys.size() >= minDegree) {
        T predecessor = getPredecessor(node, idx);
        node->keys[idx] = predecessor;
        return removeFromNode(node->children[idx], [&](const T& val) { return val == predecessor; });
    }
    else if (node->children[idx + 1]->keys.size() >= minDegree) {
        T successor = getSuccessor(node, idx);
        node->keys[idx] = successor;
        return removeFromNode(node->children[idx + 1], [&](const T& val) { return val == successor; });
    }
    else {
        merge(node, idx);
        return removeFromNode(node->children[idx], [&](const T& val) { return val == key; });
    }
}

template <typename T>
void BTree<T>::fixUnderflow(BTreeNode<T>* node, int idx) {
    if (idx > 0 && node->children[idx - 1]->keys.size() >= minDegree) {
        borrowFromPrev(node, idx);
    }
    else if (idx < node->children.size() - 1 && node->children[idx + 1]->keys.size() >= minDegree) {
        borrowFromNext(node, idx);
    }
    else {
        if (idx < node->children.size() - 1) {
            merge(node, idx);
        }
        else {
            merge(node, idx - 1);
        }
    }
}

template <typename T>
T BTree<T>::getPredecessor(BTreeNode<T>* node, int idx) {
    BTreeNode<T>* current = node->children[idx];
    while (!current->isLeaf) {
        current = current->children[current->keys.size()];
    }
    return current->keys.back();
}

template <typename T>
T BTree<T>::getSuccessor(BTreeNode<T>* node, int idx) {
    BTreeNode<T>* current = node->children[idx + 1];
    while (!current->isLeaf) {
        current = current->children[0];
    }
    return current->keys.front();
}

template <typename T>
void BTree<T>::borrowFromPrev(BTreeNode<T>* node, int idx) {
    BTreeNode<T>* child = node->children[idx];
    BTreeNode<T>* sibling = node->children[idx - 1];

    child->keys.insert(child->keys.begin(), node->keys[idx - 1]);
    node->keys[idx - 1] = sibling->keys.back();
    sibling->keys.pop_back();

    if (!sibling->isLeaf) {
        child->children.insert(child->children.begin(), sibling->children.back());
        sibling->children.pop_back();
    }
}

template <typename T>
void BTree<T>::borrowFromNext(BTreeNode<T>* node, int idx) {
    BTreeNode<T>* child = node->children[idx];
    BTreeNode<T>* sibling = node->children[idx + 1];

    child->keys.push_back(node->keys[idx]);
    node->keys[idx] = sibling->keys.front();
    sibling->keys.erase(sibling->keys.begin());

    if (!sibling->isLeaf) {
        child->children.push_back(sibling->children.front());
        sibling->children.erase(sibling->children.begin());
    }
}

template <typename T>
void BTree<T>::merge(BTreeNode<T>* node, int idx) {
    BTreeNode<T>* child = node->children[idx];
    BTreeNode<T>* sibling = node->children[idx + 1];

    child->keys.push_back(node->keys[idx]);
    child->keys.insert(child->keys.end(), sibling->keys.begin(), sibling->keys.end());

    if (!child->isLeaf) {
        child->children.insert(child->children.end(), sibling->children.begin(), sibling->children.end());
    }

    node->keys.erase(node->keys.begin() + idx);
    node->children.erase(node->children.begin() + idx + 1);

    delete sibling;
}

template <typename T>
bool BTree<T>::isEmpty() const {
    return root == nullptr || root->keys.empty(); // El árbol está vacío si no tiene raíz o no tiene claves
}
