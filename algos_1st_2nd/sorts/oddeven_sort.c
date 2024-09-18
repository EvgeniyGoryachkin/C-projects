#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

unsigned long rand1(unsigned long m){ 
    unsigned long n = rand(); 
    if (m < RAND_MAX + 1) {
        return n % m; 
    }
    return n * (m / (RAND_MAX + 1)); 
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int* arr, int size)
{
    int x = 0;
    unsigned int comp = 0, perm = 0;
    while (!x)
    {
        x = 1;
        for (int i = 1; i <= size-2; i += 2)
        {
            comp++;
            if (arr[i] > arr[i+1])
            {
               swap(&arr[i], &arr[i+1]);
               perm++;
               x = 0;
            }
        }
        for (int i = 0; i <= size-2; i += 2)
        {
            comp++;
            if (arr[i] > arr[i+1])
            {
               swap(&arr[i], &arr[i+1]);
               perm++;
               x = 0;
            }
        }
    }
    printf("%d\t\t%d\t\t%d\n", size, perm, comp);
}

void test()
{
    long int NMAX = 32768;
    int *arr = (int*)malloc(sizeof(int) * NMAX);
    printf("SIZE\t\tNPERM\t\tNCOMP\n");
    for(int size = 8; size <= NMAX; size*=2){
        for(int i = 0; i < size; i++) {
            arr[i] = rand1(size);
        }
        sort(arr, size);
    }
}

int main(){
    test();
}