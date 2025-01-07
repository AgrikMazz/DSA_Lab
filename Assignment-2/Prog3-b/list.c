#include "list.h"

List* createList(int n) {
    List* list = (List*)malloc(sizeof(List));
    list->capacity = n + 1;  // Adding space for sentinel
    list->size = 0;
    list->data = (int*)malloc(list->capacity * sizeof(int));
    list->data[list->capacity - 1] = -1;  // Initial sentinel value at the last position
    return list;
}

void deleteList(List* list) {
    free(list->data);
    free(list);
}

void printList(List* list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int length(List* list) {
    return list->size;
}

int getElement(List* list, int i) {
    if (i >= list->size) {
        return -1;  // Index out of range
    }
    return list->data[i];
}

void append(List* list, int x) {
    if (list->size == list->capacity - 1) {
        printf("List is full\n");
        return;
    }
    list->data[list->size] = x;
    list->size++;
    list->data[list->size] = -1;  // Move sentinel after the new element
}

void insertElement(List* list, int index, int val) {
    if (index < 0 || index > list->size || list->size == list->capacity - 1) {
        printf("Element cannot be inserted.\n");
        return;
    }

    // Shift elements to make room for the new element
    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = val;
    list->size++;

    // Move the sentinel to the new last position
    list->data[list->size] = -1;
}

void modify(List* list, int index, int val) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        return;
    }
    list->data[index] = val;
}

int pop(List* list) {
    if (list->size == 0) {
        return -1;
    }
    int num = list->data[list->size - 1];
    list->size--;
    list->data[list->size] = -1;  // Move the sentinel
    return num;
}

void removeElement(List* list, int val) {
    int pos = -1;
    for (int i = 0; i < list->size; i++) {
        if (list->data[i] == val) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Element not found.\n");
        return;
    }

    // Shift elements to the left
    for (int i = pos; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
    list->data[list->size] = -1;  // Move the sentinel
}

void reverse(List* list) {
    for (int i = 0; i < list->size / 2; i++) {
        int temp = list->data[i];
        list->data[i] = list->data[list->size - i - 1];
        list->data[list->size - i - 1] = temp;
    }
}

void sort(List* list) {
    int n = list->size;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list->data[j] > list->data[j + 1]) {
                int temp = list->data[j];
                list->data[j] = list->data[j + 1];
                list->data[j + 1] = temp;
            }
        }
    }
}