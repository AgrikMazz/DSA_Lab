#include "circdllfunc.h"

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
    if (!head) return;
    printf("Elements of list in same order:\n");
    struct Node* curr = head;
    do {
        printf("%d ", curr->val);
        curr = curr->next;
    } while (curr != head);
    printf("\n");
}

int findSize(struct Node* head) {
    if (!head) return 0;
    int size = 0;
    struct Node* curr = head;
    do {
        size++;
        curr = curr->next;
    } while (curr != head);
    return size;
}

bool checkListsEqual(struct Node* head1, struct Node* head2) {
    if (!head1 || !head2) return head1 == head2;
    struct Node* curr1 = head1;
    struct Node* curr2 = head2;
    do {
        if (curr1->val != curr2->val) return false;
        curr1 = curr1->next;
        curr2 = curr2->next;
    } while (curr1 != head1 && curr2 != head2);
    return curr1 == head1 && curr2 == head2;
}

struct Node* appendTwoLists(struct Node* head1, struct Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;
    struct Node* tail1 = head1->prev;
    struct Node* tail2 = head2->prev;
    tail1->next = head2;
    head2->prev = tail1;
    tail2->next = head1;
    head1->prev = tail2;
    return head1;
}

struct Node* searchUnordered(struct Node* head, int key) {
    if (!head) return NULL;
    struct Node* curr = head;
    do {
        if (curr->val == key) return curr;
        curr = curr->next;
    } while (curr != head);
    return NULL;
}

struct Node* searchOrdered(struct Node* head, int key) {
    if (!head) return NULL;
    struct Node* curr = head;
    do {
        if (curr->val >= key) {
            if (curr->val == key) return curr;
            return NULL;
        }
        curr = curr->next;
    } while (curr != head);
    return NULL;
}

struct Node* deleteNode(struct Node* head, int pos) {
    if (!head || pos < 1) return head;
    struct Node* curr = head;
    for (int i = 1; i < pos; i++) {
        curr = curr->next;
        if (curr == head) return head;
    }
    if (curr == head) {
        delete_front(&head);
    } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
    }
    return head;
}

bool isSorted(struct Node* head) {
    if (!head) return true;
    struct Node* curr = head;
    do {
        if (curr->next != head && curr->val > curr->next->val) return false;
        curr = curr->next;
    } while (curr != head);
    return true;
}

struct Node* mergeList(struct Node* head1, struct Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;
    struct Node* dummy = createNode(-1);
    struct Node* tail = dummy;
    struct Node* curr1 = head1;
    struct Node* curr2 = head2;
    do {
        if (curr1->val <= curr2->val) {
            tail->next = curr1;
            curr1->prev = tail;
            curr1 = curr1->next;
        } else {
            tail->next = curr2;
            curr2->prev = tail;
            curr2 = curr2->next;
        }
        tail = tail->next;
    } while (curr1 != head1 && curr2 != head2);
    tail->next = (curr1 == head1) ? curr2 : curr1;
    tail->next->prev = tail;
    dummy->prev = tail;
    struct Node* result = dummy->next;
    result->prev = dummy->prev;
    free(dummy);
    return result;
}

struct Node* removeDuplicatesUnsorted(struct Node* head) {
    if (!head) return NULL;
    struct Node* curr = head;
    do {
        struct Node* runner = curr->next;
        while (runner != head) {
            if (runner->val == curr->val) {
                struct Node* temp = runner->next;
                runner->prev->next = runner->next;
                runner->next->prev = runner->prev;
                free(runner);
                runner = temp;
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    } while (curr != head);
    return head;
}

struct Node* removeDuplicatesSorted(struct Node* head) {
    if (!head) return NULL;
    struct Node* curr = head;
    do {
        if (curr->next != head && curr->val == curr->next->val) {
            struct Node* temp = curr->next;
            curr->next = temp->next;
            temp->next->prev = curr;
            free(temp);
        } else {
            curr = curr->next;
        }
    } while (curr->next != head);
    return head;
}

struct Node* insertBefore(struct Node* head, struct Node* target, struct Node* before) {
    if (!target || !before) return head;
    struct Node* curr = head;
    do {
        if (curr->next == before) {
            insert_after(target, curr);
            break;
        }
        curr = curr->next;
    } while (curr != head);
    return head;
}

struct Node* insertEnd(struct Node* head, struct Node* target) {
    if (!target) return head;
    if (!head) {
        target->next = target;
        target->prev = target;
        return target;
    }
    struct Node* tail = head->prev;
    tail->next = target;
    target->prev = tail;
    target->next = head;
    head->prev = target;
    return head;
}

void swapElementsbyPairs(struct Node* head) {
    if (!head) return;
    struct Node* curr = head;
    do {
        if (curr->next != head) {
            int temp = curr->val;
            curr->val = curr->next->val;
            curr->next->val = temp;
            curr = curr->next->next;
        } else {
            break;
        }
    } while (curr != head);
}

struct Node* moveLasttoFirst(struct Node* head) {
    if (!head || head->next == head) return head;
    struct Node* last = head->prev;
    last->prev->next = head;
    head->prev = last->prev;
    last->next = head;
    head->prev = last;
    return last;
}

struct Node* rotateList(struct Node* head, int rot) {
    if(!head || rot < 0) return head;
    for (int i = 0; i < rot; i++) {
        head = moveLasttoFirst(head);
    }
    return head;
}

struct Node* deleteAlternateNodes(struct Node* head) {
    if (!head) return NULL;
    struct Node* curr = head;
    do {
        if (curr->next != head) {
            struct Node* temp = curr->next;
            curr->next = temp->next;
            temp->next->prev = curr;
            free(temp);
            curr = curr->next;
        } else {
            break;
        }
    } while (curr != head);
    return head;
}

void deleteList(struct Node* head) {
    if (!head) return;
    struct Node* curr = head;
    do {
        struct Node* temp = curr->next;
        free(curr);
        curr = temp;
    } while (curr != head);
}

struct Node* reverseList(struct Node* head) {
    if (!head) return NULL;
    struct Node* curr = head;
    struct Node* temp = NULL;
    do {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    } while (curr != head);
    return temp->prev;
}

void sort(struct Node* head) {
    if (!head) return;
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        do {
            if (ptr1->val > ptr1->next->val) {
                int t = ptr1->val;
                ptr1->val = ptr1->next->val;
                ptr1->next->val = t;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        } while (ptr1->next != lptr && ptr1 != head);
        lptr = ptr1;
    } while (swapped);
}