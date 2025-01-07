#include <stdio.h>
#include <string.h>

// Linear Search for Integers
int linear_search_int(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i; 
    }
    return -1; 
}

//Binary Search for Integers
int binary_search_int(int arr[], int n, int target){
    int low=0, high=n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if (arr[mid] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

// Linear Search for Floating Point Numbers
int linear_search_float(float arr[], int n, float target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i; 
    }
    return -1; 
}

//Binary Search for Floating Point Numbers
int binary_search_float(float arr[], int n, float target){
    int low=0, high=n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if (arr[mid] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

// Linear Search for Strings
int linear_search_str(char arr[][20], int n, char target[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i], target) == 0)
            return i; 
    }
    return -1; 
}

//Binary Search for Strings
int binary_search_str(char arr[][20], int n, char target[]){
    int low=0, high=n-1;
    while(low <= high){
        int mid = (low+high)/2;
        int cmp = strcmp(arr[mid], target);
        if(cmp == 0){
            return mid;
        }
        else if(cmp < 0){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main() {
    int arr_int[] = {10, 20, 30, 40, 50};
    float arr_float[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char arr_str[5][20] = {"apple", "banana", "mango", "orange", "watermelon"};

    // Search for Integer
    int target_int = 30;
    int result_int_linear = linear_search_int(arr_int, 5, target_int);
    int result_int_binary = binary_search_int(arr_int, 5, target_int);
    printf("Integer %d is at index (using linear search): %d\n", target_int, result_int_linear);
    printf("Integer %d is at index (using binary search): %d\n", target_int, result_int_binary);

    // Search for Float
    float target_float = 4.4;
    int result_float_linear = linear_search_float(arr_float, 5, target_float);
    int result_float_binary = binary_search_float(arr_float, 5, target_float);
    printf("Float %.2f is at index (using linear search): %d\n", target_float, result_float_linear);
    printf("Float %.2f is at index (using binary search): %d\n", target_float, result_float_binary);

    // Search for String
    char target_str[] = "banana";
    int result_str_linear = linear_search_str(arr_str, 5, target_str);
    int result_str_binary = binary_search_str(arr_str, 5, target_str);
    printf("String %s is at index (using linear search): %d\n", target_str, result_str_linear);
    printf("String %s is at index (using binary search): %d\n", target_str, result_str_binary);

    return 0;
}