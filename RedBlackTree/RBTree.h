#ifndef RBTREE_H_INCLUDED
#define RBTREE_H_INCLUDED

typedef struct no{
    int info;
    struct no * left;
    struct no * right;
    struct no * parent;
    int color;
    //int isLeaf;
}Node;

typedef struct rbtree{
    Node * root;
    Node * nil;
}RBTree;

RBTree * createNewRBTree();
void printByLevel(RBTree * rbt, Node * root);
void leftRotate(RBTree * rbt, Node * root);
void rightRotate(RBTree * rbt, Node * root);
Node * newNode(int k);
void insertRBNode(RBTree * rbt, int k);
void insertFixUp(RBTree * arv, Node * z);
void rbTransplant(RBTree * rbt, Node * u, Node * v);
Node * sucessorNode(Node * root);
Node * rbSearch(RBTree * arv, Node * root, int k);
void rbDelete(RBTree * rbt, Node * z);
void rbDeleteFixUp(RBTree * rbt, Node * x);

#endif // RBTREE_H_INCLUDED
