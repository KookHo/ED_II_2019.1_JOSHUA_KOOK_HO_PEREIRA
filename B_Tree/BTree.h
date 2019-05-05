#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#define order 3

typedef struct nodo{
    int isLeaf;
    int minDegree;
    int keys[2*order-1];
    int keyCount;
    struct nodo *C[2*order];
}Node;

typedef struct arv_b{
    Node * root;
}BTree;

BTree * createTree();
Node * searcTree(Node * root, int k);
Node * newNode(int t, int leaf);
void printTree(Node * root);
void btreeInsert(BTree * arv, int k);
void insertNonFull(Node * z, int k);
void splitChild(Node * s, int i);

#endif // BTREE_H_INCLUDED
