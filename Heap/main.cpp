#include <iostream>
#include <array>
#include <climits>
#include "heap.h"

using namespace std;

int main(){
    int tam;

    cout << "Digite o numero de elementos do vetor: ";
    cin >> tam;

    Heap * A = initialize_heap(tam);

    cout << "Digite os elementos: ";

    for(int i = 1; i <= tam; i++){
        cin >> A->v[i];
        A->heap_size++;
    }

    build_max_heap(A);
    cout << endl;
    cout << "--heap max: " << heap_max(A) << endl;
    cout << "--heap max extract: " << endl;
    heap_max_extract(A);
    cout << "--after extraction: " << endl;
    printA(A);
    cout << endl;
    cout << "--inserting key 8: " << endl;
    mHeap_insert(A, 8);
    //cout << "--heap max extract: " << heap_max_extract(A) << endl;
    cout << "--after insertion: " << endl;
    printA(A);
    cout << endl;
    heapsort(A);
    printA(A);

    return 0;
}
