#include <stdio.h>

#define ROWS_A 3
#define COLS_A 2
#define ROWS_B 2
#define COLS_B 4
#define ROWS_C ROWS_A
#define COLS_C COLS_B

int main() {
    // Оголошення матриць
    int matrix_a[ROWS_A][COLS_A];
    int matrix_b[ROWS_B][COLS_B];
    int matrix_c[ROWS_C][COLS_C];

    // Введення елементів матриці A
    printf("Введіть елементи матриці A (%d x %d):\n", ROWS_A, COLS_A);
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_A; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &matrix_a[i][j]);
        }
    }

    // Введення елементів матриці B
    printf("\nВведіть елементи матриці B (%d x %d):\n", ROWS_B, COLS_B);
    for (int i = 0; i < ROWS_B; i++) {
        for (int j = 0; j < COLS_B; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &matrix_b[i][j]);
        }
    }

    // Перевірка сумісності матриць для множення
    if (COLS_A != ROWS_B) {
        printf("Помилка: Кількість стовпців першої матриці повинна дорівнювати кількості рядків другої матриці.\n");
        return 1; // Код помилки
    }

    // Множення матриць
    printf("\nМноження матриці A на матрицю B:\n");
    for (int i = 0; i < ROWS_C; i++) {
        for (int j = 0; j < COLS_C; j++) {
            matrix_c[i][j] = 0;
            for (int k = 0; k < COLS_A; k++) {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
            printf("%d\t", matrix_c[i][j]);
        }
        printf("\n");
    }

    // Пошук найменшого елемента та його індексів
    int min_element = matrix_c[0][0];
    int min_row = 0;
    int min_col = 0;

    for (int i = 0; i < ROWS_C; i++) {
        for (int j = 0; j < COLS_C; j++) {
            if (matrix_c[i][j] < min_element) {
                min_element = matrix_c[i][j];
                min_row = i;
                min_col = j;
            }
        }
    }

    printf("\nНайменший елемент у результуючій матриці C: %d\n", min_element);
    printf("Його індекси: [%d][%d]\n", min_row, min_col);

    return 0; // Код успішного завершення
}