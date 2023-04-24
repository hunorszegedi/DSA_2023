//
// Created by Lenovo on 19/03/2023.
//

#include "functions.h"



void createQueue(int capacity, Queue *queue) {
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->elements = (char **) calloc(CAR_PLATE_NUMBER_LIMIT, sizeof(char *));
    if (!queue->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < queue->capacity; ++i) {
        queue->elements[i] = (char *) calloc(CAR_PLATE_NUMBER_LIMIT, sizeof(char));
        if (!queue->elements[i]) {
            printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
            exit(MEMORY_ALLOCATION_ERROR_CODE);
        }
    }
}

void destroyQueue(Queue *queue) {
    for (int i = 0; i < queue->capacity; ++i) {
        free(queue->elements[i]);
    }
    free(queue->elements);
    queue->capacity = 0;
    queue->front = queue->rear = -1;
    queue = NULL;
}

bool isFull(Queue queue) {
    return queue.rear == queue.capacity - 1;
}

bool isEmpty(Queue queue) {
    return queue.front == -1 && queue.rear == -1;
}

void enqueue(Queue *queue, char *item) {
    if (isFull(*queue)) {
        printf(FULL_MESSAGE);
        return;
    }
    //egyetlen elem van
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    strcpy(queue->elements[queue->rear], item);
}

char *dequeue(Queue *queue) {
    if (isEmpty(*queue)) {
        printf(EMPTY_MESSAGE);
        return EMPTY_MESSAGE;
    }
    //ha csak egyetlen elem van
    if (queue->front == queue->rear) {
        int poz = queue->front;
        queue->front = queue->rear = -1;
        return queue->elements[poz];
    }
    return queue->elements[queue->front++];
}

void display(Queue queue) {
    printf("The elements of the queue:\n");
    if(isEmpty(queue)){
        printf(EMPTY_MESSAGE);
        return;
    }
    for (int i = queue.front; i <= queue.rear; ++i) {
        printf("\t- %s\n", queue.elements[i]);
    }
    printf("\n");
}

void readFromFile(Queue *queue, const char *input) {
    if (!freopen(input, "r", stdin)) {
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    char item[CAR_PLATE_NUMBER_LIMIT];
    while (scanf("%s", item) == 1) {
        enqueue(queue, item);
    }
    freopen("CON", "r", stdin);
}

