#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Stack operations
void push(Stack* stack, char item) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow.\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

void pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow.\n");
        exit(1);
    }
    stack->top--;
}

char peek(Stack* stack) {
    return stack->items[stack->top];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Utility functions
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Conversion function
void infixToPostfix(const char* infix, char* postfix){
    Stack stk;
    stk.top = -1;
    int i = 0, j = 0;
    
    while (infix[i] != '#' && infix[i] != '\0'){
        char ch = infix[i];
        
        if (isalnum(ch)){
            postfix[j++] = ch; // Append operands directly to postfix
        } 
        else if (ch == '('){
            push(&stk, ch); // Push '(' onto stack
        } 
        else if (ch == ')'){
            // Pop until '(' is found
            while (!isEmpty(&stk) && peek(&stk) != '(') {
                postfix[j++] = peek(&stk);
                pop(&stk);
            }
            pop(&stk); // Remove '(' from stack
        } 
        else if (isOperator(ch)){
            // Pop operators of higher or equal precedence
            while (!isEmpty(&stk) && precedence(peek(&stk)) >= precedence(ch)) {
                postfix[j++] = peek(&stk);
                pop(&stk);
            }
            push(&stk, ch); // Push current operator
        }
        else if(ch == ' '){
            i++;
            continue;
        }
        else{
            printf("Invalid character encountered: %c\n", ch);
            exit(1);
        }
        i++;
    }
    
    // Pop remaining operators in stack
    while (!isEmpty(&stk)){
        postfix[j++] = peek(&stk);
        pop(&stk);
    }
    
    postfix[j] = '#'; // Append sentinel
    postfix[j + 1] = '\0'; // Null-terminate the string
}

// Main function
int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    
    printf("Enter the infix expression (terminated with #): ");
    scanf("%[^\n]s",infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    return 0;
}