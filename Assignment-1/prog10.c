#include <stdio.h>
#include <string.h>

#define MAXLEN 100

int editDistance(char *X, char *Y){
    int m = strlen(X), n = strlen(Y);

    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    int lcs = L[m][n];

    return (m - lcs) + (n - lcs);
}

int main()
{
    char X[MAXLEN], Y[MAXLEN];
    printf("Enter first string: ");
    scanf("%s", &X);

    printf("Enter second string: ");
    scanf("%s", &Y);

    printf("Edit Distance: %d\n", editDistance(X, Y));

    return 0;
}