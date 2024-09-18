#include <stdlib.h>
#include <stdio.h>
unsigned long long comps, perms;

unsigned long rand1(unsigned long m) { 
    unsigned long n = rand(); 
    if (m < RAND_MAX + 1) {
        return n % m; 
    }
    return n * (m / (RAND_MAX + 1)); 
}

int partition(int* arr, int size) {
    int x = arr[1];
    int i = 0, j = size - 1;
    while (1) {
        while (arr[i] < x) i++;
        while (x < arr[j]) j--;
        comps++;
        if (i >= j) break;
        int temp = 0;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        perms = perms + 3;
        i++; j--;

    }
    return i;
}
void quick_sort(int* arr, int size) {
    if (size < 2) {
        return;
    }
    int i = partition(arr, size);
    quick_sort(arr, i);
    quick_sort(arr + i, size - i);
}


void test() {
    int size, j, NMAX = 8096 * 16;
    int *arr = (int*)malloc(sizeof(int) * NMAX);
    printf("SIZE\t\tNCOMP\t\tNPERM\n");
    for (size = 8; size < NMAX; size*=2) {
        for(j = 0; j < 5; j++) {
            for(int i = 0; i < size; i++) {
                arr[i] = rand1(size);
            }
            quick_sort(arr, size);
        }
        printf("%d\t\t%lld\t\t%lld\n", size, comps / (long)j, perms / (long)j);
    }
}

int main() {
    test();
}