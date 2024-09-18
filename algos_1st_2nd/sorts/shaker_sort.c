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
    unsigned int comp = 0, perm = 0;
    int left = 0;
    int right = size - 1;
    int x = 1;
    while (x)
    {
        x = 0;
        for (int i = left; i < right; i++)
        {
            comp++;
            if (arr[i] > arr[i+1])
            {
                swap(&arr[i],  &arr[i+1]);
                perm++;
                x = 1;
            }
        }
        if (!x)
        {
            break;
        }
        x = 0;
        right--;
        for (int i = right; i >= left; i--)
        {
            comp++;
            if (arr[i] > arr[i+1])
            {
                swap(&arr[i],  &arr[i+1]);
                perm++;
                x = 1;
            }
        }
        left++;
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