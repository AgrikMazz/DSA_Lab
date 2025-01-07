#include "linkedlist.h"

struct Node* init_l(struct Node* curr){
    curr = NULL;
    return curr;
}

struct Node* createNode(int x){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = x;
    node->next = NULL;
    return node;
}

bool empty_l(struct Node* head){
    return (head == NULL) ? true : false;
}

bool atend_l(struct Node* curr){
    if(!curr) return false;
    return (curr->next == NULL) ? true : false;
}

void insert_front(struct Node* target,struct Node** head){
    if(!target) return;
    target->next = *head;
    *head = target;
}

void insert_after(struct Node* target,struct Node* prev){
    if (!prev || !target) return; 
    target->next = prev->next;
    prev->next = target;
}

void delete_front(struct Node** head){
    if(!(*head)) return;
    struct Node* temp = (*head)->next;
    (*head)->next = NULL;
    *head = temp;
}

void delete_after(struct Node* prev){
    if (!prev || !prev->next) return; 
    struct Node* temp = prev->next;
    prev->next = temp->next;
    free(temp);
}
