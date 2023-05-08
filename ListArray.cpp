#include "ListArray.h"
#include <vector>

ListArray::ListArray(int tamañoArreglos,int tamañoLinkedList){
    ConstruirLL(tamañoLinkedList, tamañoArreglos);
    ConstruirHojas();
    this->root=ConstruirArbol(CalcularAltura(numeroDeHojas),this->hojas, numeroDeHojas);
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


void ListArray::ConstruirLL(int size, int tamNodeA){
    this->Head = new NodeA(tamNodeA);
    NodeA* actual = this->Head;
    for (int i = 1; i < size; i++) {
        actual->next = new NodeA(tamNodeA);
        actual = actual->next;
    }
}

void ListArray::ConstruirHojas(){
    int i=0;
    NodeR* cabezaR = new NodeR();
    NodeR* actualR = cabezaR;
    NodeA* actual = this->Head;
    while (actual != nullptr && actual->next != nullptr) {
        NodeR* Hoja = new NodeR();
        Hoja->izquierda = actual;
        Hoja->derecha = actual->next;
        Hoja->size = actual->capacity + actual->next->capacity;
        Hoja->b = actual->b + actual->next->b;
        this->hojas[i]=Hoja;
        i++;
        actual = actual->next->next;
        
    }
    if (actual != nullptr && actual->next == nullptr) {
        NodeR* Hoja = new NodeR();
        Hoja->izquierda = actual;
        Hoja->size = actual->capacity;
        Hoja->b = actual->b;
        this->hojas[i]=Hoja;
        i++;
    }
    this->numeroDeHojas = i;
    for(int j=0;j<i;j++){
        this->colaDeRamas.push(this->hojas[j]);
    }
}

NodeR* ListArray::ConstruirArbol(int height, NodeR** leaves, int size) {
    vector<NodeR*> padres(size / 2 + size % 2, nullptr);
    for (int i = 0; i < size; i += 2) {
        NodeR* padre = new NodeR;
        padre->left = leaves[i];
        padre->right = (i + 1 < size) ? leaves[i + 1] : nullptr;
        if(padre->right == nullptr){
            padre->b = padre->left->b;
            padre->size = padre->left->size;
        }else{
            padre->b = padre->left->b + padre->right->b;
            padre->size = padre->left->size + padre->right->size;
        }
        padres[i / 2] = padre;
    }
    
    while (padres.size() > 1) {
        int n = padres.size();
        vector<NodeR*> newPadres(n / 2 + n % 2, nullptr);
        for (int i = 0; i < n; i += 2) {
            NodeR* padre = new NodeR;
            padre->left = padres[i];
            padre->right = (i + 1 < n) ? padres[i + 1] : nullptr;
            if(padre->right == nullptr){
                padre->b = padre->left->b;
                padre->size = padre->left->size;
            }else{
                padre->b = padre->left->b + padre->right->b;
                padre->size = padre->left->size + padre->right->size;
            }
            newPadres[i / 2] = padre;
        }
        padres = move(newPadres);
    }
    
    return padres[0];
}

void ListArray::preOrderTraversal(NodeR* raiz) {
  if (raiz != nullptr) {
    cout << raiz->b << " ";
    preOrderTraversal(raiz->left);
    preOrderTraversal(raiz->right);
  }
}

int ListArray::CalcularAltura(int actual){
   if (actual <= 2) {
        return 1;
    }
    int count = 0;
    while (actual > 1) {
        if (actual % 2 == 0) {
            actual /= 2;
            count++;
        } else {
            actual = ceil((double)actual / 2.0);
            count++;
        }
    }
    return count;
}