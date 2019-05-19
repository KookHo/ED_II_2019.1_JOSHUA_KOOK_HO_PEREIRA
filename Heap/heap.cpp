#include <iostream>
#include <array>
#include <climits>
#include "heap.h"

using namespace std;

void printA(Heap * A){
    cout << "lenght: " << A->lenght << endl;
    for (int i = 1; i <= A->lenght; i++){
        cout << A->v[i] << " ";
    }
    cout << endl;
}

Heap * initialize_heap(int i){
    Heap * newHeap = (Heap *)malloc(sizeof(Heap));
    newHeap->lenght = i;
    newHeap->heap_size = 0;
    newHeap->v = (int *)malloc(100*sizeof(int));
    return newHeap;
}

int leftChild(int i){
    return 2*i;
}

int rightChild(int i){
    return (2*i) + 1;
}
int parent(int i){
    return i/2;
}

void max_heapify(Heap * A, int i){
    int largest;
    int left = leftChild(i);
    int right = rightChild(i);
    cout << endl;
    cout << "Position: " << i << " left: " << left << " right: " << right << endl;
    if (left <= A->heap_size && A->v[left] > A->v[i]){
        printf(" left %d <= heapsize %d and A[left] %d > A[i] %d\n", left, A->heap_size, A->v[left], A->v[i]);
        largest = left;
        cout << "Largest index: " << largest <<" Value: " << A->v[largest] << endl;

    }
    else{
        cout << "First if false" << endl;
        largest = i;
        cout << "Largest index: " << largest <<" Value: " << A->v[largest] << endl;

    }


    if (right <= A->heap_size && A->v[right] > A->v[largest]){
        printf(" right %d <= heapsize %d and A[right] %d > A[largest] %d\n", right, A->heap_size, A->v[right], A->v[largest]);
        largest = right;
        cout << "Largest index: " << largest <<" Value: " << A->v[largest] << endl;

    }


    if (largest != i){
        cout << "largest != i ( " << largest << " != " << i << " )"<< endl;
        cout << "swaping A.v[i]: " << A->v[i] << " with A.v[largest]: " << A->v[largest] << endl;
        int aux = A->v[i];
        A->v[i] = A->v[largest];
        A->v[largest] = aux;
        cout << "Heapify on index " << largest << " value: " << A->v[largest] << endl;
        max_heapify(A, largest);
    }
}

void build_max_heap(Heap * A){
    cout << endl;
    cout << "--Building max heap--" << endl;
    cout << "A.Heap_size: " << A->heap_size << " , A.Lenght: " << A->lenght << endl;
    A->heap_size = A->lenght;
    cout << "Last non-leaf position: " << (int)A->lenght/2 << " Value: " << A->v[(int)A->lenght/2] << endl;
    for(int i = (int)(A->lenght/2); i > 0; i--){
        max_heapify(A, i);
    }
}

void heapsort(Heap * A){
    cout << "--Heapsorting--" << endl;
    build_max_heap(A);
    cout << A->heap_size << ", " << A->lenght << endl;
    printA(A);
    cout << endl;
    cout << "--Heapifying--" << endl;
    for(int i = A->lenght; i > 1; i--){
        int aux = A->v[1];
        A->v[1] = A->v[i];
        A->v[i] = aux;
        A->heap_size--;
        max_heapify(A, 1);
    }
}

int heap_max_extract(Heap * A){
    if (A->heap_size < 1)
        cout << "Heapless" << endl;
    int maxim = A->v[1];
    A->v[1] = A->v[A->heap_size];
    A->heap_size = A->heap_size - 1;
    A->lenght = A->lenght - 1;
    max_heapify(A, 1);
    cout << "HERE IS YOUR MAX EXTRACT: " << maxim << endl;
    return maxim;
}

int heap_max(Heap * A){
    return A->v[1];
}

void heap_increase_key(Heap * A, int i, int key){
    int aux;
    if(key < A->v[i])
        cout << "Error: new key < current key" << endl;
    A->v[i] = key;
    while (i > 1 && A->v[parent(i)] < A->v[i]){
        aux = A->v[i];
        A->v[i] = A->v[parent(i)];
        A->v[parent(i)] = aux;
        i = parent(i);
    }
}

void mHeap_insert(Heap * A, int key){
    A->lenght += 1;
    A->heap_size += 1;
    A->v[A->heap_size] = INT_MIN;
    heap_increase_key(A, A->heap_size, key);
}
