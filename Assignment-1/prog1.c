#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void factorialIterative(int n)
{
    long long f = 1;
    long long fact = 0;
    int flag = 0; // Flag to indicate overflow
    int p = 0;    // Print overflow only once

    for (int i = 2; i <= n; i++)
    {
        // checking overflow
        if (!flag && i >= INT_MAX / f)
        {
            fact = f;
            flag = 1;

            if (!p)
            {
                printf("\nOverflow occurred at i = %d, switching to long long\n", i);
                p = 1;
            }
        }

        if (flag == 1 && i >= LONG_MAX / fact)
        {
            printf("Factorial too large. Aborting....\n");
            exit(0);
        }

        // After overflow, switch to long long and continue calculation
        if (flag)
        {
            fact *= i; // continuing with long long
        }
        else
        {
            f *= i; // continuing with int
        }
    }

    if (flag)
    {
        printf("Integer Overflow\n");
        printf("Factorial: %lld\n", fact);
    }
    else
    {
        printf("\nFactorial: %d\n", f);
    }
}

void factorialRecursive(int i, int flag, int n, long long fact, int f)
{
    if (i == n + 1)
    {
        if (flag)
        {
            printf("Integer overflow\n");
            printf("Factorial: %lld\n", fact);
        }
        else
        {
            printf("\nFactorial: %d\n", f);
        }
        return;
    }

    if (!flag)
    {
        if (i >= INT_MAX / f)
        {
            fact = f;
            flag = 1;
            printf("\nOverflow occurred at i = %d, switching to long long\n", i);
        }
    }

    if (flag)
    {
        fact *= i;
    }
    else
    {
        f *= i;
    }

    factorialRecursive(i + 1, flag, n, fact, f);
}

int main()
{
    int n;
    printf("Enter values of n: ");
    scanf("%d", &n);

    printf("\nITERATIVE: n = %d\n", n);
    printf("\ncalculating %d!...", n);
    factorialIterative(n);

    printf("---------------------------------------------------------------\n");

    printf("\nRECURSIVE: n = %d\n", n);
    // recursive (without overflow)
    printf("\ncalculating %d!...", n);
    factorialRecursive(1, 0, n, 1, 1);

    return 0;
}
