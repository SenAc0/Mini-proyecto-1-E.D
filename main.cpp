#include "ListArray.h"

using namespace std;

int main(){
    ListArray lista(6,10);
    lista.preOrderTraversal(lista.root);

    return 0;
}