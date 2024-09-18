#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Структура для передачи аргументов в поток
typedef struct {
    int n_rows;
    int** a;
    int** b;
    int** c;
    int task_num;
    int num_tasks;
} ThreadArguments;

// Функция для выполнения потоком задачи
void* task(void* argument) {
    ThreadArguments* args = (ThreadArguments*) argument;
    int n_rows = args->n_rows;
    int task_num = args->task_num;

    int start_row = task_num * (n_rows / args->num_tasks);
    int end_row = (task_num + 1) * (n_rows / args->num_tasks);

    // Выполнение части задачи
    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < n_rows; j++) {
            args->c[i][j] = args->a[i][j] + args->b[i][j];
        }
    }

    pthread_exit(NULL);
}

// Функция для вывода матрицы на экран
void printMatrix(int n, int** matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n;  // Размерность массива
    int p;  // Количество потоков

    // Ввод размерности массива и количества потоков
    printf("Enter value of n: ");
    scanf("%d", &n);

    printf("Enter the number of threads: ");
    scanf("%d", &p);

    int** a = (int**) malloc(n * sizeof(int*));  // Массив a
    int** b = (int**) malloc(n * sizeof(int*));  // Массив b
    int** c = (int**) malloc(n * sizeof(int*));  // Массив c (a + b)

    // Выделение памяти для массивов a, b и c
    for (int i = 0; i < n; i++) {
        a[i] = (int*) malloc(n * sizeof(int));
        b[i] = (int*) malloc(n * sizeof(int));
        c[i] = (int*) malloc(n * sizeof(int));
    }

    // Ввод элементов массивов a и b
    printf("Enter the elements of array a:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of array b:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Создание и запуск потоков
    pthread_t threads[p];
    ThreadArguments arguments[p];

    for (int i = 0; i < p; i++) {
        arguments[i].n_rows = n;
        arguments[i].a = a;
        arguments[i].b = b;
        arguments[i].c = c;
        arguments[i].task_num = i;
        arguments[i].num_tasks = p;

        pthread_create(&threads[i], NULL, task, (void*) &arguments[i]);
    }

    // Ожидание завершения всех потоков
    for (int i = 0; i < p; i++) {
        pthread_join(threads[i], NULL);
    }

    // Вывод результата
    printf("Result matrix c:\n");
    printMatrix(n, c);

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}