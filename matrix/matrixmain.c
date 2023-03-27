#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
} element;

typedef struct sparseMatrix {
    element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
} SparseMatrix;

void matrix_print(SparseMatrix a)
{
    for (int i = 0; i < a.terms; i++)
    {
        printf("(%d %d %d)\n", a.data[i].row, a.data[i].col, a.data[i].value);

    }
    printf("\n");
}

SparseMatrix* transpose(SparseMatrix* a)
{
    SparseMatrix* b = (SparseMatrix*)malloc(sizeof(SparseMatrix));

    b->rows = a->cols;
    b->cols = a->rows;
    b->terms = a->terms;

    if (a->terms > 0) {
        int bindex = 0;
        for (int c = 0; c < a->cols; c++) {
            for (int i = 0; i < a->terms; i++) {
                if (a->data[i].col == c)
                {
                    b->data[bindex].row = a->data[i].col;
                    b->data[bindex].col = a->data[i].row;
                    b->data[bindex].value = a->data[i].value;
                    bindex++;
                }
            }
        }
    }

    return b;
}

int main()
{
    SparseMatrix *m = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    SparseMatrix *result;

    int rows, cols, terms;
    printf("행과 열 그리고 항의 개수를 입력해주세요: ");
    scanf("%d %d %d", &rows, &cols, &terms);

    m->rows = rows;
    m->cols = cols;
    m->terms = terms;

    printf("희소행렬의 항의 정보를 입력해주세요(row, col, value):\n");
    for (int i = 0; i < terms; i++) {
        scanf("%d %d %d", &m->data[i].row, &m->data[i].col, &m->data[i].value);
    }

    printf("2차원 행렬\n");
    matrix_print(*m);

    result = transpose(m);
    printf("전치행렬\n");
    matrix_print(*result);

    free(m);
    free(result);

    return 0;
}