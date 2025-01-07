#include "linkedlistfunc.h"

struct Node* BuildList(int size) {
    struct Node* head = init_l(head);
    int x;
    printf("Enter value of node-1: ");
    scanf("%d", &x);
    insert_front(createNode(x), &head);
    
    struct Node* curr = head;
    for (int i = 2; i <= size; i++) {
        printf("Enter value of node-%d: ", i);
        scanf("%d", &x);
        insert_after(createNode(x), curr);
        curr = curr->next;
    }
    return head;
}

void Print_list(struct Node* head) {
    if (!head) return;
    printf("Elements of list in same order:\n");
    struct Node* curr = head;
    while (curr) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

void Print_list_Reverse(struct Node* head) {
    if (!head) return;
    Print_list_Reverse(head->next);
    printf("%d ",head->val);
}

int findSize(struct Node* head) {
    if (!head) return 0;
    int size = 0;
    struct Node* curr = head;
    while (curr) {
        size++;
        curr = curr->next;
    }
    return size;
}

bool checkListsEqual(struct Node* head1, struct Node* head2) {
    struct Node* curr1 = head1;
    struct Node* curr2 = head2;

    while (curr1 && curr2) {
        if (curr1->val != curr2->val) return false;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return (!curr1 && !curr2);
}

struct Node* appendTwoLists(struct Node* head1, struct Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    struct Node* curr = head1;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = head2;
    return head1;
}

struct Node* searchUnordered(struct Node* head, int key) {
    struct Node* curr = head;
    struct Node* prev = NULL;

    while (curr) {
        if (curr->val == key) {
            if (prev) {
                prev->next = curr->next;
            } else {
                head = curr->next; 
            }
            curr->next = NULL; 
            return curr;
        }
        prev = curr;
        curr = curr->next;
    }
    return NULL; 
}


struct Node* searchOrdered(struct Node* head, int key) {
    struct Node* curr = head;
    struct Node* prev = NULL;

    while (curr && curr->val <= key) {
        if (curr->val == key) {
            if (prev) {
                prev->next = curr->next;
            } else {
                head = curr->next; 
            }
            curr->next = NULL; 
            return curr;
        }
        prev = curr;
        curr = curr->next;
    }
    return NULL; 
}

struct Node* deleteNode(struct Node* head, int pos) {
    if (pos == 1) {
        delete_front(&head);
        return head;
    }
    if (pos > findSize(head)) return head;
    int i = 1;
    struct Node* curr = head;
    while (i < pos - 1 && curr) {
        i++;
        curr = curr->next;
    }
    delete_after(curr);
    return head;
}

bool isSorted(struct Node* head) {
    if (!head) return true;
    struct Node* curr = head;
    while (curr->next) {
        if (curr->val > curr->next->val) {
            return false;
        }
        curr = curr->next;
    }
    return true;
}

struct Node* mergeList(struct Node* head1, struct Node* head2) {
    struct Node* curr1 = head1;
    struct Node* curr2 = head2;
    struct Node* dummy = createNode(-1);
    struct Node* ptr = dummy;

    while (curr1 && curr2) {
        if (curr1->val <= curr2->val) {
            ptr->next = curr1;
            curr1 = curr1->next;
        } else {
            ptr->next = curr2;
            curr2 = curr2->next;
        }
        ptr = ptr->next;
        ptr->next = NULL;
    }
    ptr->next = curr1 ? curr1 : curr2;

    struct Node* result = dummy->next;
    free(dummy);
    return result;
}

struct Node* removeDuplicatesUnsorted(struct Node* head) {
    if (!head) return NULL;
    struct Node* curr = head;

    while (curr) {
        struct Node* runner = curr;
        while (runner->next) {
            if (runner->next->val == curr->val) {
                delete_after(runner);
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

struct Node* removeDuplicatesSorted(struct Node* head) {
    if (!head) return NULL;
    struct Node* curr = head;

    while (curr->next) {
        if (curr->val == curr->next->val) {
            delete_after(curr);
        } else {
            curr = curr->next;
        }
    }
    return head;
}

struct Node* insertBefore(struct Node* head, struct Node* target, struct Node* before) {
    if (!target || !head || !before) return head;
    if (head == before) {
        insert_front(target, &head);
        return head;
    }

    struct Node* curr = head;
    while (curr->next && curr->next != before) {
        curr = curr->next;
    }
    if (curr->next == before) {
        insert_after(target, curr);
    }
    return head;
}

struct Node* insertEnd(struct Node* head, struct Node* target) {
    if (!target) return head;
    if (!head) return target;

    struct Node* curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    insert_after(target, curr);
    return head;
}

void swapElementsbyPairs(struct Node* head) {
    if (!head) return;
    struct Node* curr = head;

    while (curr && curr->next) {
        int t = curr->val;
        curr->val = curr->next->val;
        curr->next->val = t;
        curr = curr->next->next;
    }
}

struct Node* moveLasttoFirst(struct Node* head) {
    if (!head || !head->next) return head;
    struct Node* secondLast = head;
    struct Node* last = head->next;

    while (last->next) {
        secondLast = last;
        last = last->next;
    }
    secondLast->next = NULL;
    last->next = head;
    return last;
}

struct Node* rotateList(struct Node* head, int rot) {
    if (!head) return NULL;
    if(rot < 0) return head;
    for (int i = 0; i < rot; i++) {
        head = moveLasttoFirst(head);
    }
    return head;
}

struct Node* deleteAlternateNodes(struct Node* head) {
    if (!head) return NULL;
    struct Node* curr = head;

    while (curr && curr->next) {
        delete_after(curr);
        curr = curr->next;
    }
    return head;
}

void deleteList(struct Node* head) {
    while (head) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;

    while (curr) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void sort(struct Node* head) {
    if (!head) return;

    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->val > ptr1->next->val) {
                int t = ptr1->val;
                ptr1->val = ptr1->next->val;
                ptr1->next->val = t;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}