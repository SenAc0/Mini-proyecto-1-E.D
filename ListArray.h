#include <iostream>
#include "ListArr.h"
//Clase ListArray
class ListArray: public ListArr{
private:
    struct NodeA {
        int* data;
        int b;
        int capacity;
        NodeA* next;
        NodeA(int b) {
            this->b = b;
            data = new int[b];
            next = nullptr;
            capacity = 0;
        }
    };
    struct NodeR {
    int actual;
    int size;
    Node* left;
    Node* right;
    ListArr::NodeA* list_node; // puntero al nodo de ListArr correspondiente
    
    NodeR() {
        this->size = 0;
        this->actual = 0;
        this->left = nullptr;
        this->right = nullptr;
        this->list_node = nullptr;
    }
};
    NodeA* Head;
    NodeR* root;
    int cNodos;
    int size;

public:
    int size();
    void insert_left(int v);
    void insert_right(int v);
    void insert(int v, int i);
    void print()=;
    bool find(int v);
    //NodeR construirArbol(ListArr input,NodeR* root);
};
