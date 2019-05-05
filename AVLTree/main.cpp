#include <iostream>
#include <stdlib.h>
#include "AVL.h"

using namespace std;

int main(){
    Arv_bal * arv = avl_cria();
    arv->raiz = insertNode(arv->raiz, 3);
    printf(" %d\n", arv->raiz->info);
    arv->raiz = insertNode(arv->raiz, 2);
    arv->raiz = insertNode(arv->raiz, 1);
    //arv->raiz = removeNode(arv->raiz, 10);
    printf(" %d\n", arv->raiz->info);
    arv_imprime(arv);
}
