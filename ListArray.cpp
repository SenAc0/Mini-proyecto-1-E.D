#include "ListArr.h"
#include <queue>
//Metodos
ListArr::ListArr(int b){
    this->b = b;
    Head = new NodeA(b);

}
ListArr::~ListArr(){
    Node* current = Head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    Head = nullptr;
}
int ListArr::size(){
    return size;

}
void ListArr::insert_left(int v){
    /*if(Head->capacity==Head->b){
        NodeA* n = new NodeA(Head->b);
        n->data[0] = int v
        Head->next = Head;
        Head = n;
    }*/
    
}
void ListArr::insert_right(int v){
    if(Head->capacity==Head->b){
        NodeA* n = new NodeA(Head->b);
        n->next = Head;
        n->data[capacity] = v;
        n->capacity = n->capacity + 1;
        Head = n;
        size = size + 1;
    }else{
        Head->data[capacity] = v;
        Head->capacity = Head->capacity + 1;
        size = size + 1;
    }
}
void ListArr::insert(int v, int i){

}
void ListArr::print(){

}
bool ListArr::find(int v){

}
/*
Node ListArr::construirArbol(ListArr lista, Node* root){
    int n = lista.size();
    queue<Node*> q;
    root = new Node();
    q.push(root;)
    //a

}*/