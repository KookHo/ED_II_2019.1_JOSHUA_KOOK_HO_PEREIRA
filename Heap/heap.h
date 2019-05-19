#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

typedef struct heap{
    int lenght;
    int heap_size;
    int * v = NULL;
}Heap;

Heap * initialize_heap(int i);
void max_heapify(Heap * A, int i);
int leftChild(int i);
int rightChild(int i);
int parent(int i);
void build_max_heap(Heap * A);
void heapsort(Heap * A);
void printA(Heap * A);
int heap_max(Heap * A);
int heap_max_extract(Heap * A);
void heap_increase_key(Heap * A, int i, int key);
void mHeap_insert(Heap * A, int key);

#endif // HEAP_H_INCLUDED
