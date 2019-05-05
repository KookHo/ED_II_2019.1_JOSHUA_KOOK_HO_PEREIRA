#include <iostream>
#include <stdlib.h>
#include "AVL.h"

using namespace std;

Arv_bal * avl_cria(){
    Arv_bal * arv = (Arv_bal*)malloc(sizeof(Arv_bal));
    arv->raiz = NULL;
    return arv;
}

void arv_imprime(Arv_bal * arv){
    arv_imprime_no(arv->raiz);
}

void arv_imprime_no(Nodo * raiz){
    if(raiz != NULL){
        arv_imprime_no(raiz->esq);
        printf(" %d ", raiz->info);
        arv_imprime_no(raiz->dir);
    }
}

Nodo * insertNode(Nodo * raiz, int k){
    if(raiz == NULL)
        return newNode(k);

    if( k < raiz->info)
        raiz->esq = insertNode(raiz->esq, k);
    else if (k > raiz->info)
        raiz->dir = insertNode(raiz->dir, k);
    else
        return raiz;

    raiz->h = 1 + maxim(height(raiz->esq), height(raiz->dir));

    int bf = balance_factor(raiz);

    if(bf < -1 && k < raiz->esq->info)
        return rightRotation(raiz);

    if(bf < -1 && k > raiz->esq->info){
        raiz->esq = leftRotation(raiz->esq);
        return rightRotation(raiz);
    }

    if(bf > 1 && k > raiz->esq->info)
        return leftRotation(raiz);

    if(bf > 1 && k < raiz->esq->info){
        raiz->dir = rightRotation(raiz->dir);
        return leftRotation(raiz);
    }

    return raiz;

}

Nodo * removeNode(Nodo * raiz, int k){
    if(raiz == NULL)
        return NULL;
    else if (k < raiz->info)
        raiz->esq = removeNode(raiz->esq, k);
    else if (k > raiz->info)
        raiz->dir = removeNode(raiz->dir, k);
    else{
        if(raiz->esq == NULL && raiz->dir == NULL){
            free(raiz);
            raiz = NULL;
        }
        else if(raiz->esq == NULL){
            Nodo * aux = raiz;
            raiz = raiz->dir;
            free(aux);
        }
        else if(raiz->dir == NULL){
            Nodo * aux = raiz;
            raiz = raiz->esq;
            free(aux);
        }
        else{
            Nodo * aux = raiz->esq;
            while( aux->dir != NULL){
                aux = aux->dir;
            }

            raiz->info = aux->info;
            aux->info = k;
            raiz->esq = removeNode(raiz->esq, k);
        }
    }
    if(raiz == NULL)
        return raiz;

    raiz->h = 1 + maxim(height(raiz->esq), height(raiz->dir));

    int bf = balance_factor(raiz);

    if(bf < -1 && balance_factor(raiz->esq) <= 0)
        return rightRotation(raiz);
    if(bf < -1 && balance_factor(raiz->esq) > 0){
        raiz->esq = leftRotation(raiz->esq);
        return rightRotation(raiz);
    }
    if(bf > 1 && balance_factor(raiz->dir) >= 0)
        return leftRotation(raiz);
    if(bf > 1 && balance_factor(raiz->dir) < 0){
        raiz->dir = rightRotation(raiz->dir);
        return leftRotation(raiz);
    }

    return raiz;
}

Nodo * rightRotation(Nodo * raiz){
    Nodo * x = raiz->esq;
    Nodo * z = raiz->esq->dir;

    x->dir = raiz;
    raiz->esq = z;

    raiz->h = 1 + maxim(height(raiz->esq), height(raiz->dir));
    x->h = 1 + maxim(height(x->esq), height(x->dir));

    return x;
}

int height(Nodo * p){
    if (p == NULL)
        return -1;
    return p->h;
}

int maxim(int a, int b){
    return (a > b) ? a : b;
}

Nodo * leftRotation(Nodo * raiz){
    Nodo * y = raiz->dir;
    Nodo * z = raiz->dir->esq;

    y->esq = raiz;
    raiz->dir = z;

    raiz->h = 1 + maxim(height(raiz->esq), height(raiz->dir));
    y->h = 1 + maxim(height(y->esq), height(y->dir));

    return y;
}

int balance_factor(Nodo * p){
    if(p == NULL)
        return 0;
    return height(p->dir) - height(p->esq);
}

Nodo * newNode(int a){
    Nodo * node = (Nodo *)malloc(sizeof(Nodo));
    node->info = a;
    node->esq = node->dir = NULL;
    node->h = 0;
    return node;
}
