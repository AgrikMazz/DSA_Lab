#include "sparsematrix.h"

SparseMatrix* createMatrix(){
    SparseMatrix* mat = (SparseMatrix* )malloc(sizeof(SparseMatrix));

    printf("Enter number of rows of the matrix: ");
    scanf("%d", &mat->rows);
    printf("Enter number of columns of the matrix: ");
    scanf("%d", &mat->cols);
    printf("Enter number of non-zero terms: ");
    scanf("%d", &mat->tot);

    mat->data = (int**)malloc(mat->tot * sizeof(int*));
    for(int i=0; i<mat->tot; i++){
        mat->data[i] = (int*)malloc(3 * sizeof(int));
    }

    for(int i=0; i<mat->tot; i++){
        printf("Enter row-position, column-position, and value for element %d: ", i + 1);
        scanf("%d %d %d", &mat->data[i][0], &mat->data[i][1], &mat->data[i][2]);
    }

    return mat;
}

SparseMatrix* emptyMatrix(int r,int c){
    SparseMatrix* mat = (SparseMatrix* )malloc(sizeof(SparseMatrix));
    mat->rows = r;
    mat->cols = c;
    mat->tot = 0;
    mat->data = NULL;
    return mat;
}

void display(SparseMatrix* mat){
    if(mat == NULL){
        printf("No matrix initialised\n");
        return;
    }
    printf("Matrix Dimensions: Rows = %d, Columns = %d\n", mat->rows, mat->cols);
    if(mat->tot == 0){
        printf("No non-zero elements present inside matrix\n");
        return;
    }
    printf("Row\tCol\tValue\n");
    for(int i=0; i<mat->tot; i++){
        printf("%d\t%d\t%d\n",mat->data[i][0],mat->data[i][1],mat->data[i][2]);
    }
}

SparseMatrix* scalarMultiply(SparseMatrix* mat, int x){
    SparseMatrix* result = emptyMatrix(mat->rows, mat->cols);
    result->tot = mat->tot;

    result->data = (int**)malloc(result->tot * sizeof(int*));
    for(int i=0; i<result->tot; i++){
        result->data[i] = (int*)malloc(3 * sizeof(int));
    }

    for(int i=0; i<result->tot; i++){
        result->data[i][0] = mat->data[i][0]; 
        result->data[i][1] = mat->data[i][1];
        result->data[i][2] = x * mat->data[i][2];
    }
    return result;
}

SparseMatrix* transpose(SparseMatrix* mat){
    SparseMatrix* result = emptyMatrix(mat->cols,mat->rows);
    result->tot = mat->tot;

    result->data = (int**)malloc(result->tot * sizeof(int*));
    for(int i=0; i<result->tot; i++){
        result->data[i] = (int*)malloc(3 * sizeof(int));
    }

    for(int i=0; i<result->tot; i++){
        result->data[i][0] = mat->data[i][1]; 
        result->data[i][1] = mat->data[i][0];
        result->data[i][2] = mat->data[i][2];
    }
    return result;
}

SparseMatrix* add(SparseMatrix* mat1, SparseMatrix* mat2){
    if((mat1->rows != mat2->rows) || (mat1->cols != mat2->cols)){
        printf("Addition cannot be performed as dimensions of matrices do not match.\n");
        return NULL;
    }
    SparseMatrix* result = emptyMatrix(mat1->rows, mat1->cols);
    result->data = (int**)malloc((mat1->tot + mat2->tot) * sizeof(int*));
    for (int i = 0; i < (mat1->tot + mat2->tot); i++) {
        result->data[i] = (int*)malloc(3 * sizeof(int));
    }

    int i=0, j=0, k=0;
    while (i < mat1->tot && j < mat2->tot) {
        if (mat1->data[i][0] < mat2->data[j][0] || (mat1->data[i][0] == mat2->data[j][0] && mat1->data[i][1] < mat2->data[j][1])) {
            result->data[k][0] = mat1->data[i][0];
            result->data[k][1] = mat1->data[i][1];
            result->data[k][2] = mat1->data[i][2];
            i++;
        } 
        else if (mat1->data[i][0] > mat2->data[j][0] || (mat1->data[i][0] == mat2->data[j][0] && mat1->data[i][1] > mat2->data[j][1])) {
            result->data[k][0] = mat2->data[j][0];
            result->data[k][1] = mat2->data[j][1];
            result->data[k][2] = mat2->data[j][2];
            j++;
        } 
        else {
            int sum = mat1->data[i][2] + mat2->data[j][2];
            if (sum != 0) { 
                result->data[k][0] = mat1->data[i][0];
                result->data[k][1] = mat1->data[i][1];
                result->data[k][2] = sum;
            } 
            else {
                k--; 
            }
            i++;
            j++;
        }
        k++;
    }
    
    while (i < mat1->tot) {
        result->data[k][0] = mat1->data[i][0];
        result->data[k][1] = mat1->data[i][1];
        result->data[k][2] = mat1->data[i][2];
        i++;
        k++;
    }
    
    while (j < mat2->tot) {
        result->data[k][0] = mat2->data[j][0];
        result->data[k][1] = mat2->data[j][1];
        result->data[k][2] = mat2->data[j][2];
        j++;
        k++;
    }
    
    result->tot = k;
    return result;
}

