#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 2000

int prime[8] = {1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049};

void convertAndPrintSum(char full_name[])
{
    char largeInt[1000] = "";

    for (int i = 0; i < strlen(full_name); i++)
    {
        char asciiStr[4];
        sprintf(asciiStr, "%d", (int)full_name[i]);
        strcat(largeInt, asciiStr);
    }

    printf("\nLarge Integer: %s\n", largeInt);

    int len = strlen(largeInt), mid = len / 2;

    // Splitting string into two halves

    // 1. First Half
    char firstHalf[500], secondHalf[500];
    strncpy(firstHalf, largeInt, mid);
    firstHalf[mid] = '\0';

    // 2. Second half
    strcpy(secondHalf, largeInt + mid);
    printf("\nFirst Half: %s\n", firstHalf);
    printf("Second Half: %s\n", secondHalf);

    unsigned long long summ = atoll(firstHalf) + atoll(secondHalf);

    // Converting halves to integers
    char sum[MAXLEN] = {0};
    int k = MAXLEN - 1, i = mid - 1, j = len - 1, carry = 0, s;

    while (i >= 0 && j >= mid)
    {
        s = carry + largeInt[i] - '0' + largeInt[j] - '0';
        sum[k--] = (s % 10) + '0';
        carry = s / 10;
        i--, j--;
    }

    for (int i = k + 1; i < MAXLEN; i++)
    {
        sum[i - k - 1] = sum[i];
    }
    sum[i - k - 1] = '\0';

    printf("\nSum of the two halves: %s\n", sum);

    if (summ > LLONG_MAX)
    {
        printf("\nNumber very large. Storage failure\n");
        exit(0);
    }

    // calculating remainder of large sum by dividing it by primes
    printf("\nPrime\t\t\tLarge Int\t\t\t\t\t\tRemainder\n");

    for (int i = 0; i < 8; i++)
    {
        printf("%d\t\t\t%lld\t\t\t\t\t%d\n", prime[i], summ, summ % prime[i]);
    }
}

int main()
{
    char first_name[100];
    char last_name[100];

    printf("Enter your first name: ");
    scanf("%s", first_name);

    printf("Enter your last name: ");
    scanf("%s", last_name);

    convertAndPrintSum(strcat(first_name, last_name));

    return 0;
}