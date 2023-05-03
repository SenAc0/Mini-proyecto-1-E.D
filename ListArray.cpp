#include "ListArray.h"
#include <queue>
//Metodos
ListArray::ListArray(int b){
    this->b = b;
    Head = new NodeA(b);

}
ListArray::~ListArray(){
    NodeA *current = Head;
    while (current != nullptr) {
        NodeA *next = current->next;
        delete current;
        current = next;
    }
    Head = nullptr;
}
int ListArray::size(){
    return size1;

}
/*pseudocodigo
considerando b= tamaño array
             capacity = numero de elementos en el array
si el arreglo no esta lleno{
    mover todos los elementos del array 1 hacia la derecha
    insertar v en el indice 0
    aumentar numero de elementos en el array en 1
    }
en otro caso{
    crear nuevo nodo
    insertar nodo a la linked list despues de Head
    numero de elementos en el nodo = 1
    elemento en el indice 0 del nuevo nodo = ultimo elemento del arreglo del nodo Head
    repetir caso anterior (excepto por sumar 1 al numero de elementos en Head pues sigue lleno)

}
*/
void ListArray::insert_left(int v){
        if (Head->capacity < Head->b) {
            for (int i = Head->capacity; i > 0; i--) {
                Head->data[i] = Head->data[i - 1];
            }
            Head->data[0] = v;
            Head->capacity++;
        }
        else {
            NodeA* node = new NodeA(Head->b);
            node->next = Head->next;
            Head->next = node;
            node->capacity = 1;
            node->data[0] = Head->data[Head->b - 1];
            for (int i = Head->b-1; i > 0; i--) {
                Head->data[i] = Head->data[i - 1];
            }
            Head->data[0] = v;
        }
    
}
void ListArray::insert_right(int v){
    if(Head->capacity==Head->b){
        NodeA* n = new NodeA(Head->b);
        n->next = Head;
        n->data[0] = v;
        n->capacity=0;
        n->capacity = n->capacity + 1;
        Head = n;
        size1 = size1 + 1;
    }else{
        Head->data[Head->capacity] = v;
        Head->capacity = Head->capacity + 1;
        size1 = size1 + 1;
    }
}
void ListArray::insert(int v, int i){

}
void ListArray::print(){
    cout <<"Los elementos del ListArray son: "<< endl;
    while (Head != NULL) {
        for(int i=0;i<size1;i++){
            cout << Head->data[i] <<endl;
        }
        Head = Head->next;
    }
    cout << endl;
}

bool ListArray::find(int v){
    while (Head != NULL) {
        for (int i = 0; i < Head->capacity; i++) {  //si capacity no se  referia al numero de datos en el arreglo, cambiar por b
            if (Head->data[i] == v) {
                return true;
            }
        }
        Head = Head->next;
    }
    return false;
}

NodeR* ListArray::construirArbolCompleto(int altura) {
    if (altura == 0) {
        return nullptr;
    }
    NodeR* nuevoNodo = new NodeR();
    nuevoNodo->left = construirArbolCompleto(altura - 1);
    nuevoNodo->right = construirArbolCompleto(altura - 1);
    return nuevoNodo;
}
/*NodeR * ListArray::construirArbol(){
    vector<NodeR *> nodosArbol;
    return nullptr;
}*/