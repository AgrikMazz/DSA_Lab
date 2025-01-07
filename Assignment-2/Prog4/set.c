#include "set.h"

Set* createSet(int n){
    Set* set = (Set*)malloc(sizeof(Set));
    set->capacity = n;
    set->size = 0;
    set->data = (int*)malloc(set->capacity * sizeof(int));
    return set;
}

void deleteSet(Set* set) {
    free(set->data);
    free(set);
}

int isElementInSet(Set *set, int element) {
    for (int i = 0; i < set->size; i++) {
        if (set->data[i] == element) {
            return 1; 
        }
    }
    return 0; 
}

void insertElement(Set *set, int element) {
    if (set->size >= set->capacity) {
        printf("Set is full, cannot insert more elements.\n");
        return;
    }
    if (isElementInSet(set, element)) return;

    int pos = set->size;
    while(pos > 0 && set->data[pos - 1] > element){
        set->data[pos] = set->data[pos-1];
        pos--;
    }
    set->data[pos] = element;
    set->size++;
}

void removeElement(Set *set, int element) {
    for (int i = 0; i < set->size; i++) {
        if (set->data[i] == element) {
            for (int j = i; j < set->size - 1; j++) {
                set->data[j] = set->data[j + 1];
            }
            set->size--;
            return;
        }
    }
    printf("Element %d not found in the set.\n", element);
}

void printSet(Set *set) {
    if (set->size == 0) {
        printf("Set is empty.\n");
        return;
    }

    printf("Set elements: ");
    for (int i = 0; i < set->size; i++) {
        printf("%d ", set->data[i]);
    }
    printf("\n");
}

Set* unionSet(Set* s1, Set* s2){
    Set* res = createSet(s1->size + s2->size);
    for(int i=0; i<s1->size; i++){
        insertElement(res,s1->data[i]);
    }
    for(int i=0; i<s2->size; i++){
        if(!isElementInSet(s1, s2->data[i])){
            insertElement(res,s2->data[i]);
        }
    }
    return res;
}

Set* intersectionSet(Set* s1, Set* s2){
    int maxSize = (s1->size <= s2->size) ? s1->size : s2->size;
    Set* res = createSet(maxSize);
    for(int i=0; i<maxSize; i++){
        if(isElementInSet(s2, s1->data[i])){
            insertElement(res,s1->data[i]);
        }
    }
    return res;
}
