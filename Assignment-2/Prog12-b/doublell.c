#include "doublell.h"

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

bool atend_l(struct Node* curr) {
    return curr && curr->next == NULL;
}

void insert_front(struct Node* target, struct Node** head) {
    if (!target) return;
    target->next = *head;
    if (*head) (*head)->prev = target;
    *head = target;
}

void insert_after(struct Node* target, struct Node* prev) {
    if (!prev || !target) return;
    target->next = prev->next;
    target->prev = prev;
    if (prev->next) prev->next->prev = target;
    prev->next = target;
}

void delete_front(struct Node** head) {
    if (!*head) return;
    struct Node* temp = (*head)->next;
    if (temp) temp->prev = NULL;
    free(*head);
    *head = temp;
}

void delete_after(struct Node* prev) {
    if (!prev || !prev->next) return;
    struct Node* temp = prev->next;
    prev->next = temp->next;
    if (temp->next) temp->next->prev = prev;
    free(temp);
}
