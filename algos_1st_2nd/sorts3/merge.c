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

void merge(int* arr, int size, int* buf) {
    int i, j, k, m = size / 2;
    i = 0; j = m;
    for (k = 0; k < size; k++) {
        perms++;
        comps = comps + 2;
        if (i > m - 1) {
            buf[k] = arr[j++];
        }
        else if (j == size) {
            buf[k] = arr[i++];
        }
        else {
            buf[k] = arr[i] < arr[j] ? arr[i++] : arr[j++]; comps++;
        }
    }
    for (k = 0; k < size; k++) { 
        arr[k] = buf[k];
        perms++; 
    }
}

void mergesort(int* arr, int size, int* buf) {
    int m = size / 2;
    if (size < 2) { 
        return;
    }
    mergesort(arr, m, buf);
    mergesort(arr + m, size - m, buf + m);
    merge(arr, size, buf);
}

void test() {
    int size, NMAX = 8096 * 16;
    int *buf = (int*)malloc(sizeof(int) * NMAX);
    int *arr = (int*)malloc(sizeof(int) * NMAX);
    printf("SIZE\t\tNCOMP\t\tNPERM\n");
    for (size = 8; size < NMAX; size*=2) {
        for(int i = 0; i < size; i++) {
        arr[i] = rand1(size);
    }
        mergesort(arr, size, buf);
        printf("%d\t\t%lld\t\t%lld\n", size, comps, perms);
    }
}

int main() {
    test();
}