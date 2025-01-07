#include "circll.h"

struct Node* init_l(struct Node* curr) {
    curr = NULL;
    return curr;
}

struct Node* createNode(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = x;
    node->next = NULL;
    return node;
}

bool empty_l(struct Node* head) {
    return (head == NULL);
}

bool atend_l(struct Node* head, struct Node* curr) {
    return curr && curr->next == head;
}

void insert_front(struct Node* target, struct Node** head) {
    if (!target) return;
    if (*head == NULL) {
        target->next = target; 
        *head = target;
    } 
    else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next; 
        }
        target->next = *head;
        temp->next = target; 
        *head = target;
    }
}

void insert_after(struct Node* target, struct Node* prev) {
    if (!prev || !target) return;
    target->next = prev->next;
    prev->next = target;
}

void delete_front(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    if (temp->next == *head) {
        
        free(temp);
        *head = NULL;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next; 
        }
        last->next = (*head)->next;
        *head = (*head)->next;
        free(temp);
    }
}

void delete_after(struct Node* prev) {
    if (!prev || !prev->next) return;
    struct Node* temp = prev->next;
    if (temp == prev) {
        
        free(temp);
        prev->next = NULL;
    } else {
        prev->next = temp->next;
        free(temp);
    }
}
