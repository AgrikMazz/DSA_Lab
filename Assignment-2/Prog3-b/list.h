#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int capacity;
    int* data;
} List;

List* createList(int n);
void deleteList(List* list);
void printList(List* list);
int length(List* list);
int getElement(List* list, int i);
void append(List* list, int x);
void insertElement(List* list, int index, int val);
void modify(List* list, int index, int val);
int pop(List* list);
void removeElement(List* list, int val);
void reverse(List* list);
void sort(List* list);

#endif
