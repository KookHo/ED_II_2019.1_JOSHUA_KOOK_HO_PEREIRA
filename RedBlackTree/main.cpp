#include <iostream>
#include <stdlib.h>
#include "RBTree.h"
#define RED 1
#define BLACk 0

using namespace std;

int main(){

    RBTree * ArvRB = createNewRBTree();
    insertRBNode(ArvRB, 3);
    insertRBNode(ArvRB, 6);
    insertRBNode(ArvRB, 1);
    insertRBNode(ArvRB, 8);
    insertRBNode(ArvRB, 4);
    printByLevel(ArvRB, ArvRB->root);
    cout << "all good" << endl;
    //cout << rbSearch(ArvRB, ArvRB->root, 2) <<endl;
    Node * z = rbSearch(ArvRB, ArvRB->root, 6);
    rbDelete(ArvRB, z);
    printByLevel(ArvRB, ArvRB->root);
    z = rbSearch(ArvRB, ArvRB->root, 3);
    rbDelete(ArvRB, z);
    printByLevel(ArvRB, ArvRB->root);
    cout << endl;
    insertRBNode(ArvRB, 9);
    printByLevel(ArvRB, ArvRB->root);
    cout << endl;
    insertRBNode(ArvRB, 7);
    printByLevel(ArvRB, ArvRB->root);
    cout << endl;
    insertRBNode(ArvRB, 69);
    printByLevel(ArvRB, ArvRB->root);
    cout << endl;
    insertRBNode(ArvRB, 91);
    printByLevel(ArvRB, ArvRB->root);
    cout << endl;
    insertRBNode(ArvRB, 119);
    printByLevel(ArvRB, ArvRB->root);
    cout << endl;
    insertRBNode(ArvRB, 98);
    printByLevel(ArvRB, ArvRB->root);
    //printByLevel(ArvRB, ArvRB->root);
    return 0;
}
