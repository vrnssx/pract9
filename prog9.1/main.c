#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *x = NULL;
    int *y = NULL;
    int *z = NULL;

    printf("Введіть розмір масивів (N < 20): ");
    if (scanf("%d", &n) != 1) {
        printf("Помилка введення розміру масиву.\n");
        return 1;
    }

    if (n >= 20 || n <= 0) {
        printf("Некоректний розмір масивів.\n");
        return 1;
    }

    x = (int*)malloc(n * sizeof(int));
    y = (int*)malloc(n * sizeof(int));
    z = (int*)malloc(n * sizeof(int));

    if (x == NULL || y == NULL || z == NULL) {
        printf("Помилка виділення пам'яті.\n");
        free(x);
        free(y);
        free(z);
        return 1;
    }

    printf("Введіть елементи масиву X:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &x[i]) != 1) {
            printf("Помилка введення елемента масиву X.\n");
            free(x);
            free(y);
            free(z);
            return 1;
        }
    }

    printf("Введіть елементи масиву Y:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &y[i]) != 1) {
            printf("Помилка введення елемента масиву Y.\n");
            free(x);
            free(y);
            free(z);
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (x[i] <= y[i]) {
            z[i] = x[i] * x[i];
        } else {
            z[i] = y[i];
        }
    }

    printf("Масив Z:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", z[i]);
    }
    printf("\n");

    free(x);
    free(y);
    free(z);

    return 0;
}