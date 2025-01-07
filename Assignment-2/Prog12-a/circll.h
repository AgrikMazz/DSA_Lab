#ifndef CIRCLL_H
#define CIRCLL_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int val;
    struct Node* next;
};

struct Node* init_l(struct Node* curr);
struct Node* createNode(int x);
bool empty_l(struct Node* head);
bool atend_l(struct Node* curr);
void insert_front(struct Node* target,struct Node** head);
void insert_after(struct Node* target,struct Node* prev);
void delete_front(struct Node** head);
void delete_after(struct Node* prev);

#endif