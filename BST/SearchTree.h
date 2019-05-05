#ifndef SEARCHTREE_H_INCLUDED
#define SEARCHTREE_H_INCLUDED

using namespace std;

typedef struct no{
    int info;
    struct no *esq;
    struct no *dir;
}Nodo;

typedef struct arv_bin{
    Nodo * raiz;
}Arv_bin;

Arv_bin * abb_cria();
void arv_imprime(Arv_bin * arv);
void arv_imprime_no(Nodo * raiz);
void arv_libera(Arv_bin * arv);
void arv_libera_no(Nodo * raiz);
Nodo * arv_busca_no(Nodo * raiz, int c);
Nodo * arv_busca_no_alter(Nodo * raiz, int c);
void abb_insere(Arv_bin * arv, int c);
Nodo * insere_nodo(Nodo * raiz, int c);
void abb_remove(Arv_bin * arv, int c);
Nodo * remove_nodo(Nodo * raiz, int c);
void abb_remove_alter(Arv_bin * arv, int c);
Nodo * remove_nodo_alter(Nodo * raiz, int c);
int checa_arv(Nodo * raiz);
int max_val(Nodo * raiz);
int min_val(Nodo * raiz);
int k_min_val(Nodo * raiz, int *aux, int k);
int num_no_nodo(Nodo * raiz);
int similares(Nodo * raiz1, Nodo * raiz2);
int filhos_unicos(Nodo * raiz);
bool checa_sub(Arv_bin * arv, vector<int> &vet);
Arv_bin * constroi(vector<int> &vet);
void kesimo(Nodo * raiz, int * k);

#endif // SEARCHTREE_H_INCLUDED
