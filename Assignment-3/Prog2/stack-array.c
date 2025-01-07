#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

//Stack struct
typedef struct{
    int top;
    int *array;
} Stack ;

//Initialize an empty stack
Stack* createStack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->array = (int*)malloc(sizeof(MAX_SIZE * sizeof(int)));
}
//Check is stack is empty
int isEmpty(Stack* s){
    return s->top == -1 ? 1: 0;
}
//Check is stack is full
int isFull(Stack* s){
    return s->top == (MAX_SIZE - 1) ? 1: 0;
}
// Push on top of stack
void push(Stack* s, int n){
    if(isFull(s) == 1){
        printf("Error. Overflow\n");
        return;
    }
    s->top += 1;
    s->array[s->top] = n;
}
//Pops element from top of stack
void pop(Stack* s){
    if(isEmpty(s) == 1){
        printf("Error. Underflow\n");
        return ;
    }
    s->top--;
}
//Return top of stack
int peek(Stack* s){
    if(isEmpty(s) == 1){
        printf("Error. Underflow\n");
        return -1;
    }
    return s->array[s->top];
}
//Display all elements of stack
void display(Stack* s){
    if(isEmpty(s) == 1){
        printf("Error. Underflow\n");
        return;
    }
    int top = s->top;
    printf("Displaying all elements.\n");
    for(int i = top--; i>=0; i--){
        printf("%d\n",s->array[i]);
    }
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