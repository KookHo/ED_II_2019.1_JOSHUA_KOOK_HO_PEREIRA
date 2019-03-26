#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include "Tree.h"
#include <queue>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

Arv_bin * arv_cria(Nodo * raiz){
    Arv_bin * arv = (Arv_bin*)malloc(sizeof(Arv_bin));
    arv->raiz = raiz;
    return arv;
}

Nodo * arv_cria_no(char c, Nodo * esq, Nodo * dir){
    Nodo * nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo->esq = esq;
    nodo->dir = dir;
    nodo->info = c;
    return nodo;
}

void arv_print_pre(Nodo * raiz){
    printf("%c", raiz->info);
    if(raiz->esq != NULL){
        arv_print_pre(raiz->esq);
    }
    if(raiz->dir != NULL){
        arv_print_pre(raiz->dir);
    }
}

void arv_print_infixa(Nodo * raiz){
    if(raiz->esq != NULL){
        arv_print_infixa(raiz->esq);
    }
    printf("%c", raiz->info);
    if(raiz->dir != NULL){
        arv_print_infixa(raiz->dir);
    }
}

void arv_print_pos(Nodo * raiz){
    if(raiz->esq != NULL){
        arv_print_pos(raiz->esq);
    }
    if(raiz->dir != NULL){
        arv_print_pos(raiz->dir);
    }
    printf("%c", raiz->info);
}

void arv_print_formated(Nodo * raiz){
    printf("<");
    if(raiz == NULL){
        printf(">");
    }else{
        printf("%c", raiz->info);
        arv_print_formated(raiz->esq);
        arv_print_formated(raiz->dir);
        printf(">");
    }
}

void arv_free(Nodo * raiz){
    if(raiz != NULL){
       if(raiz->esq != NULL){
        arv_free(raiz->esq);
        }
        if(raiz->dir != NULL){
            arv_free(raiz->dir);
        }
    }
    free(raiz);
}

void arv_print_by_order(Arv_bin * arv, int ordem){
    switch(ordem){
        case 1:
            arv_print_pre(arv->raiz);
            break;
        case 2:
            arv_print_infixa(arv->raiz);
            break;
        case 3:
            arv_print_pos(arv->raiz);
            break;
        case 4:
            arv_print_formated(arv->raiz);
            break;
        default:
            printf("Invalid order");
            break;
    }
}

Nodo * arv_busca(Arv_bin * arv, char c){
    return arv_busca_no(arv->raiz, c);
}

Nodo * arv_busca_no(Nodo * raiz, char c){
    if (raiz == NULL){
        return NULL;
    }
    else if (raiz->info == c){
        return raiz;
    }
    else{
        Nodo * no = arv_busca_no(raiz->esq, c);
        if(no!=NULL){
            return no;
        }else
            return arv_busca_no(raiz->dir, c);
    }
}

int arv_altura(Arv_bin * arv){
    return arv_altura_no(arv->raiz);
}

int arv_altura_no(Nodo * raiz){
    if (raiz == NULL)
        return -1;
    int alt_sae = arv_altura_no(raiz->esq);
    int alt_sad = arv_altura_no(raiz->dir);
    return 1 + (alt_sae > alt_sad ? alt_sae : alt_sad);
}

int arv_pertence(Arv_bin* arv, char c){
    return arv_pertence_no(arv->raiz, c);
}

int arv_pertence_no(Nodo * raiz, char c){
    printf("%c", c);
    if(raiz == NULL)
        return 0;
    if(raiz->info == c)
        return 1;
    else if(arv_pertence_no(raiz->esq, c))
        return 1;
    else
        return arv_pertence_no(raiz->dir, c);
}

int num_no(Arv_bin * arv){
    return num_no_nodo(arv->raiz);
}

int num_no_nodo(Nodo * raiz){
    if(raiz == NULL)
        return 0;
    int a = num_no_nodo(raiz->esq);
    int b = num_no_nodo(raiz->dir);
    return 1 + (a + b);
}

void largura(Nodo * raiz){
    queue<Nodo *> fila;
    fila.push(raiz);
    while(!fila.empty()){
        Nodo *p = fila.front();
        fila.pop();
        if(p){
            printf("%c", p->info);
            fila.push(p->esq);
            fila.push(p->dir);
        }
    }
}

Arv_bin * esp(Arv_bin * arv){
    return arv_cria(esp_no(arv->raiz));
}

Nodo * esp_no(Nodo * raiz){
    if(raiz == NULL)
        return NULL;
    else{
        return arv_cria_no(raiz->info, esp_no(raiz->dir), esp_no(raiz->esq));
    }
}


