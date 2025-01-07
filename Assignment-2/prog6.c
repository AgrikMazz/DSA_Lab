#include <stdio.h>

void checkSorted(int arr[], int n){
    int asc = 1;
    int desc = 1;
    int eql = 1;
    if (n == 1){
        printf("Only one element\n");
        return;
    }
    for (int i = 0; i < n - 1; i++){
        if (arr[i] != arr[i + 1])
            eql = 0;
        if (arr[i] < arr[i + 1])
            desc = 0;
        if (arr[i] > arr[i + 1])
            asc = 0;

        if (!eql && !asc && !desc)
        {
            printf("Not sorted\n");
            return;
        }
    }
    if (eql){
        printf("Elements are equal\n");
        return;
    }
    if (asc){
        printf("Elements are ascending\n");
        return;
    }
    if (desc){
        printf("Elements are descending\n");
        return;
    }
}

int main(){
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    checkSorted(arr, n);

    return 0;
}
