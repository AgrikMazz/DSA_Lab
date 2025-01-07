#include "llarray.h"

void initList(LinkedList* list) {
    list->head = -1;
    list->free = 0;

    for (int i = 0; i < MAX_SIZE - 1; i++) {
        list->pool[i].next = i + 1;
    }
    list->pool[MAX_SIZE - 1].next = -1;
}

int allocateNode(LinkedList* list, int value) {
    if (list->free == -1) {
        printf("No free nodes available.\n");
        return -1;
    }
    int newIndex = list->free;
    list->free = list->pool[newIndex].next;
    list->pool[newIndex].value = value;
    list->pool[newIndex].next = -1;
    return newIndex;
}

void freeNode(LinkedList* list, int index) {
    list->pool[index].next = list->free;
    list->free = index;
}

void Build_list(LinkedList* list, int size) {
    initList(list);
    printf("Enter %d values: ", size);
    for (int i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);
        int newIndex = allocateNode(list, value);
        if (i == 0) {
            list->head = newIndex;
        } else {
            int curr = list->head;
            while (list->pool[curr].next != -1) {
                curr = list->pool[curr].next;
            }
            list->pool[curr].next = newIndex;
        }
    }
}

void Build_list_reverse(LinkedList* list, int size) {
    initList(list);
    printf("Enter %d values: ", size);
    for (int i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);
        int newIndex = allocateNode(list, value);
        list->pool[newIndex].next = list->head;
        list->head = newIndex;
    }
}

void printList(LinkedList* list) {
    int curr = list->head;
    while (curr != -1) {
        printf("%d ", list->pool[curr].value);
        curr = list->pool[curr].next;
    }
    printf("\n");
}

void printListReverse(LinkedList* list, int index) {
    if (index == -1) return;
    printListReverse(list, list->pool[index].next);
    printf("%d ", list->pool[index].value);
}

int findSize(LinkedList* list) {
    int size = 0, curr = list->head;
    while (curr != -1) {
        size++;
        curr = list->pool[curr].next;
    }
    return size;
}

bool areEqual(LinkedList* list1, LinkedList* list2) {
    int curr1 = list1->head, curr2 = list2->head;
    while (curr1 != -1 && curr2 != -1) {
        if (list1->pool[curr1].value != list2->pool[curr2].value) {
            return false;
        }
        curr1 = list1->pool[curr1].next;
        curr2 = list2->pool[curr2].next;
    }
    return (curr1 == -1 && curr2 == -1);
}


int searchKey(LinkedList* list, int key, bool ordered) {
    int curr = list->head;
    int prev = -1;

    while (curr != -1) {
        if (list->pool[curr].value == key) {
            if (prev != -1) {
                list->pool[prev].next = list->pool[curr].next;
            } else {
                list->head = list->pool[curr].next;
            }
            freeNode(list, curr);
            return 1;  
        }
        prev = curr;
        curr = list->pool[curr].next;
        if (ordered && list->pool[curr].value > key) break;  
    }
    return 0;  
}

void appendList(LinkedList* list1, LinkedList* list2) {
    if (list1->head == -1) {
        list1->head = list2->head;
        return;
    }

    int curr = list1->head;
    while (list1->pool[curr].next != -1) {
        curr = list1->pool[curr].next;
    }
    list1->pool[curr].next = list2->head;
    list2->head = -1;  
}

void deleteNthNode(LinkedList* list, int pos) {
    if (pos == 1) {
        int temp = list->head;
        list->head = list->pool[temp].next;
        freeNode(list, temp);
        return;
    }
    
    int curr = list->head;
    for (int i = 1; curr != -1 && i < pos - 1; i++) {
        curr = list->pool[curr].next;
    }

    if (curr == -1 || list->pool[curr].next == -1) return;

    int temp = list->pool[curr].next;
    list->pool[curr].next = list->pool[temp].next;
    freeNode(list, temp);
}

bool isOrdered(LinkedList* list) {
    if (list->head == -1) return true;

    int curr = list->head;
    while (list->pool[curr].next != -1) {
        if (list->pool[curr].value > list->pool[list->pool[curr].next].value) {
            return false;
        }
        curr = list->pool[curr].next;
    }
    return true;
}

