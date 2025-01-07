#include "polynomial.h"

int main() {
    int choice;
    Polynomial *p1, *p2, *result;
    int x, scalar;

    do {
        printf("Polynomial Menu:\n");
        printf("1. Create Polynomial\n");
        printf("2. Display Polynomial\n");
        printf("3. Get degree of Polynomial\n");
        printf("4. Scalar Multiply Polynomial\n");
        printf("5. Evaluate Polynomial\n");
        printf("6. Add Polynomials\n");
        printf("7. Subtract Polynomials\n");
        printf("8. Multiply Polynomials\n");
        printf("9. Polynomial power\n");
        printf("10. Polynomial composition\n");
        printf("11. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                p1 = createPolynomial();
                printf("Polynomial created\n");
                break;
            case 2:
                p1 = createPolynomial();
                display(p1);
                break;
            case 3:
                p1 = createPolynomial();
                getDegree(p1);
                break;
            case 4:
                printf("Create polynomial:\n");
                p1 = createPolynomial();
                printf("Enter scalar value: ");
                scanf("%d", &scalar);
                result = scalarMultiply(p1, scalar);
                display(p1);
                printf("Result of scalar multiplication: ");
                display(result);
                break;
            case 5:
                printf("Create polynomial:\n");
                p1 = createPolynomial();
                printf("Enter the value of x to evaluate polynomial: ");
                scanf("%d", &x);
                display(p1);
                printf("Result of evaluation: %lld\n", evaluate(p1, x));
                break;
            case 6:
                printf("Create first polynomial:\n");
                p1 = createPolynomial();
                printf("Create second polynomial:\n");
                p2 = createPolynomial();
                result = add(p1, p2);
                display(p1);
                display(p2);
                printf("Result of addition: ");
                display(result);
                break;
            case 7:
                printf("Create first polynomial:\n");
                p1 = createPolynomial();
                printf("Create second polynomial:\n");
                p2 = createPolynomial();
                result = sub(p1, p2);
                display(p1);
                display(p2);
                printf("Result of subtraction: ");
                display(result);
                break;
            case 8:
                printf("Create first polynomial:\n");
                p1 = createPolynomial();
                printf("Create second polynomial:\n");
                p2 = createPolynomial();
                result = mul(p1, p2);
                display(p1);
                display(p2);
                printf("Result of multiplication: ");
                display(result);
                break;
            case 9:
                printf("Create polynomial:\n");
                p1 = createPolynomial();
                int num;
                printf("Enter number: ");
                scanf("%d",&num);
                display(p1);
                result = power(p1,num);
                printf("Result of power: ");
                display(result);
                break;
            case 10:
                printf("Create first polynomial:\n");
                p1 = createPolynomial();
                printf("Create second polynomial:\n");
                p2 = createPolynomial();
                result = composition(p1, p2);
                display(p1);
                display(p2);
                printf("Result of composition: ");
                display(result);
            case 11:
                printf("Exited\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 11);

    return 0;
}