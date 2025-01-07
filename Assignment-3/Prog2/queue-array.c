#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

// Initialize a new queue
Queue* createQueue(int n){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int*)malloc(n * sizeof(int));
    q->size = n;
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Queue* q){
    return (q->front == (q->rear + 1) % q->size);
}

// Check if the queue is empty
int emptyQueue(Queue* q){
    return q->front == -1;
}

// Enqueue an element into the queue
void enqueue(Queue* q,int x){
    int n = q->size;
    if(isFull(q)) return;
    if(emptyQueue(q)){
        q->rear = 0;
        q->front = 0;
    }
    else{
        q->rear = (q->rear + 1) % n;
    }
    q->arr[q->rear] = x;
}

// Dequeue an element from the queue
void dequeue(Queue* q){
    int n = q->size;
    if (emptyQueue(q)){
        printf("\nQueue is Empty");
        return;
    }
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }
    else{
        q->front = (q->front + 1) % n;
    }
}

// Peek at the front element of the queue
int peek(Queue* q) {
    if (emptyQueue(q)) {
        printf("Queue is empty: No front element to peek\n");
        return -1;
    }
    return q->arr[q->front];
}

void displayQueue(Queue* q){
    if (emptyQueue(q)){
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Queue are: ");

    if (q->rear >= q->front){
        for (int i = q->front; i <= q->rear; i++)
            printf("%d ",q->arr[i]);
    }
    
    else{
        for (int i = q->front; i < q->size; i++)
            printf("%d ", q->arr[i]);
 
        for (int i = 0; i <= q->rear; i++)
            printf("%d ", q->arr[i]);
    }
}

int main() {
    int size, choice, value;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    Queue* q = createQueue(size);

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
