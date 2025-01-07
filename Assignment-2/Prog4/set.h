#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int capacity;
    int* data;
} Set;

Set* createSet(int n);
void deleteSet(Set* set);
int isElementInSet(Set* set, int element);
void insertElement(Set* set, int element);
void removeElement(Set* set, int element);
void printSet(Set* set);
Set* unionSet(Set* s1, Set* s2);
Set* intersectionSet(Set* s1, Set* s2);

#endif
