#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* array;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Khong the cap phat bo nho dong!");
        return NULL;
    }
    queue->array = (int*)malloc(size * sizeof(int));
    if (queue->array == NULL) {
        printf("Khong the cap phat bo nho dong!");
        return NULL;
    }
    queue->front = 0;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

int main(void) {
    int size = 5;
    Queue* queue = createQueue(size);
    return 0;
}