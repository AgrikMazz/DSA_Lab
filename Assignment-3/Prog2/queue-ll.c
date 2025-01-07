#include "linkedlist.h"

typedef struct{
    struct Node* front; 
    struct Node* rear;  
} Queue;

// Initialize a new queue
Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = init_l(q->front);
    q->rear = init_l(q->rear);
    return q;
}

// Check if the queue is empty
bool isEmpty(Queue* q){
    return empty_l(q->front);
}

// Enqueue an element into the queue
void enqueue(Queue* q, int x){
    struct Node* newNode = createNode(x);
    if (isEmpty(q)) {
        q->front = q->rear = newNode; 
    } else {
        insert_after(newNode, q->rear); 
        q->rear = newNode;             
    }
}

// Dequeue an element from the queue
void dequeue(Queue* q){
    if (isEmpty(q)) {
        printf("Cannot dequeue from an empty queue\n");
        return;
    }
    delete_front(&q->front); 
    if (q->front == NULL) {  
        q->rear = NULL;
    }
}

// Peek at the front element of the queue
int peek(Queue* q){
    if (isEmpty(q)) {
        printf("Queue is empty: No front element to peek\n");
        return -1;
    }
    return q->front->val;
}

// Display the elements in the queue
void displayQueue(Queue* q){
    if (isEmpty(q)) {
        printf("Empty queue\n");
        return;
    }
    printf("Elements of queue:\n");
    struct Node* curr = q->front;
    while (curr) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n-------------\n");
}

int main(){
    int choice, value;
    Queue* q = createQueue();

    do {
        printf("\nQueue Menu:");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                value = peek(q);
                if (value != -1) {
                    printf("\nFront element is: %d\n", value);
                }
                break;
            case 4:
                displayQueue(q);
                break;
            case 5:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}