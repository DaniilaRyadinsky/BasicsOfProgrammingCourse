#include <assert.h>
#include "matrix.h"

// размещает в динамической памяти матрицу размером nRows на nCols.
matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

// размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols.
// Возвращает указатель на нулевую матрицу
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; ++i)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

// освобождает память, выделенную под хранение матрицы m
void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        free(m.values[i]);
    free(m.values);
}

// освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        freeMemMatrix(ms[i]);
    free(ms);
}

//ввод матрицы m
void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
    }
}

//ввод массива из nMatrices матриц, хранящейся по адресу ms.
void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        inputMatrix(ms[i]);
    }
}

//вывод матрицы m
void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
}

//вывод массива из nMatrices матриц, хранящейся по адресу ms.
void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        outputMatrix(ms[i]);
    }
}

static void swap_pointers(int **a, int **b) {
    int *t = *a;
    *a = *b;
    *b = t;
}


//обмен строк с порядковыми номерами i1 и i2 в матрице m
void swapRows(matrix m, int i1, int i2) {
    assert(0 <= i1 && i1 < m.nRows);
    assert(0 <= i2 && i2 < m.nRows);
    swap_pointers(&m.values[i1], &m.values[i2]);
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//обмен колонок с порядковыми номерами j1 и j2 в матрице m.
void swapColumns(matrix m, int j1, int j2) {
    assert(0 <= j1 && j1 < m.nCols);
    assert(0 <= j2 && j2 < m.nCols);
    for (int i = 0; i < m.nRows; ++i) {
        swap(&m.values[i][j1], &m.values[i][j2]);
    }
}

//выполняет сортировку вставками строк матрицы m по неубыванию
// значения функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int const *, int)) {
    int *criteriaValues = (int*) malloc(sizeof(int) * m.nRows);

    for (int i = 0; i < m.nRows; ++i)
        criteriaValues[i] = criteria(m.values[i], m.nCols);

    for (int i = 0; i < m.nRows; ++i) {
        int minIndex = i;
        for (int j = i+1; j < m.nRows; ++j) {
            if (criteriaValues[j] < criteriaValues[minIndex])
                minIndex = j;
        }
        if (i != minIndex) {
            swap(&criteriaValues[i], &criteriaValues[minIndex]);
            swapRows(m, i, minIndex);
        }
    }
    free(criteriaValues);
}

// выполняет сортировку выбором столбцов матрицы m по неубыванию значения функции criteria
// применяемой для столбцов
void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int const *, int)) {
    int *criteriaValues = (int*)malloc(sizeof(int) * m.nCols);
    int *column = (int*)malloc(sizeof(int) * m.nRows);
    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++)
            column[i] = m.values[i][j];
        criteriaValues[j] = criteria(column, m.nCols);
    }

    for (int i = 0; i < m.nCols; i++) {
        int minIndex = i;
        for (int j = i + 1; j < m.nCols; j++)
            if (criteriaValues[j] < criteriaValues[minIndex])
                minIndex = j;
        if (i != minIndex) {
            swap(&criteriaValues[i], &criteriaValues[minIndex]);
            swapColumns(m, i, minIndex);
        }
    }

    free(column);
    free(criteriaValues);
}

//возвращает значение ’истина’, если
//матрица m является квадратной, ложь – в противном случае
bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols ? true : false;
}

//возвращает значение ’истина’, если матрицы m1 и m2 равны, ложь – в противном случае
bool areTwoMatricesEqual(matrix *m1, matrix *m2) {
    if (m1->nRows == m2->nRows && m1->nCols == m2->nCols) {
        for (int i = 0; i < m1->nRows; ++i) {
            for (int j = 0; j < m1->nCols; ++j) {
                if (m1->values[i][j] != m2->values[i][j])
                    return false;
            }
        }
        return true;
    }
    return false;
}

//возвращает значение ’истина’, если матрица m является единичной, ложь – в противном случае
bool isEMatrix(matrix *m) {
    if (m->nRows != m->nCols)
        return false;
    for (int i = 0; i < m->nRows; ++i) {
        for (int j = 0; j < m->nCols; ++j) {
            if (m->values[i][j] != (i == j))
                return false;
        }
    }
    return true;
}
//возвращает значение ’истина’, если матрица m является симметричной, ложь – в противном случае
bool isSymmetricMatrix(matrix *m) {
    if (m->nRows == m->nCols) {
        for (int i = 0; i < m->nRows; ++i) {
            for (int j = 0; j < m->nCols; ++j) {
                if ((m->values[i][j] != m->values[j][i]) && (j != i))
                    return false;
            }
        }
        return true;
    }
    return false;
}

//транспонирует квадратную матрицу m.
void transposeSquareMatrix(matrix *m) {
    matrix t = getMemMatrix(m->nCols, m->nRows);
    for (int i = 0; i < m->nRows; i++)
        for (int j = 0; j < m->nCols; j++)
            t.values[j][i] = m->values[i][j];
    freeMemMatrix(*m);
    *m = t;
}

//транспонирует матрицу m
void transposeMatrix(matrix *m) {
    matrix t = getMemMatrix(m->nCols, m->nRows);
    for (int i = 0; i < m->nRows; i++)
        for (int j = 0; j < m->nCols; j++)
            t.values[j][i] = m->values[i][j];
    freeMemMatrix(*m);
    *m = t;
}


//возвращает позицию минимального элемента матрицы m.
position getMinValuePos(matrix m) {
    position minPos = {0, 0};
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < m.values[minPos.rowIndex][minPos.colIndex])
                minPos = (position) {i, j};
    return minPos;
}


//возвращает позицию максимального элемента матрицы m.
position getMaxValuePos(matrix m) {
    position maxPos = {0, 0};
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > m.values[maxPos.rowIndex][maxPos.colIndex])
                maxPos = (position) {i, j};
    return maxPos;
}

//возвращает матрицу размера nRows на nCols, построенную из элементов массива a
matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j)
            m.values[i][j] = a[k++];
    }
    return m;
}

//возвращает указатель на нулевую матрицу массива из nMatrices матриц, размещенных
//в динамической памяти, построенных из элементов массива a
matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    for (int i = 0; i < nMatrices; ++i) {
        ms[i] = createMatrixFromArray(values, nRows, nCols);
    }
    return ms;
}
