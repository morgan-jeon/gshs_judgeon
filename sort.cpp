#include<iostream>

void swap(int* a, int* b);
void i_sort(int* arr, int n);
void b_sort(int* arr, int n);
void s_sort(int* arr, int n);
void m_sort(int* arr, int n);
void q_sort(int* arr, int n);
void maxh_sort(int* arr, int n);
void h_sort(int* arr, int n);

int main(){
    int n;
    std::cin>>n;
    int *arr = new int[n];

    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }

    maxh_sort(arr, n);

    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<' ';
    }
    delete[] arr;
}

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void m_merge(int *arr, int start, int middle, int end, int n){
    int *temp_arr = new int[n];
    int i = start;
	int j = middle + 1;
	int k = start;
	
	while(i<=middle && j<=end){
		if(arr[i]<=arr[j]){
            temp_arr[k] = arr[i++];
        } else {
            temp_arr[k] = arr[j++];
        }
		k++;
	}
	
    if(i>middle){
		for(int t=j;t<=end;++t){
			temp_arr[k] = arr[t];
	        ++k;
		}
	} else {
		for(int t=i;t<=middle;++t){
			temp_arr[k] = arr[t];
			++k;
		}
	}
	
	for(int t=start;t<=end;++t){
		arr[t] = temp_arr[t];
	}
    delete[] temp_arr;
}

void m_msort(int *arr, int start, int end, int n){
    if(start < end){
		int middle = (start + end) / 2;
		m_msort(arr, start, middle, n);
		m_msort(arr, middle+1, end, n);
		m_merge(arr, start, middle, end, n);
	}
}
void m_sort(int *arr, int n){
    //// Merge Sort
    m_msort(arr,0,n-1,n);
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



void q_qsort(int *arr, int first, int last){
    if(first >= last) return;

	int pivot = first;
	int i = first + 1;
	int j = last;
	int tmp;

	while (i <= j)
	{
		while (arr[i] < arr[pivot] && i <= last) i++;
		while (arr[j] >= arr[pivot] && j > first) j--;

		if (i >= j) break;

		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	tmp = arr[j];
	arr[j] = arr[pivot];
	arr[pivot] = tmp;

	q_qsort(arr, first, j - 1);
	q_qsort(arr, j + 1, last);
}

void q_sort(int* arr, int n){
    q_qsort(arr, 0, n-1);
}

void max_heapify(int *a, int i, int n)
{ 
	int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j + 1] > a[j])
            j = j + 1;
        if (temp > a[j])
        {
            break;
        }
        else if (temp <= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}

void maxh_sort(int *arr, int n){
    for(int i = n / 2; i >= 1; i--){
    max_heapify(arr, i, n);
    } 
    for(int temp, i = n; i >= 2; i--){
        temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        max_heapify(arr, 1, i - 1);
    }
}

void h_sort(int *arr, int n){
    if (n <= 1){
            return;
    }

    for (int i = 0; i < n; i++){
        while (i > 0 && arr[i / 2] < arr[i]){
        swap(&arr[i / 2], &arr[i]);
        i /= 2;
        }
    }

    for (int i = n - 1; i >= 1; i--){
        swap(&arr[0], &arr[i]);
        int j = 0;
        while (2 * j + 1 < i){
            int maxChild = 2 * j + 1;
            if (2 * j + 2 < i && arr[2 * j + 2] > arr[maxChild]){
                maxChild = 2 * j + 2;
            }

            if (arr[maxChild] > arr[j]){
                swap(&arr[j], &arr[maxChild]);
                j = maxChild;
            } else {
                break;
            }
        }
    }
}
