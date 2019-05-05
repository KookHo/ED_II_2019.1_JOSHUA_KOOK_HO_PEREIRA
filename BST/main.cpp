#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include "SearchTree.h"

using namespace std;

int main(){
    Arv_bin * arv = abb_cria();
    Arv_bin * arv2 = abb_cria();
    int vet[12] = {50,30,70,20,40,60,80,15,25,35,45,36};
    int vet2[12] = {50,30,70,20,40,60,80,15,25,35,45,36};
    int i;
    for (i = 0; i < 12; i++){
        abb_insere(arv, vet[i]);
    }
    for (i = 0; i < 12; i++){
        abb_insere(arv2, vet2[i]);
    }
    printf("Arvore 1: ");
    arv_imprime(arv);
    printf("\n");
    printf("Arvore 2: ");
    arv_imprime(arv2);
    printf("\n");
    abb_remove_alter(arv, 30);
    printf("\nRemovendo da arvore 1 o elemento 30: ");
    arv_imprime(arv);
    printf("\n");
    cout << "Checando se a arvore 1 eh uma arvore binaria de busca: ";
    int a = checa_arv(arv->raiz);
    if(a != 0)
        printf("Nao eh binaria de busca\n");
    else
        printf("Eh binaria de busca\n");

    a = max_val(arv->raiz);
    printf("\nValor maximo na arvore 1: %d\n", a);

    a = min_val(arv->raiz);
    printf("\nValor minimo na arvore 1: %d\n\n", a);
/*
    int b = 0;
    int k;
    scanf("%d", &k);
    a = k_min_val(arv->raiz, &b, k);
    printf("\nK-esimo valor minimo na arvore: %d\n", a);
*/
    cout << "Checando se arvore 1 e 2 sao similares: ";
    a = similares(arv->raiz, arv2->raiz);
    if(a != 0)
        printf("Nao sao similares\n");
    else
        printf("Sao similares\n");

    cout << "\nNumero de nos com apenas 1 filho: ";
    a = filhos_unicos(arv->raiz);
    printf("%d\n", a);

    printf("\nBusca do valor 15: %p", arv_busca_no(arv->raiz, 15));

    vector<int> vetor;
    string buf;
    int input;
    cout << "\nElementos para verificar na arvore: ";

    getline(cin, buf);
    istringstream ssin(buf);
    while(ssin >> input)
    {
        vetor.push_back(input);
    }

    printf("\n");
    cout << "Checando se a sequencia esta na arvore: ";
    if(checa_sub(arv, vetor))
        cout << "Pertence\n";
    else
        cout << "Nao pertence\n";

    vetor.clear();

    cout << "\nPre-ordem para construir a arvore: ";
    getline(cin, buf);
    istringstream asd(buf);
    while(asd >> input)
    {
        vetor.push_back(input);
    }

    Arv_bin * teste = constroi(vetor);
    cout << "\nArvore: ";
    arv_imprime(teste);

    cout << "\nDigite o k-esimo menor elemento para procurar: ";
    cin >> a;
    kesimo(arv2->raiz, &a);

    arv_libera(arv);
}
