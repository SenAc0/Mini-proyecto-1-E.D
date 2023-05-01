#include <iostream>
#include "ListArr.h"
//Clase ListArray
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
    NodeR *left;
    NodeR *right;
    
    NodeR() {
        this->size = 0;
        this->actual = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class ListArray: public ListArr{
private:
    NodeA* Head;
    NodeR* root;
    int b;
    int size1;

public:
    ListArray(int b);
    ~ListArray();
    int size();
    void insert_left(int v);
    void insert_right(int v);
    void insert(int v, int i);
    void print();
    bool find(int v);
    NodeR * construirArbol();
    //NodeR construirArbol(ListArr input,NodeR* root);
};
