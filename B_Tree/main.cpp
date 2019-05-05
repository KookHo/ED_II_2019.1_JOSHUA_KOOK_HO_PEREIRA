#include <iostream>
#include <math.h>
#include "BTree.h"

#define order 3

using namespace std;

int main()
{
    BTree * arv = createTree();

    /*
        Exemplos de inserção
        Imprime a árvore após cada inserção
    */
    btreeInsert(arv, 10);
    printTree(arv->root);
    cout << endl;
    btreeInsert(arv, 20);
    printTree(arv->root);
    cout << endl;
    btreeInsert(arv, 5);
    printTree(arv->root);
    cout << endl;
    btreeInsert(arv, 6);
    printTree(arv->root);
    cout << endl;
    btreeInsert(arv, 12);
    printTree(arv->root);
    cout << endl;
    btreeInsert(arv, 30);
    printTree(arv->root);
    cout << endl;
    btreeInsert(arv, 7);
    printTree(arv->root);
    cout << endl;
    btreeInsert(arv, 17);
    printTree(arv->root);
    cout << endl;
    btreeInsert(arv, 18);
    printTree(arv->root);
    cout << endl;
    //Exemplo de busca (retorna NULL se não estiver na árvore
    Node * s = searcTree(arv->root, 10);
    cout << s << endl;



    //cout << arv->root->C[0]->keys[0] << endl;
   // cout << arv->root->keys[0] << endl;
    cout << arv->root->keys[0];

    return 0;
}
