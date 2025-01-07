#include "circdll.h"

struct Node* init_l(struct Node* curr) {
    curr = NULL;
    return curr;
}

struct Node* createNode(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = x;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

bool empty_l(struct Node* head) {
    return head == NULL;
}

bool atend_l(struct Node* head, struct Node* curr) {
    return curr && curr->next == head;
}

void insert_front(struct Node* target, struct Node** head) {
    if (!target) return;

    if (!*head) {
        target->next = target;
        target->prev = target;
        *head = target;
    } else {
        struct Node* tail = (*head)->prev;
        target->next = *head;
        target->prev = tail;
        tail->next = target;
        (*head)->prev = target;
        *head = target;
    }
}

void insert_after(struct Node* target, struct Node* prev) {
    if (!prev || !target) return;

    if (!prev->next) { 
        target->next = target;
        target->prev = target;
        prev->next = target;
        prev->prev = target;
    } else {
        target->next = prev->next;
        target->prev = prev;
        if (prev->next) {
            prev->next->prev = target;
        }
        prev->next = target;
    }
}

void delete_front(struct Node** head) {
    if (!*head) return;

    struct Node* temp = *head;
    if (temp->next == temp) {
        free(temp);
        *head = NULL;
    } else {
        struct Node* tail = temp->prev;
        *head = temp->next;
        (*head)->prev = tail;
        tail->next = *head;
        free(temp);
    }
}

void delete_after(struct Node* prev) {
    if (!prev || !prev->next || prev->next == prev) return;

    struct Node* temp = prev->next;
    prev->next = temp->next;
    if (temp->next) {
        temp->next->prev = prev;
    }
    free(temp);
}