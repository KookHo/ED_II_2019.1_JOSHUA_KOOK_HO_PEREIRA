#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include "SearchTree.h"

using namespace std;


Arv_bin * abb_cria(){
    Arv_bin * arv = (Arv_bin*)malloc(sizeof(Arv_bin));
    arv->raiz = NULL;
    return arv;
}

void arv_imprime(Arv_bin * arv){
    arv_imprime_no(arv->raiz);
}

void arv_imprime_no(Nodo * raiz){
    if(raiz != NULL){
        arv_imprime_no(raiz->esq);
        printf(" %d ", raiz->info);
        arv_imprime_no(raiz->dir);
    }
}

void arv_libera(Arv_bin * arv){
    arv_libera_no(arv->raiz);
    free(arv);
}

void arv_libera_no(Nodo * raiz){
    if(raiz != NULL){
        arv_libera_no(raiz->esq);
        arv_libera_no(raiz->dir);
        free(raiz);
    }
}

void kesimo(Nodo * raiz, int * k){
    if(raiz != NULL){
        kesimo(raiz->esq, k);
        (*k)--;
        if(*k == 0){
            printf("K-esimo menor elemento: %d", raiz->info);
            (*k)--;
        }
        kesimo(raiz->dir, k);
    }
}

Nodo * arv_busca_no(Nodo * raiz, int c){
    if(raiz == NULL || raiz->info == c)
        return raiz;
    if (c < raiz->info)
        return arv_busca_no(raiz->esq, c);
    else
        return arv_busca_no(raiz->dir, c);
}

Nodo * arv_busca_no_alter(Nodo * raiz, int c){
    while(raiz != NULL && raiz->info != c){
        if (c < raiz->info)
            raiz = raiz->esq;
        else
            raiz = raiz->dir;
    }
    return raiz;
}

void abb_insere(Arv_bin * arv, int c){
    arv->raiz = insere_nodo(arv->raiz, c);
}

Nodo * insere_nodo(Nodo * raiz, int c){
    if(raiz == NULL){
        raiz = (Nodo *)malloc(sizeof(Nodo));
        raiz->info = c;
        raiz->esq = raiz->dir = NULL;
    }else if (c < raiz->info)
        raiz->esq = insere_nodo(raiz->esq, c);
    else
        raiz->dir = insere_nodo(raiz->dir, c);
    return raiz;
}

void abb_remove(Arv_bin * arv, int c){
    arv->raiz = remove_nodo(arv->raiz, c);
}

Nodo * remove_nodo(Nodo * raiz, int c){
    if(raiz == NULL)
        return NULL;
    else if (c < raiz->info)
        raiz->esq = remove_nodo(raiz->esq, c);
    else if (c > raiz->info)
        raiz->dir = remove_nodo(raiz->dir, c);
    else{
        if(raiz->esq == NULL && raiz->dir == NULL){
            free(raiz);
            raiz = NULL;
        }else if(raiz->esq == NULL){
            Nodo * aux = raiz;
            raiz = raiz->dir;
            free(aux);
        }else if(raiz->dir == NULL){
            Nodo * aux = raiz;
            raiz = raiz->esq;
            free(aux);
        }
        else{
            Nodo * aux = raiz->esq;
            while(aux->dir != NULL){
                aux = aux->dir;
            }

            raiz->info = aux->info;
            aux->info = c;
            raiz->esq = remove_nodo(raiz->esq, c);
        }
    }
    return raiz;
}

void abb_remove_alter(Arv_bin * arv, int c){
    arv->raiz = remove_nodo_alter(arv->raiz, c);
}

