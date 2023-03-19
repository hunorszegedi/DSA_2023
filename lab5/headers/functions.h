//
// Created by Lenovo on 13/03/2023.
//

#ifndef LAB5_FUNCTIONS_H
#define LAB5_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <constants.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct Stack{
    int capacity;
    int top;
    int *items;
}Stack;

/**
 * print the STACK (not right to do that)
 * @param stack
 */
void printStack(Stack stack);

/**
* Initializing the capacity and size of stack,
* allocating memory for the @elements array
* @param capacity
* @param stack
*/
void createStack(int capacity, Stack * stack);
/**
* Deallocates the memory
* @param stack
*/
void destroyStack(Stack* stack);
/**
* Checks whether the stack is full
* @param stack
* @return
*/
bool isFull(Stack stack);
/**
* Checks whether the stack is empty
* @param stack
* @return
*/
bool isEmpty(Stack stack);
/**
* Pushes a new item to the stack,
* if it is not full
* @param stack
* @param item
*/
void push(Stack* stack, int item);
/**
* Removes the top element from the stack,
* if it is not empty
* @param stack
* @return
*/
int pop(Stack* stack);
/**
* Returns the top element of the stack,
* if it is not empty
* @param stack
* @return
*/
int peek(Stack stack);
/**
* Returns the size of the stack
* @param stack
* @return
*/
int size(Stack stack);



#endif //LAB5_FUNCTIONS_H