SparseMatrix* subtract(SparseMatrix* mat1, SparseMatrix* mat2){
    if((mat1->rows != mat2->rows) || (mat1->cols != mat2->cols)){
        printf("Subtraction cannot be performed as dimensions of matrices do not match.\n");
        return NULL;
    }
    SparseMatrix* result = emptyMatrix(mat1->rows, mat1->cols);
    result->data = (int**)malloc((mat1->tot + mat2->tot) * sizeof(int*));
    for(int i = 0; i < (mat1->tot + mat2->tot); i++){
        result->data[i] = (int*)malloc(3 * sizeof(int));
    }

    int i=0, j=0, k=0;
    while (i < mat1->tot && j < mat2->tot) {
        if (mat1->data[i][0] < mat2->data[j][0] || (mat1->data[i][0] == mat2->data[j][0] && mat1->data[i][1] < mat2->data[j][1])) {
            result->data[k][0] = mat1->data[i][0];
            result->data[k][1] = mat1->data[i][1];
            result->data[k][2] = mat1->data[i][2];
            i++;
        } 
        else if (mat1->data[i][0] > mat2->data[j][0] || (mat1->data[i][0] == mat2->data[j][0] && mat1->data[i][1] > mat2->data[j][1])) {
            result->data[k][0] = mat2->data[j][0];
            result->data[k][1] = mat2->data[j][1];
            result->data[k][2] = -mat2->data[j][2];
            j++;
        } 
        else {
            int diff = mat1->data[i][2] - mat2->data[j][2];
            if (diff != 0) { 
                result->data[k][0] = mat1->data[i][0];
                result->data[k][1] = mat1->data[i][1];
                result->data[k][2] = diff;
            } 
            else {
                k--; 
            }
            i++;
            j++;
        }
        k++;
    }
    
    while (i < mat1->tot) {
        result->data[k][0] = mat1->data[i][0];
        result->data[k][1] = mat1->data[i][1];
        result->data[k][2] = mat1->data[i][2];
        i++;
        k++;
    }
    
    while (j < mat2->tot) {
        result->data[k][0] = mat2->data[j][0];
        result->data[k][1] = mat2->data[j][1];
        result->data[k][2] = mat2->data[j][2];
        j++;
        k++;
    }
    
    result->tot = k;
    return result;
}

SparseMatrix* multiply(SparseMatrix* mat1, SparseMatrix* mat2){
    if(mat1->cols != mat2->rows){
        printf("Multiplication cannot be performed.\n");
        return NULL;
    }
    SparseMatrix* result = emptyMatrix(mat1->rows, mat2->cols);

    int** tempResult = (int**)malloc(mat1->rows * sizeof(int*));
    for (int i = 0; i < mat1->rows; i++) {
        tempResult[i] = (int*)calloc(mat2->cols, sizeof(int)); 
    }

    for (int i = 0; i < mat1->tot; i++) {
        int row1 = mat1->data[i][0];
        int col1 = mat1->data[i][1];
        int val1 = mat1->data[i][2];

        for (int j = 0; j < mat2->tot; j++) {
            int row2 = mat2->data[j][0];
            int col2 = mat2->data[j][1];
            int val2 = mat2->data[j][2];

            if (col1 == row2) {
                tempResult[row1][col2] += val1 * val2;
            }
        }
    }

    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            if (tempResult[i][j] != 0) {
                result->data = (int**)realloc(result->data, (result->tot + 1) * sizeof(int*));
                result->data[result->tot] = (int*)malloc(3 * sizeof(int));
                result->data[result->tot][0] = i;
                result->data[result->tot][1] = j;
                result->data[result->tot][2] = tempResult[i][j];
                result->tot++;
            }
        }
    }

    for (int i = 0; i < mat1->rows; i++) {
        free(tempResult[i]);
    }
    free(tempResult);

    return result;
}