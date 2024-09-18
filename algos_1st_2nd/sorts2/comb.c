#include <stdlib.h>
#include <stdio.h>

unsigned long rand1(unsigned long m) { 
    unsigned long n = rand(); 
    if (m < RAND_MAX + 1) {
        return n % m; 
    }
    return n * (m / (RAND_MAX + 1)); 
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int* arr, int size, int* seq) {
    int swapped = 1, count = 0, gap = size;
    unsigned long long perms = 0, comps = 0;

    while (swapped)
    {
        gap = seq[count];
        swapped = 0;
        for (int i = 0; i+gap < size; i++)
        {
            comps++;
            if(arr[i] > arr[i+gap])
            {
                swap(&arr[i], &arr[i+gap]);
                swapped = 1;
                perms++;
            }
        }
        if (gap > 1) {count++;}
    }
    printf("%lld\t%lld\n", comps, perms);
}

void perfect_sort(int* arr, int size) {
    int swapped = 1, gap = size/3;
    unsigned long long perms = 0, comps = 0;

    while (swapped)
    {
        swapped = 0;
        for (int i = 0; i+gap < size; i++)
        {
            comps++;
            if(arr[i] > arr[i+gap])
            {
                swap(&arr[i], &arr[i+gap]);
                swapped = 1;
                perms++;
            }
        }
        if (gap > 1) {gap /= 3;}
    }
    printf("\n\nCOMPS\t\tPERMS\n");
    printf("%lld\t\t%lld\n", comps, perms);
}

void test(void (fun)(int* arr, int size, int* seq)) {
    int size = 32768;
    long int NMAX = 32768;
    int* seqarr[4];
    int G1[15] = {16384, 8192, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    int G2[14] = {16383, 8191, 4095, 2047, 1023, 511, 255, 127, 63, 31, 15, 7, 3, 1};
    int G3[8] = {16577, 4193, 1073, 281, 77, 23, 8, 1};
    int G4[10] = {16339, 8147, 4051, 2003, 979, 367, 211, 83, 19, 1};
    seqarr[0] = G1;
    seqarr[1] = G2;
    seqarr[2] = G3;
    seqarr[3] = G4;
    char* namearr[4] = {"G1", "G2", "G3", "G4"};
    for (int i = 0; i < 4; i++) {
        int *arr = (int*)malloc(sizeof(int) * NMAX);
        printf("\n%s\n\nCOMPS\t\tPERMS\n", namearr[i]);
        for(int j = 0; j < size; j++) {
            arr[j] = rand1(size);
        }
        fun(arr, size, seqarr[i]);
        free(arr);
        printf("\n");
    }
    printf("\nBEST COEF");
    int *arr = (int*)malloc(sizeof(int) * NMAX);
    for(int j = 0; j < size; j++) {
            arr[j] = rand1(size);
        }
    perfect_sort(arr, size);
    free(arr);
}

int main()
{
    test(sort);
}