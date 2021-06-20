#include<iostream>

void swap(int* a, int* b);
void i_sort(int* arr, int n);
void b_sort(int* arr, int n);
void s_sort(int* arr, int n);
void m_sort(int* arr, int n);

int main(){
    int n;
    std::cin>>n;
    int *arr = new int[n];

    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }

    s_sort(arr, n);

    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<' ';
    }
    delete arr;
}

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void m_sort(int *arr, int n){
    //// Merge Sort

}

void s_sort(int *arr, int n){
    //// Selection Sort
    int min=0;
    for(int i=0;i<n-1;++i){
        min = i;
        for(int j=i+1;j<n;++j){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(&arr[i],&arr[min]);
    }
}

void b_sort(int* arr, int n){
    //// Bubble Sort
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-i;++j){
            if(arr[j]<arr[j-1]){
                swap(&arr[j],&arr[j-1]);
            }
        }
    }
}

void i_sort(int* arr, int n){
    //// Insertion
    for(int i=0;i<n;++i){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(&arr[j],&arr[j-1]);
            j = j-1;
        }
    }
    ////
}
