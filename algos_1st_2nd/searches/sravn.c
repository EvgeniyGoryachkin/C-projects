#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n) {
int i, j, tmp;
for (i = 0; i < n-1; i++) {
	for (j = 0; j < n-i-1; j++) {
		if (arr[j] > arr[j+1]) {
			tmp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = tmp;
		}
	}
}
}

void cocktail_sort(int arr[], int n) {
int tmp, start = 0, end = n-1, swapped = 1, i;

while (swapped) {
	swapped = 0;

for (i = start; i < end; i++) {
	if (arr[i] > arr[i+1]) {
		tmp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = tmp;
		swapped = 1;
	}
}

if (!swapped)
	break;

swapped = 0;

end--;

for (i = end-1; i >= start; i--) {
	if (arr[i] > arr[i+1]) {
		tmp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = tmp;
		swapped = 1;
	}
}

start++;
}
}

int main() {
int arr1[5000], arr2[5000], i, n = 5000;
double time1, time2;

srand(time(NULL));

for (i = 0; i < n; i++) {
	arr1[i] = arr2[i] = rand() % 1000;
}

clock_t start1 = clock();
bubble_sort(arr1, n);
clock_t end1 = clock();

clock_t start2 = clock();
cocktail_sort(arr2, n);
clock_t end2 = clock();

time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

printf("Bubble sort time: %f seconds\n", time1);
printf("Cocktail sort time: %f seconds\n", time2);

return 0;
}