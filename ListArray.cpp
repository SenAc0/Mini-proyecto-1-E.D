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
void ListArray::insert_left(int v){

    
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
    while(Head->next!=nullptr){
        for (int i = 0; i < Head->b; i++)
        {
            cout << Head->data[i] << endl;
        }
        Head->next;
    }

}
bool ListArray::find(int v){
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