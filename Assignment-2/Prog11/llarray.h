#ifndef LLARRAY_H
#define LLARRAY_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    int next; 
} Node;

typedef struct {
    Node pool[MAX_SIZE];
    int head;      
    int free;      
} LinkedList;

void initList(LinkedList* list);
void Build_list(LinkedList* list, int size);
void Build_list_reverse(LinkedList* list, int size);
void printList(LinkedList* list);
void printListReverse(LinkedList* list, int index);
int findSize(LinkedList* list);
bool areEqual(LinkedList* list1, LinkedList* list2);
int searchKey(LinkedList* list, int key, bool ordered);
void appendList(LinkedList* list1, LinkedList* list2);
void deleteNthNode(LinkedList* list, int pos);
bool isOrdered(LinkedList* list);
void mergeSortedLists(LinkedList* list1, LinkedList* list2, LinkedList* result);
void insertTargetNode(LinkedList* list, int value, int before);
void removeDuplicates(LinkedList* list, bool ordered);
void swapPairwise(LinkedList* list);
void moveLastToFront(LinkedList* list);
void deleteAlternateNodes(LinkedList* list);
void rotateList(LinkedList* list, int k);
void deleteList(LinkedList* list);
void reverseList(LinkedList* list);
void sortList(LinkedList* list);

#endif
