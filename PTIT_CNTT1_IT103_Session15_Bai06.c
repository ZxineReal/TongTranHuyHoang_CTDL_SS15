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

int checkIncrease(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong!");
        return 0;
    }
    for (int i = queue->front; i < queue->rear; i++) {
        if (queue->array[i + 1] - queue->array[i] != 1) {
            return 0;
        }
    }
    return 1;
}


int main(void) {
    int n;
    printf("Moi ban nhap vao so luong phan tu:");
    scanf("%d", &n);
    Queue* queue = createQueue(n);

    for (int i = 0; i < n; i++) {
        int value;
        printf("Moi ban nhap vao phan tu thu %d:", i + 1);
        scanf("%d", &value);
        enQueue(queue, value);
    }
    if (checkIncrease(queue)) {
        printf("TRUE");
    } else {
        printf("FALSE");
    }
    return 0;
}