Nodo * remove_nodo_alter(Nodo * raiz, int c){
    if(raiz == NULL)
        return NULL;
    else if (c < raiz->info)
        raiz->esq = remove_nodo(raiz->esq, c);
    else if (c > raiz->info)
        raiz->dir = remove_nodo(raiz->dir, c);
    else{
        if(raiz->esq == NULL && raiz->dir == NULL){
            free(raiz);
            raiz = NULL;
        }else if(raiz->esq == NULL){
            Nodo * aux = raiz;
            raiz = raiz->dir;
            free(aux);
        }else if(raiz->dir == NULL){
            Nodo * aux = raiz;
            raiz = raiz->esq;
            free(aux);
        }
        else{
            Nodo * aux = raiz->dir;
            while(aux->esq != NULL){
                aux = aux->esq;
            }

            raiz->info = aux->info;
            aux->info = c;
            raiz->dir = remove_nodo(raiz->dir, c);
        }
    }
    return raiz;
}

int checa_arv(Nodo * raiz){
    if(raiz == NULL){
        return 0;
    }
    else if(raiz->esq == NULL && raiz->dir == NULL)
        return 0;
    else{
        if(raiz->esq == NULL){
            if(raiz->dir->info > raiz->info)
                return 0 + checa_arv(raiz->dir);
            else
                return 1;
        }else if(raiz->dir == NULL){
            if(raiz->esq->info < raiz->info)
                return 0 +checa_arv(raiz->esq);
            else
                return 1;
        }else{
            if(raiz->esq->info < raiz->info && raiz->dir->info >= raiz->info)
                return 0 + checa_arv(raiz->esq) + checa_arv(raiz->dir);
            else
                return 1;
        }
    }
}

int max_val(Nodo * raiz){
    if(raiz == NULL)
        return NULL;
    else if(raiz->dir == NULL)
        return raiz->info;
    else
        return max_val(raiz->dir);
}

int min_val(Nodo * raiz){
    if(raiz == NULL)
        return NULL;
    else if(raiz->esq == NULL)
        return raiz->info;
    else{
        Nodo * aux = raiz;
        while(aux->esq != NULL){
            aux = aux->esq;
        }
        return aux->info;
    }
}

int num_no_nodo(Nodo * raiz){
    if(raiz == NULL)
        return 0;
    int a = num_no_nodo(raiz->esq);
    int b = num_no_nodo(raiz->dir);
    return 1 + (a + b);
}

/*int k_min_val(Nodo * raiz, int * aux,int k){
}*/

int similares(Nodo * raiz1, Nodo * raiz2){
    if(raiz1 == NULL && raiz2 == NULL)
        return 0;
    else if( (raiz1 == NULL && raiz2 != NULL) || (raiz1 != NULL && raiz2 == NULL) )
        return 1;
    else if(raiz1->info != raiz2->info)
        return 1;
    else{
        return 0 + similares(raiz1->esq, raiz2->esq) + similares(raiz1->dir, raiz2->dir);
    }

}

int filhos_unicos(Nodo * raiz){
    if(raiz == NULL)
        return 0;
    else if(raiz->esq == NULL && raiz->dir == NULL)
        return 0;
    else{
        if(raiz->esq == NULL)
            return 1 + filhos_unicos(raiz->dir);
        else if(raiz->dir == NULL)
            return 1 + filhos_unicos(raiz->esq);
        else
            return 0 + filhos_unicos(raiz->esq) + filhos_unicos(raiz->dir);
    }
}

bool checa_sub(Arv_bin * arv, vector<int>& vet){
    int i;
    int a = 0;
    Nodo * aux = (Nodo *)malloc(sizeof(Nodo));
    for( i = 0; i < (int)vet.size(); i++ ){
        aux = arv_busca_no(arv->raiz, vet[i]);
        if (aux != NULL)
            a++;
    }
    if(a == (int)vet.size())
        return true;
    else
        return false;
}

Arv_bin * constroi(vector<int> &vet){
    Arv_bin * arvc = abb_cria();
    int i;
    for(i = 0; i < (int)vet.size(); i++){
        abb_insere(arvc, vet[i]);
    }
    return arvc;
}
