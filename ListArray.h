#include <iostream>
#include <math.h>
#include "ListArr.h"
#include <queue>

struct NodeA {
        int* data;
        int b;
        int capacity;
        NodeA* next;
        NodeA(int b) {
            this->b = b;
            this->data = new int[b];
            this->next = nullptr;
            this->capacity = 0;
        }
};
struct NodeR {
    int actual;
    int size;
    int b;
    NodeA *izquierda;
    NodeA *derecha;
    NodeR *left;
    NodeR *right;
    
    NodeR() {
        this->size = 0;
        this->actual = 0;
        this->b=0;
        this->izquierda = nullptr;
        this->derecha = nullptr;
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
    int numeroDeHojas;
    NodeR** hojas = new NodeR*[int(ceil(size1/2))];
    queue<NodeR*> colaDeRamas;

public:
    
    ListArray(int tamañoArreglos,int tamañoLinkedList);
    ~ListArray();
    int size();
    void insert_left(int v);
    void insert_right(int v);
    void insert(int v, int i);
    void print();
    bool find(int v);
    void ConstruirLL(int size,int tamNodeA);
    void ConstruirHojas();
    NodeR* ConstruirArbol(int height, NodeR** leaves, int size);
    //NodeR * construirArbol();
};
