#include <stdio.h>
#include <time.h>
#include <limits.h>

int fibonacciIterative(int n)
{
    if (n < 0)
    {
        printf("Invalid input\n");
    }
    if (n == 0 || n == 1)
    {
        printf("%dth fibonacci number: %d\n", n, n);
    }

    int first = 0, second = 1, third;
    long long int First, Second, Third;
    int flag = 0;

    for (int i = 2; i <= n; i++)
    {
        if (!flag)
        {
            if (first > INT_MAX - second)
            {
                printf("Integer overflow at n = %d\n", i);
                First = first;
                Second = second;
                flag = 1;
            }
            else
            {
                third = first + second;
                first = second;
                second = third;
            }
        }

        if (flag)
        {
            Third = First + Second;
            First = Second;
            Second = Third;
        }
    }

    if (flag)
    {
        printf("Switching to long long...\n");
        printf("%dth fibonacci number: %lld\n", n, Third);
    }
    else
    {
        printf("%dth fibonacci number: %d\n", n, third);
    }

    // if integer overflow, return where it overflows
    if (flag)
        return n;

    return -1;
}

int intfibonacciRecursive(int n)
{
    if (n < 0)
    {
        printf("Invalid Input\n");
    }

    if (n == 0 || n == 1)
    {
        return n;
    }

    return intfibonacciRecursive(n - 1) + intfibonacciRecursive(n - 2);
}

long long longfibonacciRecursive(int n)
{
    if (n < 0)
    {
        printf("Invalid Input\n");
    }

    if (n == 0 || n == 1)
    {
        return n;
    }

    return longfibonacciRecursive(n - 1) + longfibonacciRecursive(n - 2);
}
int main()
{
    int n, x;
    char ch;
    long long overflow;

    printf("Enter values of n: ");
    scanf("%d", &n);
    getchar();

    // ITERATIVE

    printf("\nITERATIVE: n = %d\n", n);

    printf("\ncalculating %dth fibonacci number...\n", n);
    overflow = fibonacciIterative(n);

    // time elapsed iterative
    double timeI = 1.0 * clock() / CLOCKS_PER_SEC;
    printf("\nTime elapsed (iterative): %.15lf\n", timeI);

    printf("---------------------------------------------------------------\n");

    // RECURSIVE

    printf("\nRECURSIVE: n = %d", n);

    printf("\ncalculating %dth fibonacci number...\n", n);
    if (overflow != -1)
    {
        printf("Integer overflow at n = %d\n", overflow);
        printf("Switching to long long...\n");
        printf("%dth fibonacci number: %lld\n", n, longfibonacciRecursive(n));
    }

    else
    {
        printf("%dth fibonacci number: %d\n", n, intfibonacciRecursive(n));
    }

    // time elapsed recursive
    double timeR = 1.0 * clock() / CLOCKS_PER_SEC;
    printf("\nTime elapsed (recursive): %.15lf\n", timeR - timeI);

    return 0;
}