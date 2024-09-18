#include <stdio.h>

int binary_search(int arr[], int low, int high, int key, int *count) {
if (low <= high) {
int mid = (low + high) / 2;
(*count)++;
if (key == arr[mid]) {
return mid;
} else if (key < arr[mid]) {
return binary_search(arr, low, mid - 1, key, count);
} else {
return binary_search(arr, mid + 1, high, key, count);
}
}
return -1;
}

int main() {
int arr[] = {1, 3, 5, 6, 7, 11, 13, 89, 34, 45, 56};
int n = sizeof(arr)/sizeof(int);
int count = 0;
int key = 7;
int index = binary_search(arr, 0, n-1, key, &count);
if (index == -1) {
printf("Element not found\n");
} else {
printf("Element found at index %d\n", index);
}
printf("Number of operations: %d\n", count);
return 0;
}