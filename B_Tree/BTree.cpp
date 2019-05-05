#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "BTree.h"

#define order 3

using namespace std;

//int minDegree = (ceil(order/2))-1;

BTree * createTree(){
    BTree * arv = (BTree *)malloc(sizeof(BTree));
    arv->root = (Node *)malloc(sizeof(Node));
    arv->root->isLeaf = 1;
    arv->root->keyCount = 0;
    return arv;
}

Node * newNode(int t, int leaf){
    Node * z = (Node *)malloc(sizeof(Node));
    z->minDegree = t;
    z->isLeaf = leaf;
    z->keyCount = 0;
    return z;
}

void printTree(Node * root){
    int i;
    for(i = 0; i < root->keyCount; i++){
        if(root->isLeaf == 0)
            printTree(root->C[i]);
        cout << " . " << root->keys[i];
    }
    if(root->isLeaf == 0){
        printTree(root->C[i]);
    }
}

Node * searcTree(Node * root, int k){
    int i = 0;
    while (i < root->keyCount && k > root->keys[i])
        i++;

    if (root->keys[i] == k)
        return root;

    if (root->isLeaf)
        return NULL;

    return searcTree(root->C[i], k);
}

void btreeInsert(BTree * arv, int k){
    Node * r = arv->root;
    /*if(arv->root == NULL){
        cout << "Root is null, creating new root" << endl;
        arv->root = newNode(order, 1);
        arv->root->keys[0] = k;
        arv->root->keyCount = 1;
    }else{*/

        if(r->keyCount == 2*order-1){

            Node * s = (Node *)malloc(sizeof(Node));
            arv->root = s;
            s->isLeaf = 0;
            s->keyCount = 0;
            s->C[0] = r;

            splitChild(s, 0);
            /*int i = 0;
            if(s->keys[0] < k)
                i++;*/
            insertNonFull(s, k);

            //arv->root = s;
        }else{
            insertNonFull(r, k);
        }
    //}
}

void insertNonFull(Node * z, int k){
    int i = z->keyCount-1;

    if(z->isLeaf){
        while(i >= 0 && z->keys[i] > k){
            z->keys[i+1] = z->keys[i];
            i--;
        }
        z->keys[i+1] = k;
        z->keyCount = z->keyCount+1;
    }else{
        while(i >= 0 && z->keys[i] >k){
            i--;
        }
        i += 1;
        if(z->C[i]->keyCount == 2*order-1){
            splitChild(z, i);
            if(z->keys[i+1] < k)
                i++;
        }
        insertNonFull(z->C[i], k);
    }
}

void splitChild(Node * x, int i){
    Node * z = (Node *)malloc(sizeof(Node));
    Node * y = x->C[i];
    z->isLeaf = y->isLeaf;
    z->keyCount = order-1;
    for(int j = 0; j < order-1; j++){
        z->keys[j] = y->keys[j+order];
    }
    if(y->isLeaf == 0){
        for(int j = 0; j < order; j++){
            z->C[j] = y->C[j+order];
        }
    }
    y->keyCount = order-1;
    for(int j = x->keyCount; j >= i+1; j--){
        x->C[j+1] = x->C[j];
    }
    x->C[i+1] = z;
    for(int j = x->keyCount-1; j >= i; j--){
        x->keys[j+1] = x->keys[j];
    }
    x->keys[i] = y->keys[order-1];
    x->keyCount += 1;
}
