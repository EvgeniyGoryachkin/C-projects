#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
int temp = *a;
*a = *b;
*b = temp;
}

void heapify(int arr[], int n, int i, int* counter) {
int largest = i;
int l = 2*i + 1;
int r = 2*i + 2;

if (l < n && arr[l] > arr[largest])
largest = l;

if (r < n && arr[r] > arr[largest])
largest = r;

if (largest != i) {
swap(&arr[i], &arr[largest]);
(*counter)++;
heapify(arr, n, largest, counter);
}
}

void heapSort(int arr[], int n, int* counter) {
for (int i = n / 2 - 1; i >= 0; i--)
heapify(arr, n, i, counter);

for (int i=n-1; i>0; i--) {
swap(&arr[0], &arr[i]);
(*counter)++;
heapify(arr, i, 0, counter);
}
}

int main() {
int arr[] = {5, 3, 2, 7, 6, 8, 4, 1};
int n = sizeof(arr) / sizeof(int);
printf("unsorted array");
for (int i=0; i<n; ++i)
printf(" %d ", arr[i]);


int counter = 0;
heapSort(arr, n, &counter);

printf("Sorted array: ");
for (int i = 0; i < n; i++)
printf("%d ", arr[i]);

printf("\nNumber of swaps %d\n", counter);

return 0;
}