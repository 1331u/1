#include "sorts.h"
void swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

void BubbleSort(int* ar,int size,bool (*comp)(int , int)){
    for(int i = 0; i< size-1; i++)
    {
        for(int j = 0;j<size-1;j++)
            if(comp(ar[j], ar[j+1])){
                swap(ar[j],ar[j+1]);


            }
    }
}

void InsertionSort(int *ar, int size, bool (*comp)(int, int))
{
    for(int i = 1; i < size; i++)
    {
        int key = ar[i];
        int j = i - 1;
        while(j>= 0 && comp(ar[j], key))
        {
            ar[j+1] = ar[j];
            j = j - 1;
        }
        ar[j+1] = key;
    }
}

void SelectionSort(int *ar, int size, bool (*comp)(int, int)){
    for(int i = 0; i < size - 1; i++){
        int min_pos = i;
        for(int j = i + 1;j < size; j ++)
        {
            if(comp(ar[min_pos], ar[j]))
            {
                min_pos = j;
            }
        }
        if(min_pos != i)
        {
            swap(ar[i], ar[min_pos]);

        }
    }
}

void ShellSort(int *ar, int size, bool (*comp)(int, int)){
    for(int gap = size/2; gap> 0; gap = gap/2)
    {
        for(int i = gap; i < size; i++)
        {
            int temp = ar[i];
            int j;
            for (j = i; j >= gap && comp(ar[j - gap], temp); j -= gap)
                ar[j] = ar[j - gap];
            ar[j] = temp;

        }
    }
}

void CountSort(int* ar, int size)
{
    int max = ar[0];
    for(int i = 1; i< size; i++)
    {
        if(max < ar[i])
        {
            max = ar[i];
        }
    }
    int* br = new int(max + 1);
    for(int i = 0; i< max + 1; i++)
        br[i] = 0;
    for(int i = 0; i< size; i++)
    {
        br[ar[i]] ++;
    }
    int n = 0;
    for(int i = 0; i< max + 1; i++)
    {
        for(int j = 0; j < br[i]; j++)
        {
            ar[n] = i;
            n++;
        }
    }

}

void quicksort(int* ar, int left, int right,bool(*comp)(int , int))
{
    if (left > right)
        return;

    int i = left;
    int j = right;
    int p = ar[(left + right) / 2];

    while (i <= j) {
        while (comp(ar[i], p))
            i++;
        while (comp(p,ar[i]))
            j--;
        if (i <= j) {
            swap(ar[i], ar[j]);
            i++;
            j--;
        }
    }

    quicksort(ar, left, j,comp);
    quicksort(ar, i, right,comp);
}
void QuickSort(int *ar, int size, bool (*comp)(int, int))
{
    quicksort(ar,0,size-1,comp);
}
void heapify(int *ar, int size, int i){
    int largest  = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<size && ar[l] > ar[largest])
        largest = l;
    if(r<size && ar[r] >ar[largest])
        largest = r;
    if(largest != i)
    {
        swap(ar[i],ar[largest]);
        heapify(ar,size,largest);
    }
}

void HeapSort(int *ar, int size, bool (*comp)(int, int)){
    for(int i = size/2 - 1; i >= 0; i--)
        heapify(ar, size, i);
    for(int i = size - 1; i> 0; i--)
    {
        swap(ar[0], ar[i]);
        heapify(ar,i,0);
    }
}