void mergeSortedLists(LinkedList* list1, LinkedList* list2, LinkedList* result) {
    int curr1 = list1->head, curr2 = list2->head;
    result->head = -1;
    int currResult = -1;

    while (curr1 != -1 && curr2 != -1) {
        int newIndex;
        if (list1->pool[curr1].value <= list2->pool[curr2].value) {
            newIndex = allocateNode(result, list1->pool[curr1].value);
            curr1 = list1->pool[curr1].next;
        } else {
            newIndex = allocateNode(result, list2->pool[curr2].value);
            curr2 = list2->pool[curr2].next;
        }

        if (result->head == -1) {
            result->head = newIndex;
        } else {
            result->pool[currResult].next = newIndex;
        }
        currResult = newIndex;
    }

    while (curr1 != -1) {
        int newIndex = allocateNode(result, list1->pool[curr1].value);
        if (result->head == -1) {
            result->head = newIndex;
        } else {
            result->pool[currResult].next = newIndex;
        }
        currResult = newIndex;
        curr1 = list1->pool[curr1].next;
    }

    while (curr2 != -1) {
        int newIndex = allocateNode(result, list2->pool[curr2].value);
        if (result->head == -1) {
            result->head = newIndex;
        } else {
            result->pool[currResult].next = newIndex;
        }
        currResult = newIndex;
        curr2 = list2->pool[curr2].next;
    }
}

void insertTargetNode(LinkedList* list, int value, int before) {
    int curr = list->head;
    int prev = -1;

    while (curr != -1) {
        if (list->pool[curr].value == before) {
            int newIndex = allocateNode(list, value);
            if (prev != -1) {
                list->pool[prev].next = newIndex;
            } else {
                list->head = newIndex;
            }
            list->pool[newIndex].next = curr;
            return;
        }
        prev = curr;
        curr = list->pool[curr].next;
    }
}

void removeDuplicates(LinkedList* list, bool ordered) {
    int curr = list->head;
    while (curr != -1) {
        int prev = curr;
        int nextNode = list->pool[curr].next;

        while (nextNode != -1) {
            if (list->pool[curr].value == list->pool[nextNode].value) {
                list->pool[prev].next = list->pool[nextNode].next;
                freeNode(list, nextNode);
                nextNode = list->pool[prev].next;
            } else {
                prev = nextNode;
                nextNode = list->pool[nextNode].next;
            }
        }
        curr = list->pool[curr].next;
        if (ordered && curr != -1 && list->pool[curr].value > list->pool[prev].value) {
            break;  
        }
    }
}

void swapPairwise(LinkedList* list) {
    int curr = list->head;
    while (curr != -1 && list->pool[curr].next != -1) {
        int nextNode = list->pool[curr].next;
        int temp = list->pool[curr].value;
        list->pool[curr].value = list->pool[nextNode].value;
        list->pool[nextNode].value = temp;

        curr = list->pool[nextNode].next;
    }
}

void moveLastToFront(LinkedList* list) {
    if (list->head == -1 || list->pool[list->head].next == -1) return;

    int curr = list->head;
    int prev = -1;

    while (list->pool[curr].next != -1) {
        prev = curr;
        curr = list->pool[curr].next;
    }

    list->pool[prev].next = -1;
    list->pool[curr].next = list->head;
    list->head = curr;
}

void deleteAlternateNodes(LinkedList* list) {
    int curr = list->head;
    while (curr != -1 && list->pool[curr].next != -1) {
        int nextNode = list->pool[curr].next;
        list->pool[curr].next = list->pool[nextNode].next;
        freeNode(list, nextNode);
        curr = list->pool[curr].next;
    }
}

void rotateList(LinkedList* list, int k) {
    int size = findSize(list);
    if (k <= 0 || k >= size) return;

    int curr = list->head;
    for (int i = 1; i < size - k; i++) {
        curr = list->pool[curr].next;
    }

    int newHead = list->pool[curr].next;
    list->pool[curr].next = -1;

    int temp = newHead;
    while (list->pool[temp].next != -1) {
        temp = list->pool[temp].next;
    }

    list->pool[temp].next = list->head;
    list->head = newHead;
}

void deleteList(LinkedList* list) {
    int curr = list->head;
    while (curr != -1) {
        int temp = curr;
        curr = list->pool[curr].next;
        freeNode(list, temp);
    }
    list->head = -1;
}

void reverseList(LinkedList* list) {
    int prev = -1;
    int curr = list->head;
    while (curr != -1) {
        int nextNode = list->pool[curr].next;
        list->pool[curr].next = prev;
        prev = curr;
        curr = nextNode;
    }
    list->head = prev;
}

void sortList(LinkedList* list) {
    int swapped;
    do {
        swapped = 0;
        int curr = list->head;
        while (list->pool[curr].next != -1) {
            int nextNode = list->pool[curr].next;
            if (list->pool[curr].value > list->pool[nextNode].value) {
                int temp = list->pool[curr].value;
                list->pool[curr].value = list->pool[nextNode].value;
                list->pool[nextNode].value = temp;
                swapped = 1;
            }
            curr = list->pool[curr].next;
        }
    } while (swapped);
}