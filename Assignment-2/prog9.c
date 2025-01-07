#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node* next;
};

struct Node* createNode(int x){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = x;
    node->next = NULL;
    return node;
}

struct Node* Build_List(const char* filename, struct Node* head){
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return NULL;
    }
    struct Node* current = head;
    int num;
    while(fscanf(fp,"%d",&num) != EOF){
        struct Node* node = createNode(num);
        if(current == NULL){
            current = node;
            head = current;
        }
        else{
            current->next = node;
            current = current->next;
        }   
    }
    fclose(fp);
    return head;
}

struct Node* Build_List_reverse(const char* filename, struct Node* head){
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return NULL;
    }
    int num;
    while(fscanf(fp,"%d",&num) != EOF){
        struct Node* node = createNode(num);
        node->next = head;
        head = node;
    }
    fclose(fp);
    return head;
}

void Print_List(struct Node* head){
    if(head == NULL){
        printf("Empty list\n");
    }
    struct Node* current = head;
    while(current){
        printf("%d ",current->val);
        current = current->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    head = Build_List("numbers.txt",head);
    printf("List in order:-\n");
    Print_List(head);

    struct Node* headRev = NULL;
    headRev = Build_List_reverse("numbers.txt",headRev);
    printf("List in reverse order:-\n");
    Print_List(headRev);

    return 0;
}