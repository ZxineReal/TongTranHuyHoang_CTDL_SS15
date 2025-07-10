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

int isEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

int isFull(Queue* queue) {
    return queue->rear == queue->size - 1;
}

void enQueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Hang doi da day!");
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
    printf("Them phan tu %d thanh cong!\n", value);
}

int deQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong!");
        return -1;
    }
    int value = queue->array[queue->front];
    queue->front++;
    return value;
}

void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong!");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main(void) {
    int size = 5;
    Queue* queue = createQueue(size);
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);

    printf("Phan tu o dau hang doi la: %d\n", deQueue(queue));
    printf("Hang doi sau khi lay ra phan tu dau tien la: ");
    displayQueue(queue);
    return 0;
}