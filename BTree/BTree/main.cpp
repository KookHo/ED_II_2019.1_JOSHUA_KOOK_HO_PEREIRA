#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Tree.h"
using namespace std;

int main(){
    Arv_bin * arv = arv_cria(
                        arv_cria_no('a',
                                arv_cria_no('b',
                                        arv_cria_no('g', NULL, NULL),
                                        NULL ),
                                arv_cria_no('c',
                                        arv_cria_no('e', NULL, NULL),
                                        arv_cria_no('f', NULL, NULL)
                                        )
                                    )
                             );

    printf("Selecione uma ordem:\n1-Pre-ordem\n2-Infixa\n3-Pos-ordem\nOpção: ");
    int a;
    int ind = 0;
    char c;
    scanf("%d", &a);
    arv_print_by_order(arv, a);
    printf("\n\nIn-ordem iterativo: ");
    infixa_alter(arv->raiz);
    printf("\n\nPos-ordem iterativo: ");
    pos_alter(arv);
    printf("\n\nSelecione uma letra de a até f: ");
    scanf(" %c", &c);
    if (arv_pertence(arv->raiz, c) > 0)
        printf("\nElemento pertence a arvore");
    else
        printf("\n\nElemento não pertence a arvore");
    printf("\nLocal do item buscado: %p", arv_busca(arv, c));
    printf("\n\nAltura da arvore: %d", arv_altura(arv));
    a = num_no(arv);
    printf("\n\nNumero de nos na arvora: %d", a);
    printf("\n\nArvore Binária completa? : ");
    if( completa(arv->raiz, ind, a) > 0)
        printf("Não");
    else
        printf("Sim");

    printf("\n\nArvore por Largura: ");
    largura(arv->raiz);
    a = leafs(arv->raiz);
    printf("\n\nNumero de folhas: %d", a);

    Arv_bin * arv2 = esp(arv);
    a = estritamente(arv->raiz);
    cout<<"\n\nEstritamente binária? : ";
    if(a != 0)
        cout << "não" << endl;
    else
        cout << "sim" << endl;
    //Arv_bin * arv3 = espelho(arv);

    printf("\n\nSelecione uma ordem para a arvore espelhada:\n1-Pre-ordem\n2-Infixa\n3-Pos-ordem\nOpção: ");
    scanf("%d", &a);
    arv_print_by_order(arv2, a);
    //printf("\nArvore espelhada(preordem): ");
    //arv_print_by_order(arv3, 1);
    arv_free(arv2->raiz);
    //arv_free(arv3->raiz);
    arv_free(arv->raiz);


}
