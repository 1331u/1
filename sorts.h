#ifndef SORTS_H
#define SORTS_H

void swap(int &a, int &b);
void BubbleSort(int* ar,int size, bool (*comp)(int , int));
void InsertionSort(int* ar, int size, bool (*comp)(int , int));
void SelectionSort(int* ar, int size, bool (*comp)(int, int));
void ShellSort(int* ar, int size, bool (*comp)(int , int));
void CountSort(int* ar, int size);
void quicksort(int* ar, int left, int right,bool (*comp)(int , int ));
void QuickSort(int* ar, int size,bool(*comp)(int , int));
void heapify(int* ar, int size, int i);
void HeapSort(int* ar, int size, bool(*comp)(int , int));



#endif // SORTS_H
