
#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
int i, count = 0;
arr[n] = x; 
for (i = 0; arr[i] != x; i++) {
count++;
}

return count;
}

int main() {
int arr[] = {2, 3, 4, 1, 50, 11, 21, 345, 10, 45, 44};
int x = 10;
int n = sizeof(arr)/sizeof(arr[0]);
int count;

count = linearSearch(arr, n, x);
if (count >= n) {
printf("Element not found\n");
} else {
printf("Element found at index %d\n", count);
printf("Number of operations: %d\n", count+1); 
}

return 0;
}
