//
// Created by Lenovo on 13/03/2023.
//

#include "functions.h"


void createStack(int capacity, Stack *stack) {
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (int *) calloc(capacity, sizeof(int));
    if (!stack->items) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

bool isFull(Stack stack) {
    return stack.top == stack.capacity - 1;
}

bool isEmpty(Stack stack) {
    return stack.top == -1;
}

void destroyStack(Stack *stack) {
    free(stack->items);
    stack->capacity = 0;
    stack = NULL;
    stack->top = -1;
}

void push(Stack *stack, int item) {
    if (isFull(*stack)) {
        printf(FULL_MESSAGE);
        return;
    }
    stack->top++;
    stack->items[stack->top] = item;
}

int pop(Stack *stack) {
    if (isEmpty(*stack)) {
        printf(EMPTY_MESSAGE);
        return stack->top;
    }
    int result = stack->items[stack->top];
    stack->items[stack->top--] == 0;
    return result;
}

void printStack(Stack stack) {
    for (int i = 0; i < stack.capacity; ++i) {
        printf("%i ", stack.items[i]);
    }

}

int peek(Stack stack) {
    if(isEmpty(stack)){
        printf(EMPTY_MESSAGE);
        return stack.top;
    }
    return stack.items[stack.top];
}

int size(Stack stack) {
    int value = 0;
    for (int i = 0; i < stack.items[stack.top] ; ++i) {
        value++;
    }
    return value;
}
