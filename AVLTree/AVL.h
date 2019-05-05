#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

using namespace std;

typedef struct no{
    int info;
    struct no * esq;
    struct no * dir;
    int h;
}Nodo;

typedef struct arv_bal{
    Nodo * raiz;
}Arv_bal;

Arv_bal * avl_cria();
void arv_imprime(Arv_bal * arv);
void arv_imprime_no(Nodo * raiz);
Nodo * insertNode(Nodo * raiz, int k);
Nodo * newNode(int a);
Nodo * rightRotation(Nodo * raiz);
Nodo * leftRotation(Nodo * raiz);
int balance_factor(Nodo * p);
Nodo * removeNode(Nodo * raiz, int k);
int height(Nodo * p);
int maxim(int a, int b);


#endif // AVL_H_INCLUDED
