#include "functions.h"


int calculateResultByOperation(int val1, int val2, char *token);

enum StackExceptions {
    INCORRECT_EXPRESSION, INVALID_OPERATOR, INVALID_OPERAND
};

void displayErrorMessage(enum StackExceptions exception);


void checkOperandValidity(char *token);

int main() {

//    srand(time(NULL));
//    Stack stack;
//    int capacity;
//    printf("Give me the capacity:");
//    scanf("%i", &capacity);
//    createStack(capacity, &stack);
//    for (int i = 0; i < capacity; ++i) {
//        push(&stack, rand() % 50);
//    }
//    printStack(stack);
//    printf("The current size is %i\n", size(stack));
//    for (int i = 0; i < 2; ++i) {
//        pop(&stack);
//    }
//
//    printStack(stack);
//    printf("The current size is %i\n", size(stack));


    char input[] = "2 5 3 6 + * * 15 / 2 -";
    Stack stack;
    createStack(strlen(input), &stack);

    const char separators[2] = " ";
    char *token = strtok(input, separators);

    const char operators[] = "+-*/%";

    while (token != NULL) {
        //printf("%s\n", token);
        if (strstr(operators, token)) {
            //operator --pop two elements form the stack
            if (isEmpty(stack))displayErrorMessage(INCORRECT_EXPRESSION);
            int val1 = pop(&stack);
            if (isEmpty(stack))displayErrorMessage(INCORRECT_EXPRESSION);
            int val2 = pop(&stack);
            int result = calculateResultByOperation(val2, val1, token);
            push(&stack, result);
            printStack(stack);
            printf("\n");
        } else {
            //operator -- push number to stack
            checkOperandValidity(token);
            push(&stack, atoi(token));      //atoi atalakitja inte
            printStack(stack);
            printf("\n");
        }


        token = strtok(NULL, separators);
    }
    int finalResult = pop(&stack);
    if (!isEmpty(stack)) {
        displayErrorMessage(INCORRECT_EXPRESSION);
    } else {
        printf("The final result is: %i\n", finalResult);

    }

    destroyStack(&stack);
    return 0;
}

void checkOperandValidity(char *token) {
    for (int i = 0; i < strlen(token); ++i) {
        if(!isdigit(token[i])){
            displayErrorMessage(INVALID_OPERAND);
        }
    }
}


int calculateResultByOperation(int val1, int val2, char *token) {
    char operation = token[0];
    switch (operation) {
        case '+':
            return val1 + val2;
        case '-':
            return val1 - val2;
        case '*':
            return val1 * val2;
        case '/':
            return val1 / val2;
        case '%':
            return val1 % val2;
        default:
            displayErrorMessage(INVALID_OPERATOR);
            return STACK_EXCEPTION_ERROR_CODE;
    }
}


void displayErrorMessage(enum StackExceptions exception) {
    switch (exception) {
        case INCORRECT_EXPRESSION:
            printf(INCORECT_EXPRESSION_MESSAGE);
            break;
        case INVALID_OPERATOR:
            printf(INVALID_OPERATOR_MESSAGE);
            break;
        case INVALID_OPERAND:
            printf(INVALID_OPERAND_MESSAGE);
            break;
        default:
            printf(UNKNOWN_EXCEPTION_MESSAGE);
            break;
    }
    exit(STACK_EXCEPTION_ERROR_CODE);
}