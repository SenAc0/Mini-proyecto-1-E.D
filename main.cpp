#include "ListArray.h"

using namespace std;

int main(){
    ListArray lista(6,7);
    lista.preOrderTraversal(lista.root);

    return 0;
}