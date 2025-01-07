#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct Node{
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} Number;

Node* createNode(int digit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = digit;
    newNode->next = NULL;
    return newNode;
}

Number createNumber(int n) {
    Number num;
    num.head = NULL;
    num.size = n;

    Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        int random_digit = rand() % 10;
        if(i == 0 && random_digit == 0){
            random_digit = (rand() % 9) + 1; // Ensure non-zero digit
        }

        Node* newNode = createNode(random_digit);
        if (num.head == NULL) {
            num.head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    return num;
}

int compare(Number num1, Number num2) {
    if (num1.size > num2.size) {
        return 1;
    } else if (num1.size < num2.size) {
        return -1;
    }

    Node* ptr1 = num1.head;
    Node* ptr2 = num2.head;
    while (ptr1 != NULL) {
        if (ptr1->val > ptr2->val) {
            return 1;
        } else if (ptr1->val < ptr2->val) {
            return -1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return 0; 
}

void reverseList(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

Number addNumbers(Number num1, Number num2) {
    reverseList(&num1.head);
    reverseList(&num2.head);

    Node* ptr1 = num1.head;
    Node* ptr2 = num2.head;

    Number result;
    result.head = NULL;
    result.size = 0;

    int carry = 0;
    while (ptr1 != NULL || ptr2 != NULL || carry > 0) {
        int digit1 = (ptr1 != NULL) ? ptr1->val : 0;
        int digit2 = (ptr2 != NULL) ? ptr2->val : 0;

        int sum = (digit1 + digit2 + carry) % 10;
        carry = (digit1 + digit2 + carry) / 10;

        Node* newNode = createNode(sum);
        newNode->next = result.head;
        result.head = newNode;

        if (ptr1 != NULL) ptr1 = ptr1->next;
        if (ptr2 != NULL) ptr2 = ptr2->next;
        result.size++;
    }

    reverseList(&num1.head);
    reverseList(&num2.head);

    return result;
}

Number subtractNumbers(Number num1, Number num2) {
    reverseList(&num1.head);
    reverseList(&num2.head);

    Node* ptr1 = num1.head;
    Node* ptr2 = num2.head;

    Number result;
    result.head = NULL;
    result.size = 0;

    int borrow = 0;
    while (ptr1 != NULL || ptr2 != NULL) {
        int digit1 = (ptr1 != NULL) ? ptr1->val : 0;
        int digit2 = (ptr2 != NULL) ? ptr2->val : 0;

        digit1 -= borrow;
        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        Node* newNode = createNode(digit1 - digit2);
        newNode->next = result.head;
        result.head = newNode;

        if (ptr1 != NULL) ptr1 = ptr1->next;
        if (ptr2 != NULL) ptr2 = ptr2->next;
        result.size++;
    }

    while (result.head != NULL && result.head->val == 0) {
        Node* temp = result.head;
        result.head = result.head->next;
        free(temp);
        result.size--;
    }

    reverseList(&num1.head);
    reverseList(&num2.head);

    return result;
}

Number multiplyNumbers(Number num1, Number num2) {
    reverseList(&num1.head);
    reverseList(&num2.head);

    Node* ptr1 = num1.head;
    Node* ptr2 = num2.head;

    Number result;
    result.head = NULL;
    result.size = 0;

    int position = 0; 

    while (ptr1 != NULL) {
        Number tempResult;
        tempResult.head = NULL;
        tempResult.size = 0;

        for (int i = 0; i < position; i++) {
            Node* zeroNode = createNode(0);
            zeroNode->next = tempResult.head;
            tempResult.head = zeroNode;
            tempResult.size++;
        }

        Node* ptr2 = num2.head;
        int carry = 0;

        while (ptr2 != NULL || carry > 0) {
            int prod = (ptr1->val * (ptr2 != NULL ? ptr2->val : 0)) + carry;
            carry = prod / 10;

            Node* newNode = createNode(prod % 10);
            newNode->next = tempResult.head;
            tempResult.head = newNode;
            tempResult.size++;

            if (ptr2 != NULL) ptr2 = ptr2->next;
        }

        result = addNumbers(result, tempResult);

        ptr1 = ptr1->next;
        position++;
    }
   
    reverseList(&num1.head);
    reverseList(&num2.head);

    return result;
}


void printNumber(Number num) {
    Node* curr = num.head;
    while (curr != NULL) {
        printf("%d", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int n1, n2;
    printf("Enter number of digits in first number: ");
    scanf("%d", &n1);
    printf("Enter number of digits in second number: ");
    scanf("%d", &n2);

    Number num1 = createNumber(n1);
    Number num2 = createNumber(n2);

    Number add = addNumbers(num1, num2);
    Number sub;
    if (compare(num1, num2) >= 0) {
        sub = subtractNumbers(num1, num2);
    } else {
        sub = subtractNumbers(num2, num1);
    }
    Number mul = multiplyNumbers(num1, num2);

    printf("First number: ");
    printNumber(num1);

    printf("Second number: ");
    printNumber(num2);

    printf("Sum: ");
    printNumber(add);

    printf("Difference: ");
    printNumber(sub);

    printf("Product: ");
    printNumber(mul);

    return 0;
}