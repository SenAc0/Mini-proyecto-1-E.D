#include <iostream>
//Clase ListArr
class ListArr{
private:
    //Intente crear un nodo para ambos nodos(ListArr, Resumen), actual es la suma de la cantidad de datos en los arreglos, b es la capacidad fija
    // int *data es el arreglo, node izq,der son los nodos: anterior a el y nodo next en el caso de los nodos ListArr
    //En el caso de los nodos Resumen son los nodos izquierda y derecha
    struct Node {
        int actual;
        int b;
        int* data;
        Node* izq;
        Node* der;
        Node(int b, Node* izq = nullptr,Node* der = nullptr) {
            this->b = b;
            data = new int[b];
            this->izq = izq;
            this->der = der;
        }
    };
    //b capacidad
    //Puntero Node* c
    int b;
    Node* c;



public:
    virtual int size()=0; //Retorna la cantidad de elementos almacenados en el ListArr
    virtual void insert_left(int v)=0; //Inserta un nuevo valor v a la izquierda del ListArr. Equivalentemente, inserta el valor v en el índice 0
    virtual void insert_right(int v)=0; //Inserta un nuevo valor v a la derecha del ListArr. Equivalentemente, inserta el valor v en el índice size()-1
    virtual void insert(int v, int i)=0; //Inserta un nuevo valor v en el índice i del ListArr.
    virtual void print()=0; //Imprime por pantalla todos los valores almacenados en el ListArr.
    virtual bool find(int v)=0; //Busca en el ListArr si el valor v se encuentra almacenado.
};