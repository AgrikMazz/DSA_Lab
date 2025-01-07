#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LENGTH 10
#define MAX_SIZE 100000

char *generate_random(int len)
{
    char *str = (char *)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++)
    {
        str[i] = 'A' + (rand() % 26);
    }
    str[len] = '\0';
    return str;
}

int isUnique(char strings[][LENGTH + 1], char *str, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(strings[i], str) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    srand(time(NULL));

    char strings[MAX_SIZE][LENGTH + 1];
    int size = 0;
    while (size < MAX_SIZE)
    {
        char *random_str = generate_random(LENGTH);
        if (isUnique(strings, random_str, size) == 1)
        {
            strcpy(strings[size], random_str);
            size++;
        }
    }

    FILE *fp = fopen("random_strings.txt", "w");
    for (int i = 0; i < MAX_SIZE; i++)
    {
        fprintf(fp, "%s\n", strings[i]);
    }
    fclose(fp);

    return 0;
}