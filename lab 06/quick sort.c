#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void quickSort(int[], int, int);
int partition(int[], int, int);

void quickSort(int A[], int low, int high) {
    if(low < high) {
        int split_point = partition(A, low, high);
        quickSort(A, low, split_point -  1);
        quickSort(A, split_point + 1, high);
    }
}

int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high + 1;
    while(i <= j) {
        while(true) {
            i += 1;
            if(A[i] >= pivot) {
                break;
            }
        }
        while(true) {
            j -= 1;
            if(A[j] <= pivot) {
                break;
            }
        }

        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;

    int temp1 = A[j];
    A[j] = A[low];
    A[low] = temp1;

    return j;
}

int main() {
     int a[15000], n, i, j, ch;
    clock_t start, end;
    while(1) {
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                printf("\nEnter array elements: ");
                for(i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                start = clock();
                quickSort(a, 0, n-1);
                end = clock();
                printf("\nSorted array is: ");
                for(i = 0; i < n; i++) {
                    printf("%d\t", a[i]);
                }
                printf("\nTime taken to sort %d numbers is %f Secs", n, ((double)(end-start))/CLOCKS_PER_SEC);
                break;
            case 2:
                n = 500;
                while(n <= 14500) {
                    for(i = 0; i < n; i++) {
                        a[i] = n - i;
                    }
                    start = clock();
                    quickSort(a, 0, n-1);
                    for(int j=0; j<50000000; j++) {
                        float temp = 38/600;
                    }
                    end = clock();
                    printf("\nTime taken to sort %d numbers is %f Secs", n, ((double)(end-start))/CLOCKS_PER_SEC);
                    n += 1000;
                }
                break;
            case 3:
                exit(0);
                break;
        }
        getchar();
    }
    return 0;
}
