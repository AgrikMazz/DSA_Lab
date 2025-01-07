#include <stdio.h>
#include <string.h>

void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void generate(char* str, int n, int pos, int max_len){
    if (pos == max_len){
        for (int i = 0; i < max_len; i++) {
            printf("%c", str[i]);
        }
        printf("\n");
        return;
    }

    for (int i = pos; i < n; i++){
        swap(&str[pos], &str[i]);  // Swap current index with the loop index
        generate(str, n, pos + 1, max_len); // Recur with the next position
        swap(&str[pos], &str[i]);  // Swap back to backtrack
    }
}

int main(){
    char str[] = "abcdef";  
    int n = strlen(str);
    for (int length = 3; length <= 6; length++){
        printf("Permutations of length %d:\n", length);
        generate(str, n, 0, length);  // Generate permutations of specified length
        printf("\n");
    }
    return 0;
}