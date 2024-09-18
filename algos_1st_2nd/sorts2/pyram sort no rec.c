#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *arr, int n, int *count) {
for (int i = n / 2 - 1; i >= 0; i--) {
	int j = i;
	int k = 2 * j + 1;
	while (k < n) {
		if (k + 1 < n && arr[k] < arr[k + 1]) k++;
		if (arr[j] < arr[k]) {
			int temp = arr[j];
			arr[j] = arr[k];
			arr[k] = temp;
			j = k;
			k = 2 * j + 1;
			(*count)++;
		} else {
			break;
		}
	}
}

for (int i = n - 1; i > 0; i--) {
	int temp = arr[0];
	arr[0] = arr[i];
	arr[i] = temp;
	int j = 0;
	int k = 2 * j + 1;
	while (k < i) {
		if (k + 1 < i && arr[k] < arr[k + 1]) k++;
		if (arr[j] < arr[k]) {
			temp = arr[j];
			arr[j] = arr[k];
			arr[k] = temp;
			j = k;
			k = 2 * j + 1;
			(*count)++;
		} else {
			break;
		}
	}
}
}

int main() {
int arr[] = {5, 3, 2, 7, 6, 8, 4, 1};
int n = sizeof(arr) / sizeof(int);
printf("unsorted array: ");
for (int i=0; i<n; ++i)
	printf("%d ", arr[i]);
	int count = 0;
	heap_sort(arr, n, &count);
	printf("sorted array");
for (int i = 0; i < n; i++) {
	printf(" %d ", arr[i]);
}
printf("\n");
printf("Number of swaps: %d\n", count);
return 0;
}