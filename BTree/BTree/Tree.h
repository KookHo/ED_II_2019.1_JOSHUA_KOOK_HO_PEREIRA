#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct no {
    char info;
    struct no *esq;
    struct no *dir;
}Nodo;

typedef struct arv_bin{
    Nodo * raiz;
}Arv_bin;

Arv_bin *arv_cria(Nodo * raiz);
Nodo * arv_cria_no(char c, Nodo * esq, Nodo * dir);
void arv_print_pre(Nodo * raiz);
void arv_print_infixa(Nodo * raiz);
void arv_print_pos(Nodo * raiz);
void arv_print_by_order(Arv_bin * arv, int ordem);
Nodo * arv_busca(Arv_bin * arv, char c);
Nodo * arv_busca_no(Nodo * raiz, char c);
int arv_altura(Arv_bin * arv);
int arv_altura_no(Nodo * raiz);
int arv_pertence_no(Nodo * raiz, char c);
int arv_pertence(Arv_bin* arv, char c);
int num_no(Arv_bin * arv);
int num_no_nodo(Nodo * raiz);
Arv_bin *espelho(Arv_bin arv);
void arv_free(Nodo * raiz);
void largura(Nodo *raiz);
Arv_bin *espelho(Arv_bin * arv);
Arv_bin * esp(Arv_bin * arv);
Nodo * esp_no(Nodo * raiz);
void pos_alter(Arv_bin * arv);
void infixa_alter(Nodo * raiz);
int leafs(Nodo * raiz);
int estritamente(Nodo * raiz);
int completa(Nodo * raiz, int indice, int nodos);
int arv_pertence(Nodo * raiz, char c);

#endif // TREE_H_INCLUDED
