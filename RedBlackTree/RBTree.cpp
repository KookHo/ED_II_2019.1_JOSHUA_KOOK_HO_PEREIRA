#include <iostream>
#include <stdlib.h>
#include <queue>
#include "RBTree.h"
#define RED 1
#define BLACK 0

using namespace std;

RBTree * createNewRBTree(){
    RBTree * arv = (RBTree *)malloc(sizeof(RBTree));

    arv->nil = (Node *)malloc(sizeof(Node));
    arv->nil->color = BLACK;
    arv->root = arv->nil;
    cout<<"Tree Created"<<endl;
    return arv;
}

void printByLevel(RBTree * rbt, Node * root){
    if (root == rbt->nil)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
        Node *temp = q.front();
        cout << temp->info << " Color: " << temp->color << " | ";
        q.pop();

        if (temp->left != rbt->nil)
            q.push(temp->left);

        if (temp->right != rbt->nil)
            q.push(temp->right);
    }
}

Node * newNode(RBTree * rbt, int k){
    Node * z = (Node *)malloc(sizeof(Node));
    z->color = RED;
    z->info = k;
    z->left = z->right = z->parent = rbt->nil;
    return z;
}

void insertRBNode(RBTree * rbt, int k){
    Node * z = newNode(rbt, k);
    Node * y = rbt->nil;
    Node * x = rbt->root;
    //cout<<"now inserting"<<endl;
    while(x != rbt->nil){
       // cout<<"root is not null"<<endl;
        y = x;
        if(z->info < x->info)
            x = x->left;
        else
            x = x->right;
    }
    //cout<<"now adjusting"<<endl;
    z->parent = y;
    if(y == rbt->nil)
        rbt->root = z;
    else if(z->info < y->info)
        y->left = z;
    else
        y->right = z;
    z->left = rbt->nil;
    z->right = rbt->nil;
    z->color = RED;
    //cout<<"proceeding to fixup"<<endl;
    insertFixUp(rbt, z);
}

void insertFixUp(RBTree * arv, Node * z){
    //cout<<"Node color: "<<z->color<<endl;
    while(z->parent->color == RED){
        if(z->parent == z->parent->parent->left){
            //cout<<"uncle is on the right"<<endl;
            Node * y = z->parent->parent->right;
            if(y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }else{
                if(z == z->parent->right){
                    z = z->parent;
                    leftRotate(arv, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(arv, z->parent->parent);
            }
        }else{
            //cout<<"uncle is on the left"<<endl;
            Node * y = z->parent->parent->left;
            if(y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }else{
                if(z == z->parent->left){
                    z = z->parent;
                    rightRotate(arv, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(arv, z->parent->parent);
            }
        }
    }
    //cout<<"returning"<<endl;
    arv->root->color = BLACK;
}


void leftRotate(RBTree * rbt, Node * x){
    Node * y = x->right;
    x->right = y->left;
    if (y->left != rbt->nil)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == rbt->nil)
        rbt->root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rightRotate(RBTree * rbt, Node * x){
    Node * y = x->left;
    x->left = y->right;
    if (y->right != rbt->nil)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == rbt->nil)
        rbt->root = y;
    else if(x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    y->right = x;
    x->parent = y;
}

void rbTransplant(RBTree * rbt, Node * u, Node * v){
    if(u->parent == rbt->nil)
        rbt->root = v;
    else if(u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

Node * sucessorNode(RBTree * rbt, Node * root){
    while(root->left != rbt->nil){
        root = root->left;
    }
    cout << root->color << endl;
    return root;
}

void rbDelete(RBTree * rbt, Node * z){
    Node * y = z;
    Node * x = NULL;
    int yOriginalColor = y->color;
    if(z->left == rbt->nil){
        cout << "node has no left child" <<endl;
        x = z->right;
        rbTransplant(rbt, z, z->right);
    }else if(z->right == rbt->nil){
        cout << "node has no right child" <<endl;
        x = z->left;
        rbTransplant(rbt, z, z->left);
    }else{
        cout << "node has both child" <<endl;
        y = sucessorNode(rbt, z->right);
        cout << "sucessor: " << y->info << endl;
        yOriginalColor = y->color;
        x = y->right;
        if(y->parent == z)
            x->parent = y;
        else{
            rbTransplant(rbt, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rbTransplant(rbt, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    cout << "apply fixup" << endl;
    if(yOriginalColor == BLACK)
        rbDeleteFixUp(rbt, x);
}

Node * rbSearch(RBTree * arv, Node * root, int k){
    if(root == arv->nil || root->info == k)
        return root;
    if (k < root->info)
        return rbSearch(arv, root->left, k);
    else
        return rbSearch(arv, root->right, k);
}

void rbDeleteFixUp(RBTree * rbt, Node * x){
    Node * w = (Node*)malloc(sizeof(Node));
    while(x != rbt->root && x->color == BLACK){
        if(x == x->parent->left){
            w = x->parent->right;
            if(w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(rbt, x->parent);
                w = x->parent->right;
            }
            if(w->left->color == BLACK && w->right->color == BLACK){
                w->color = RED;
                x = x->parent;
            }else{
                if(w->right->color == BLACK){
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(rbt, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(rbt, x->parent);
                x = rbt->root;
            }
        }else{
            w = x->parent->left;
            if(w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(rbt, x->parent);
                w = x->parent->left;
            }
            if(w->right->color == BLACK && w->left->color == BLACK){
                w->color = RED;
                x = x->parent;
            }else{
                if(w->left->color == BLACK){
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(rbt, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(rbt, x->parent);
                x = rbt->root;
            }
        }
    }
    x->color = BLACK;
}
