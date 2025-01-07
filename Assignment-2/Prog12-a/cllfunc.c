#include "cllfunc.h"

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
    return (curr1 == head1 && curr2 == head2);
}

struct Node* appendTwoLists(struct Node* head1, struct Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;
    struct Node* last1 = head1;
    while (last1->next != head1) last1 = last1->next;
    struct Node* last2 = head2;
    while (last2->next != head2) last2 = last2->next;
    last1->next = head2;
    last2->next = head1;
    return head1;
}

struct Node* searchUnordered(struct Node* head, int key) {
    if (!head) return NULL;
    struct Node* curr = head;
    struct Node* prev = NULL;
    do {
        if (curr->val == key) {
            if (prev) prev->next = curr->next;
            else {
                struct Node* last = head;
                while (last->next != head) last = last->next;
                last->next = curr->next;
                head = curr->next;
            }
            curr->next = NULL;
            return curr;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    return NULL;
}

struct Node* searchOrdered(struct Node* head, int key) {
    if (!head) return NULL;
    struct Node* curr = head;
    struct Node* prev = NULL;
    do {
        if (curr->val >= key) {
            if (curr->val == key) {
                if (prev) prev->next = curr->next;
                else {
                    struct Node* last = head;
                    while (last->next != head) last = last->next;
                    last->next = curr->next;
                    head = curr->next;
                }
                curr->next = NULL;
                return curr;
            }
            return NULL;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    return NULL;
}

struct Node* deleteNode(struct Node* head, int pos) {
    if (pos < 1 || !head) return head;
    if (pos == 1) {
        struct Node* last = head;
        while (last->next != head) last = last->next;
        struct Node* temp = head;
        if (head == last) head = NULL;
        else {
            last->next = head->next;
            head = head->next;
        }
        free(temp);
        return head;
    }
    struct Node* curr = head;
    for (int i = 1; i < pos - 1 && curr->next != head; i++) curr = curr->next;
    if (curr->next != head) delete_after(curr);
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
    struct Node* curr1 = head1;
    struct Node* curr2 = head2;
    struct Node* dummy = createNode(-1);
    struct Node* ptr = dummy;
    do {
        if (curr1->val <= curr2->val) {
            ptr->next = curr1;
            curr1 = curr1->next;
        } else {
            ptr->next = curr2;
            curr2 = curr2->next;
        }
        ptr = ptr->next;
    } while (curr1 != head1 && curr2 != head2);
    ptr->next = (curr1 == head1) ? curr2 : curr1;
    while (ptr->next != head1 && ptr->next != head2) ptr = ptr->next;
    ptr->next = dummy->next;
    struct Node* result = dummy->next;
    free(dummy);
    return result;
}

struct Node* removeDuplicatesUnsorted(struct Node* head) {
    if (!head) return NULL;
    struct Node* curr = head;
    do {
        struct Node* runner = curr;
        while (runner->next != head) {
            if (runner->next->val == curr->val) {
                struct Node* temp = runner->next;
                runner->next = temp->next;
                free(temp);
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
            free(temp);
        } else {
            curr = curr->next;
        }
    } while (curr->next != head);
    return head;
}

struct Node* insertBefore(struct Node* head, struct Node* target, struct Node* before) {
    if (!target || !head) return head;
    if (head == before) {
        insert_front(target, &head);
        return head;
    }
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
        return target;
    }
    struct Node* curr = head;
    while (curr->next != head) curr = curr->next;
    insert_after(target, curr);
    return head;
}

void swapElementsbyPairs(struct Node* head) {
    if (!head) return;
    struct Node* curr = head;
    do {
        if (curr->next != head) {
            int t = curr->val;
            curr->val = curr->next->val;
            curr->next->val = t;
            curr = curr->next->next;
        } else {
            break;
        }
    } while (curr != head);
}

struct Node* moveLasttoFirst(struct Node* head) {
    if (!head || head->next == head) return head;
    struct Node* secondLast = head;
    struct Node* last = head->next;
    while (last->next != head) {
        secondLast = last;
        last = last->next;
    }
    secondLast->next = head;
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
    do {
        if (curr->next != head) {
            struct Node* temp = curr->next;
            curr->next = temp->next;
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
    struct Node* nextNode;
    do {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    } while (curr != head);
}

struct Node* reverseList(struct Node* head) {
    if (!head) return NULL;
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next;
    struct Node* last = head;
    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);
    last->next = prev;
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
        do {
            if (ptr1->next != head && ptr1->val > ptr1->next->val) {
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