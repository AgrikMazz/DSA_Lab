#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

int main()
{
    srand(time(NULL));

    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = i + 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        int random = rand() % SIZE;
        int temp = arr[i];
        arr[i] = arr[random];
        arr[random] = temp;
    }

    FILE *fp = fopen("file.txt", "w");
    for (int i = 0; i < SIZE; i++)
    {
        fprintf(fp, "%d\n", arr[i]);
    }

    fclose(fp);
    return 0;
}