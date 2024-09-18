#include <stdio.h>

int main() {
int num, arr[100], even[100], odd[100];
int i, j, even_count = 0, odd_count = 0;

printf("Enter a number: ");
scanf("%d", &num);

printf("Enter %d elements in the array: ", num);
for(i = 0; i < num; i++)
scanf("%d", &arr[i]);

for(i = 0; i < num; i++) {
if(arr[i] % 2 == 0) {
even[even_count] = arr[i];
even_count++;
} else {
odd[odd_count] = arr[i];
odd_count++;
}
}

for(i = 0; i < even_count - 1; i++) {
for(j = i + 1; j < even_count; j++) {
if(even[i] > even[j]) {
int temp = even[i];
even[i] = even[j];
even[j] = temp;
}
}
}

for(i = 0; i < odd_count - 1; i++) {
for(j = i + 1; j < odd_count; j++) {
if(odd[i] < odd[j]) {
int temp = odd[i];
odd[i] = odd[j];
odd[j] = temp;
}
}
}

printf("\nEven numbers in ascending order: ");
for(i = 0; i < even_count; i++)
printf("%d ", even[i]);

printf("\nOdd numbers in descending order: ");
for(i = 0; i < odd_count; i++)
printf("%d ", odd[i]);

return 0;
}