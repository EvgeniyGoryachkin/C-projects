#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long rand1(unsigned long m) { 
    unsigned long n = rand(); 
    if (m < RAND_MAX + 1) {
        return n % m; 
    }
    return n * (m / (RAND_MAX + 1)); 
}

int partition(int* arr1, int size) {
    int temp = 0;
    int x = arr1[1];
    int i = 0, j = size - 1;
    while (1) {
        while (arr1[i] < x) { 
            i++;
        }
        while (x < arr1[j]) { 
            j--;
        }
        if (i >= j) {
            break;
        }
        temp = arr1[i];
        arr1[i] = arr1[j];
        arr1[j] = temp;
        i++; j--;
    }
    return i;
}

void quick_sort(int* arr1, int size) {
    if (size < 2) {
        return;
    }
    int i = partition(arr1, size);
    quick_sort(arr1, i);
    quick_sort(arr1 + i, size - i);
}

int compare(const void* arr1, const void* arr2) {
    const int* x = (int*)arr1;
    const int* y = (int*)arr2;
    if (*x > *y) {
        return 1;
    }
    else if (*x < *y) {
        return -1;
    }
    return 0;
}

int main() {
    int size, NMAX = 8096 * 16;
    printf("SIZE\t\tTIME\t\tTIME\t\t\n");
    for (size = 8; size < NMAX; size*=2) {
        int arr1[size], arr2[size];
        for (int i = 0; i < size; i++) {
            arr1[i] = arr2[i] = rand1(size);
        }
        clock_t start1 = clock();
        quick_sort(arr1, size);
        clock_t end1 = clock();
        double time_spent1 = (double)(end1 - start1) * 1000 / CLOCKS_PER_SEC;
        double time_clocks1 = (double)(end1 - start1);
        clock_t start2 = clock();
        qsort(arr2, size, sizeof(int), compare);
        clock_t end2 = clock();
        double time_spent2 = (double)(end2 - start2) * 1000 / CLOCKS_PER_SEC;
        double time_clocks2 = (double)(end2 - start2);
        printf("%d\t\t%f\t%f\t\t\n", size, time_clocks1, time_clocks2);
    }
}