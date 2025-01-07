#include "linkedlist.h"

typedef struct{
    struct Node* head;
} Stack;

Stack* createStack(){
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->head = init_l(stk->head);
    return stk;
}

bool isEmpty(Stack* stk){
    return empty_l(stk->head);
}

void push(Stack* stk, int x){
    insert_front(createNode(x),&stk->head);
}

void pop(Stack* stk){
    delete_front(&stk->head);
}

void display(Stack* stk){
    if(isEmpty(stk)){
        printf("Empty stack\n");
        return;
    }
    printf("Elements of stack:\n");
    struct Node* curr = stk->head;
    while(curr){
        printf("%d\n",curr->val);
        curr = curr->next;
    }
    printf("-------------\n");
}

int peek(Stack* stk){
    if(isEmpty(stk)){
        printf("Empty stack\n");
        return -1;
    }
    return stk->head->val;
}

int main() {
    Stack* s = createStack();
    int choice, value;

    do {
        printf("\n Stack Menu \n");
        printf("1. Push element\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display all elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(s, value);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                value = peek(s);
                if (value != -1) {
                    printf("Top element is: %d\n", value);
                }
                break;
            case 4:
                display(s);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
