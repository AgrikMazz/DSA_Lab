#include <stdio.h>
#include <math.h>

int isPerfect(int n)
{
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return n == sum ? 1 : 0;
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (isPerfect(n) == 0)
    {
        printf("Number is not perfect\n");
        return 0;
    }
    int arr[10];
    int len = (int)log10(n) + 1;

    int i = len - 1;
    while (n > 0)
    {
        arr[i--] = (n % 10) + 97;
        n = n / 10;
    }

    char str[10];
    int j = 0;
    while (j < len)
    {
        char c = arr[j];
        str[j] = c;
        j++;
    }
    str[j] = '\0';
    printf("Resultant string is- %s\n", str);

    return 0;
}