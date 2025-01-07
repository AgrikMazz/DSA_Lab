#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int rows;
    int cols;
    int tot;
    int** data;
} SparseMatrix;

SparseMatrix* createMatrix();
SparseMatrix* emptyMatrix(int r,int c);
void display(SparseMatrix* mat);
SparseMatrix* scalarMultiply(SparseMatrix* mat, int x);
SparseMatrix* transpose(SparseMatrix* mat);
SparseMatrix* add(SparseMatrix* mat1, SparseMatrix* mat2);
SparseMatrix* subtract(SparseMatrix* mat1, SparseMatrix* mat2);
SparseMatrix* multiply(SparseMatrix* mat1, SparseMatrix* mat2);

#endif