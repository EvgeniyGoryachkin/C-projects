#include <stdio.h>

void cocktail_sort(int arr[], int n)
{
int start = 0, end = n - 1, swapped = 1;

while (swapped) {
swapped = 0;

for (int i = start; i < end; i++) {
if (arr[i] > arr[i + 1]) {
int temp = arr[i];
arr[i] = arr[i + 1];
arr[i + 1] = temp;
swapped = 1;
}
}

if (!swapped)
break;

swapped = 0;

end--;

for (int i = end - 1; i >= start; i--) {
if (arr[i] > arr[i + 1]) {
int temp = arr[i];
arr[i] = arr[i + 1];
arr[i + 1] = temp;
swapped = 1;
}
}

start++;
}
}

int main() {
int arr[100], n, i;
printf("Enter the number of elements: ");
scanf("%d", &n);
printf("\nEnter the elements:\n");
for (i = 0; i < n; i++)
scanf("%d", &arr[i]);
cocktail_sort(arr, n);
printf("\nSorted Array:\n");
for (i = 0; i < n; i++)
printf("%d ", arr[i]);
return 0;
}