void pos_alter(Arv_bin * arv){
    stack<Nodo *> P1;
    stack<Nodo *> P2;
    Nodo * aux = NULL;
    P1.push(arv->raiz);
    while(!P1.empty()){
        aux = P1.top();
        P2.push(aux);
        P1.pop();
        if(aux->esq != NULL)
            P1.push(aux->esq);
        if(aux->dir != NULL)
            P1.push(aux->dir);
    }
    while(!P2.empty()){
        printf("%c", P2.top()->info);
        P2.pop();
    }
}

string cria_string_in(Nodo * raiz){
    string inorder;
    string l;
    string r;

    if(raiz->esq != NULL){
        l += cria_string_in(raiz->esq);
    }
    inorder += raiz->info;
    if(raiz->dir != NULL){
        r += cria_string_in(raiz->dir);
    }

    return l + inorder + r;
}

string cria_string_pre(Nodo * raiz){
    string pre;

    string l;
    string r;
    if(raiz->esq != NULL){
        l += cria_string_pre(raiz->esq);
    }

    if(raiz->dir != NULL){
        r += cria_string_pre(raiz->dir);
    }
    pre += raiz->info;
    return l + r + pre;
}

Nodo * cria_no(char c){
    Nodo * no = (Nodo*)malloc(sizeof(Nodo));
    no->info = c;
    no->esq = no->dir = NULL;
    return no;
}

Nodo * construct_Tree(string pre, string in, int * pos){
    Nodo * root = cria_no(pre[*pos]);
    int r;
    r = in.find(pre[*pos]);
    string left = in.substr(0, r);
    string right = in.substr(r+1, in.length()-1);
    if(in.length() == 1) {
        return root;
    }else{
        if(root->info == in[0]){
            root->esq = NULL;
        }else{
            //cout << "Go left" << endl;
            (*pos)++;
            root->esq = construct_Tree(pre, left, pos);
        }
        if(root->info == in[in.length()-1]){
            root->dir = NULL;
        }else{
            //cout << "Go right" << endl;
            (*pos)++;
            root->esq = construct_Tree(pre, right, pos);
        }
    }
    return root;

}

Arv_bin *espelho(Arv_bin * arv){
    string preorder;
    string inorder;

    preorder = cria_string_pre(arv->raiz);
    inorder = cria_string_in(arv->raiz);

    //cout << "\nin-orderm: " << inorder;
    //cout << "\npre-orderm: " << preorder;

    reverse(inorder.begin(), inorder.end());
    reverse(preorder.begin(), preorder.end());

    //cout << "\n\npre-orderm: " << preorder;
    //cout << "\nin-orderm: " << inorder;

    int pos = 0;
    Nodo * root = construct_Tree(preorder, inorder, &pos);
    Arv_bin * mirror = arv_cria(root);
    return mirror;

}

void infixa_alter(Nodo * raiz){
    stack <Nodo *> pile;
    pile.push(raiz);
    Nodo * atual = NULL;
    while(!pile.empty()){
        atual = pile.top();
        if(atual->esq != NULL){
            pile.push(atual->esq);
            atual = pile.top();
        }
        printf("%c", atual->info);
        pile.pop();
        if(atual->dir != NULL){
            pile.push(atual->dir);
        }else{
            if(!pile.empty()){
                atual = pile.top();
                printf("%c", atual->info);
                pile.pop();
                if(atual->dir != NULL){
                    pile.push(atual->dir);
                }

            }
        }
    }
}

int leafs(Nodo * raiz){
    if(raiz == NULL){
        return 0;
    }else if( (raiz->esq == NULL) && (raiz->dir == NULL) ){
        return 1;
    }else{
        return( (leafs(raiz->esq)) + ( leafs(raiz->dir)) );
    }
}

int estritamente(Nodo * raiz){
    if( (raiz->esq == NULL) && (raiz->dir == NULL) )
        return 0;
    else if( (raiz->esq != NULL) && (raiz->dir != NULL) )
        return ( (estritamente(raiz->esq)) + (estritamente(raiz->dir)) );
    else
        return 1;
}


int completa(Nodo * raiz, int indice, int nodos){
    if(raiz == NULL)
        return 0;
    else{
        if(indice >= nodos)
            return 1;
        else
            return(completa(raiz->esq, 2*indice +1 , nodos) + completa(raiz->dir, 2*indice + 2 , nodos));
    }
}

int arv_pertence(Nodo * raiz, char c){
    if (raiz == NULL)
        return 0;
    if(raiz->info == c)
        return 1;
    else if(arv_pertence(raiz->esq, c))
        return 1;
    else
        return arv_pertence(raiz->dir, c);
}

