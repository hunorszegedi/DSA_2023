//
// Created by Lenovo on 19/03/2023.
//

#ifndef LAB5_CIRCULAR_QUEUE_CIRCULAR_QUEUE_H
#define LAB5_CIRCULAR_QUEUE_CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <constants.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>


typedef struct Queue{
    int capacity;
    int front;
    int rear;
    int *elements;
}Queue;

/**
* Creates the queue data structure, allocates memory for elements
* @param capacity
* @param queue
*/
void createQueue(int capacity, Queue *queue);
/**
* Deallocates the elements array -> free
* @param queue
*/
void destroyQueue(Queue* queue);
/**
* Checks whether the queue is full or not
* @param queue
* @return true/false
*/
bool isFull(Queue queue);
/**
* Checks whether the queue is empty or not
* @param queue
* @return true/false
*/
bool isEmpty(Queue queue);
/**
* Adds a new item to the end of the queue
* @param queue
* @param item
*/
void enqueue(Queue* queue, int item);
/**
* Removes the first item from the queue
* @param queue
* @return
*/
int dequeue(Queue* queue);
/**
* Prints all items of the queue
* @param queue
*/
void display(Queue queue);


#endif //LAB5_CIRCULAR_QUEUE_CIRCULAR_QUEUE_H
