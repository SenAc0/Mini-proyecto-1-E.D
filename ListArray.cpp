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
void ListArray::insert_left(int v){
        if (this->Head->capacity < this->Head->b) {
            for (int i = Head->capacity-1; i > 0; i--) {
                this->Head->data[i] = this->Head->data[i - 1];
            }
            this->Head->data[0] = v;
            this->Head->capacity++;
        }
        else {
            NodeA* node = new NodeA(Head->b);
            node->next = this->Head->next;
            this->Head->next = node;
            node->capacity = 1;
            node->data[0] = Head->data[Head->b - 1];
            for (int i = this->Head->b-1; i > 0; i--) {
                this->Head->data[i] = this->Head->data[i - 1];
            }
            this->Head->data[0] = v;
        }
        ConstruirHojas();
        this->root = ConstruirArbol(CalcularAltura(numeroDeHojas), hojas, numeroDeHojas);
    
}
void ListArray::insert_right(int v){
    if (this->tail->capacity == this->tail->b) {
        NodeA *newNode = new NodeA(this->Head->b);
        newNode->capacity = 1;
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->tail->data[this->tail->capacity] = v;
    this->tail->capacity++;
    ConstruirHojas();
    this->root = ConstruirArbol(CalcularAltura(numeroDeHojas), hojas, numeroDeHojas);
}

void ListArray::insert(int v, int i){
    NodeR* curr = this->root;
    if(i > curr->size){
        cout << "El indice no se encuentra en el array" << endl;
    }else{
        while(curr->left != nullptr){
            if(curr->left->size > i){
            
                curr = curr->left;
            }else{
                i=i-curr->left->size;
                curr = curr->right;
            }
        }
        if(curr->izquierda->capacity > i){
            if(curr->izquierda->capacity == curr->izquierda->b){
                NodeA* temp = new NodeA(curr->izquierda->b);
                temp->next = curr->izquierda->next;
                curr->izquierda->next = temp;
                temp->capacity = 1;
                temp->data[0] = curr->izquierda->data[curr->izquierda->capacity-1];
                curr->izquierda->data[curr->izquierda->capacity-1] = v;
            }else{
                for (int j = curr->izquierda->capacity-1; j > i; j--) {
                    curr->izquierda->data[j] = curr->izquierda->data[j - 1];
                }
                curr->izquierda->data[i] = v;
                curr->izquierda->capacity++;
            }
        }else{
            i=i-curr->izquierda->capacity;
            if(curr->derecha->capacity == curr->derecha->b){
                NodeA* temp = new NodeA(curr->derecha->b);
                temp->next = curr->derecha->next;
                curr->derecha->next = temp;
                temp->capacity = 1;
                temp->data[0] = curr->derecha->data[curr->derecha->capacity-1];
                curr->derecha->data[curr->derecha->capacity-1] = v;
            }else{
                for (int j = curr->derecha->capacity-1; j > i; j--) {
                    curr->derecha->data[j] = curr->derecha->data[j - 1];
                }
                curr->derecha->data[i] = v;
                curr->derecha->capacity++;
            }
        }

    }
    
    ConstruirHojas();
    this->root=ConstruirArbol(CalcularAltura(numeroDeHojas),this->hojas, numeroDeHojas);
}

void ListArray::print(){
    NodeA *curr = Head;
    cout <<"Los elementos del ListArray son: "<< endl;
    while (curr != nullptr) {
        for(int i=0;i<curr->capacity;i++){
            cout << curr->data[i] <<" ";
        }
        curr = curr->next;
    }
    cout << endl;
}

bool ListArray::find(int v){
    NodeA *curr = Head;
    while (curr != nullptr) {
        for (int i = 0; i < curr->capacity; i++) {  //si capacity no se  referia al numero de datos en el arreglo, cambiar por b
            if (curr->data[i] == v) {
                return true;
            }
        }
        curr = curr->next;
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
    this->tail = actual;
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
}

NodeR* ListArray::ConstruirArbol(int height, NodeR** hojas, int size) {
    vector<NodeR*> padres(size/2+size%2, nullptr);
    for (int i = 0; i < size; i += 2) {
        NodeR* padre = new NodeR;
        padre->left = hojas[i];
        padre->right = (i + 1 < size) ? hojas[i + 1] : nullptr;
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
    cout << raiz->size  << " ";
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
