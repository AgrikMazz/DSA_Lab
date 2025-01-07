#include <stdio.h>
#include <stdlib.h>

void compute_remainders(unsigned long long large_ints[], int num_large_ints, int primes[8])
{
    printf("Li\t\t\t");
    for (int i = 0; i < 8; i++)
    {
        printf("P = %d\t", primes[i]);
    }
    printf("\n");

    for (int i = 0; i < num_large_ints; i++)
    {
        printf("%llu\t", large_ints[i]);
        for (int j = 0; j < 8; j++)
        {
            unsigned long long remainder = large_ints[i] % primes[j];
            printf("%llu\t", remainder);
        }
        printf("\n");
    }
}

int main()
{
    unsigned long long large_ints[] = {9876543210ULL, 123456789012ULL, 9876543212345ULL, 123456789098765ULL, 987654321012345ULL, 12345678234567ULL, 987654321654321ULL};
    int num_large_ints = sizeof(large_ints) / sizeof(large_ints[0]);
    int primes[8] = {1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049};

    compute_remainders(large_ints, num_large_ints, primes);

    return 0;
}