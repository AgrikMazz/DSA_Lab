#include "sparsematrix.h"

int main() {
    SparseMatrix *matrix1 = NULL, *matrix2 = NULL, *result = NULL;
    int choice, scalar;

    while (1) {
        printf("\n--- Sparse Matrix Operations ---\n");
        printf("1. Create a new matrix\n");
        printf("2. Display a matrix\n");
        printf("3. Transpose a matrix\n");
        printf("4. Scalar multiplication of a matrix\n");
        printf("5. Add two matrices\n");
        printf("6. Subtract two matrices\n");
        printf("7. Multiply two matrices\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Creating matrix...\n");
                matrix1 = createMatrix();
                printf("Matrix created successfully.\n");
                break;

            case 2:
                printf("Displaying matrix...\n");
                display(matrix1);
                break;

            case 3:
                printf("Transposing matrix...\n");
                result = transpose(matrix1);
                display(result);
                break;

            case 4:
                printf("Enter scalar value to multiply: ");
                scanf("%d", &scalar);
                result = scalarMultiply(matrix1, scalar);
                printf("Result after scalar multiplication:\n");
                display(result);
                break;

            case 5:
                printf("Enter details of second matrix to add:\n");
                matrix2 = createMatrix();
                result = add(matrix1, matrix2);
                if (result != NULL) {
                    printf("Result after addition:\n");
                    display(result);
                }
                break;

            case 6:
                printf("Enter details of second matrix to subtract:\n");
                matrix2 = createMatrix();
                result = subtract(matrix1, matrix2);
                if (result != NULL) {
                    printf("Result after subtraction:\n");
                    display(result);
                }
                break;

            case 7:
                printf("Enter details of second matrix to multiply:\n");
                matrix2 = createMatrix();
                result = multiply(matrix1, matrix2);
                if (result != NULL) {
                    printf("Result after multiplication:\n");
                    display(result);
                }
                break;

            case 8:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
