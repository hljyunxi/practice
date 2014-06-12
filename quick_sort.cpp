#include <iostream.h>
#include <stdlib.h>

template <class T>
void quick_sort_1(T a[], int low, int high){

    if(!(low < high))
        return ;

    //partition
    int p = rand()%(high-low) + low;
    T cmp_data = a[p];

    int i = low, j = high - 1;
    while(i < j){
        while(i < j && a[j] > cmp_data)
            j--;

        while(i < j && a[i] < cmp_data)
            i++;

        if(i < j)
            swap(a[i++], a[j--]);
    }

    quick_sort_1(a, low, i);
    quick_sort_1(a, i+1, high);
}

template <class T>
void quick_sort_2(T a[], int low, int high){

    //partition
    int p = rand()%(high-low) + low;
    T cmp_data = a[p];

    int i = low, j = high - 1;
    while(i < j){
        while(i < j && a[j] > cmp_data)
            j--;
        if(i < j)
            a[i++] = a[j];

        while(i < j && a[i] < tmp_data)
            i++;
        
        if(i < j)
            a[j--] = a[i]
    }
    a[i] = cmp_data;
    quick_sort_2(a, low, i);
    quick_sort_2(a, i+1, high);
}

template <class T>
void qucik_sort(T a[], int size){
    quick_sort(a, 0, size);
}

int main(){
    return 0;
}
