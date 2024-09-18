#include <stdio.h>

int binary_search(int arr[], int n, int x, int *count) {
int left = 0;
int right = n - 1;
int mid;
while (left <= right) {
mid = (left + right) / 2;
(*count)++;
if (arr[mid] == x) {
return mid;
}
else if (arr[mid] < x) {
left = mid + 1;
}
else {
right = mid - 1;
}
}
return -1;
}

int main() {
int arr[] = {1, 3, 5, 7, 9, 11, 15, 16, 17,};
int n = sizeof(arr) / sizeof(arr[0]);
int x = 5;
int count = 0;
int result = binary_search(arr, n, x, &count);
printf("Index of %d in the array is %d\n", x, result);
printf("Number of operations: %d\n", count);
return 0;
}