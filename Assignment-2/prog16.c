#include<stdio.h>
#include <stdlib.h>
#include<time.h>

// Global variable to count comparisons
long long comparisons = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Selection Sort
void selection_sort(int arr[], int n) {
    comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

//Bubble sort
void bubble_sort(int arr[], int n) {
    int swapped = 0;
    comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
}

//Insertion sort
void insertion_sort(int arr[], int n) {
    comparisons = 0;
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0) {
            comparisons++;
            if (arr[j - 1] > arr[j]) {
                swap(&arr[j - 1], &arr[j]);
                j--;
            } else {
                break;
            }
        }
    }
}
//Merge Sort
void merge(int arr[], int low, int mid, int high) {
    int temp[high - low + 1];
    int k = 0;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        comparisons++;
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }

    while (left <= mid) {
        temp[k++] = arr[left++];
    }
    while (right <= high) {
        temp[k++] = arr[right++];
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void merge_sort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

// Wrapper for merge_sort
void mergeSortWrapper(int arr[], int n) {
    comparisons = 0; // Reset comparisons
    merge_sort(arr, 0, n - 1);
}

//Quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            comparisons++;
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            comparisons++;
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }
    int pivot_index = partition(arr, low, high);
    quickSort(arr, low, pivot_index - 1);
    quickSort(arr, pivot_index + 1, high);
}

// Wrapper for quickSort
void quickSortWrapper(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}

//Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    comparisons++;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    comparisons++;
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    comparisons = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void testSortingAlgorithm(void (*sortFunc)(int*, int), int arr[], int n, const char* algoName) {
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    comparisons = 0;
    clock_t start = clock();
    sortFunc(temp, n);
    clock_t end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%s:\n", algoName);
    // printf("Sorted Array: ");
    // printArray(temp, n);
    printf("Comparisons: %lld\n", comparisons);
    printf("Time Taken: %f seconds\n\n", timeTaken);
}

int main() {
    srand(time(NULL));
    
    int n;
    printf("Enter no of elements in array: ");
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        int random = rand() % n;
        int temp = arr[i];
        arr[i] = arr[random];
        arr[random] = temp;           
    }

    // printf("Original Array: ");
    // printArray(arr, n);
    // printf("\n");

    testSortingAlgorithm(selection_sort, arr, n, "Selection Sort");
    testSortingAlgorithm(bubble_sort, arr, n, "Bubble Sort");
    testSortingAlgorithm(insertion_sort, arr, n, "Insertion Sort");
    testSortingAlgorithm(mergeSortWrapper, arr, n, "Merge Sort");
    testSortingAlgorithm(quickSortWrapper, arr, n, "Quick Sort");
    testSortingAlgorithm(heapSort, arr, n, "Heap Sort");

    return 0;
}