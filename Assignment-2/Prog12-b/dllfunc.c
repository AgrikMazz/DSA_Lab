#include "dllfunc.h"

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
    curr->next = head;
    return head;
}

struct Node* BuildList_Reverse(int size) {
    struct Node* head = init_l(head);
    int x;
    
    for(int i = 1; i <= size; i++){
        printf("Enter value of node-%d: ", i);
        scanf("%d", &x);
        insert_front(createNode(x),&head);    
    }

    return head;
}

void Print_list(struct Node* head) {
    printf("Elements of list in same order:\n");
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int findSize(struct Node* head) {
    int size = 0;
    while (head) {
        size++;
        head = head->next;
    }
    return size;
}

bool checkListsEqual(struct Node* head1, struct Node* head2) {
    while (head1 && head2) {
        if (head1->val != head2->val) return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return !head1 && !head2;
}

struct Node* appendTwoLists(struct Node* head1, struct Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;
    struct Node* tail = head1;
    while (tail->next) tail = tail->next;
    tail->next = head2;
    head2->prev = tail;
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
    struct Node* curr = head;
    for (int i = 1; curr && i < pos; i++) curr = curr->next;
    if (curr) {
        if (curr->prev) curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
        free(curr);
    }
    return head;
}

bool isSorted(struct Node* head) {
    while (head && head->next) {
        if (head->val > head->next->val) return false;
        head = head->next;
    }
    return true;
}

struct Node* mergeList(struct Node* head1, struct Node* head2) {
    struct Node* dummy = createNode(-1);
    struct Node* tail = dummy;

    while (head1 && head2) {
        if (head1->val <= head2->val) {
            tail->next = head1;
            head1->prev = tail;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2->prev = tail;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    tail->next = head1 ? head1 : head2;
    if (tail->next) tail->next->prev = tail;

    struct Node* result = dummy->next;
    if (result) result->prev = NULL;
    free(dummy);
    return result;
}

struct Node* removeDuplicatesUnsorted(struct Node* head) {
    struct Node* curr = head;
    while (curr) {
        struct Node* runner = curr->next;
        while (runner) {
            if (runner->val == curr->val) {
                struct Node* temp = runner->next;
                if (runner->prev) runner->prev->next = runner->next;
                if (runner->next) runner->next->prev = runner->prev;
                free(runner);
                runner = temp;
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

struct Node* removeDuplicatesSorted(struct Node* head) {
    struct Node* curr = head;
    while (curr && curr->next) {
        if (curr->val == curr->next->val) {
            struct Node* temp = curr->next;
            curr->next = temp->next;
            if (temp->next) temp->next->prev = curr;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
    return head;
}

struct Node* insertBefore(struct Node* head, struct Node* target, struct Node* before) {
    if (!target || !before) return head;
    if (head == before) {
        insert_front(target, &head);
        return head;
    }
    struct Node* curr = head;
    while (curr && curr->next != before) curr = curr->next;
    if (curr->next == before) insert_after(target, curr);
    return head;
}

struct Node* insertEnd(struct Node* head, struct Node* target) {
    if (!target) return head;
    if (!head) return target;
    struct Node* tail = head;
    while (tail->next) tail = tail->next;
    insert_after(target, tail);
    return head;
}

void swapElementsbyPairs(struct Node* head) {
    struct Node* curr = head;
    while (curr && curr->next) {
        int temp = curr->val;
        curr->val = curr->next->val;
        curr->next->val = temp;
        curr = curr->next->next;
    }
}

struct Node* moveLasttoFirst(struct Node* head) {
    if (!head || !head->next) return head;
    struct Node* last = head;
    while (last->next) last = last->next; 

    if (last->prev) last->prev->next = NULL;
    last->prev = NULL;
    last->next = head;
    head->prev = last;
    return last;
}

struct Node* rotateList(struct Node* head, int rot) {
    if(!head || rot < 0) return head;
    for(int i=0; i<rot; i++){
        head = moveLasttoFirst(head);
    }
    return head;
}

struct Node* deleteAlternateNodes(struct Node* head) {
    struct Node* curr = head;
    while (curr && curr->next) {
        struct Node* temp = curr->next;
        curr->next = temp->next;
        if (temp->next) temp->next->prev = curr;
        free(temp);
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
    struct Node* curr = head;
    struct Node* temp = NULL;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    return temp ? temp->prev : head;
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
