#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};


struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; 
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}


int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}


int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue. It changes rear and size
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}


int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return INT_MIN;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return queue->array[queue->front];
}

int rear(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return queue->array[queue->rear];
}

void printQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for (i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity) {
        printf("%d ", queue->array[i]);
    }
    printf("%d\n", queue->array[i]);
}

int main() {
    struct Queue* queue = createQueue(MAX);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n", dequeue(queue));

    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    printf("Elements present in queue: ");
    printQueue(queue);

    return 0;
}
