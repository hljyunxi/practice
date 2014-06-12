#include <iostream>
#include <stdlib.h>
#include <stdio.h>

template <class T>
void swap(T * a, T * b){
    T t = *a;
    *a = *b;
    *b = t;
}

template <class T>
void quick_sort(T* a, int low, int high){

    if(!(low < high))
        return ;

    int i = low, j = high;
    T cmp_data = a[low];
    while(i < j){
        while(i < j && a[j] >= cmp_data)
            j--;
        if(i < j)
            a[i] = a[j];

        while(i < j && a[i] < cmp_data)
            i++;
        if(i < j)
            a[j] = a[i];
    }
    a[i] = cmp_data;
    quick_sort(a, low, i);
    quick_sort(a, i+1, high);
}

template <class T>
void quick_sort_random_pivot(T *a, int low, int high){
    if(low >= high)
        return ;

    int i = low, j = high;
    int p = low + (rand() % (high - low));
    int cmp_data = a[p];
    while(i < j){
        while(i < j && a[j] > cmp_data)
            j--;
        
        while(i < j && a[i] <= cmp_data)
            i++;

        if(i < j)
            swap(&a[i], &a[j]);
        i++, j--;
    }
    quick_sort_random_pivot(a, low, i-1);
    quick_sort_random_pivot(a, i, high);
}

int main(){
    int a[] = {1, 7, 4, 3, 5, 8, 9, 12, 2, 15};
    quick_sort((int * )a, 0, 9);
    for(int i = 0; i < 10; i++)
        printf("%d->", a[i]);
    return 0;
}
