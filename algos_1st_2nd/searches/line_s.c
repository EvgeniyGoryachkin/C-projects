#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear_search(int *arr, int n, int key, int *count) {
for (int i = 0; i < n; i++) {
*count += 1;
if (arr[i] == key) {
return i;
}
}
return -1;
}

int main() {

int n = 10;
int arr[n];
for (int i = 0; i < n; i++) {
arr[i] = rand() % 100;
printf("%d ", arr[i]);
}
printf("\n");
int key = 24; 
int count = 0;
int index = linear_search(arr, n, key, &count);
printf("element on posicion %d.\n", index);
printf("count of operations: %d.\n", count);
return 0;
}
