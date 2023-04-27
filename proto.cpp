#include <iostream>

class ListArr {
public:
    struct Node {
        int* data;
        int b;
        Node* izq;
        Node* der;
        Node(int b) {
            this->b = b;
            data = new int[b];
            izq = nullptr;
            der = nullptr;
        }
    };
    Node* Head;
    Node* Tail;

    int size();
    void insert_left(int v);
    void insert_right(int v);
    void insert(int v, int i);
    void print();
    bool find(int v);
};

class Arbol {
public:
    struct Node {
        int actual;
        int size;
        Node* left;
        Node* right;
        ListArr::Node* list_node; // puntero al nodo de ListArr correspondiente
        
        Node(int b, ListArr::Node* list_node = nullptr, Node* left = nullptr, Node* right = nullptr) {
            size = b;
            actual = 0;
            this->left = left;
            this->right = right;
            this->list_node = list_node;
        }
    };
    Node* root;

    Arbol() {
        root = nullptr;
    }

    Node* construirArbol(ListArr input) {
        // Crear una cola para guardar los nodos del árbol mientras se construye
        std::queue<Node*> q;

        // Crear la raíz del árbol
        int n = input.size();
        root = new Node(n, &input.Head[n - 1]);

        // Agregar la raíz a la cola
        q.push(root);

        // Mientras hayan nodos en la cola
        while (!q.empty()) {
            // Sacar el primer nodo de la cola
            Node* curr = q.front();
            q.pop();

            // Si el nodo actual tiene hijos, agregarlos a la cola
            if (curr->left) {
                curr->left->list_node = curr->list_node->izq;
                q.push(curr->left);
            }
            if (curr->right) {
                curr->right->list_node = curr->list_node->der;
                q.push(curr->right);
            }
        }

        return root;
    }
};
