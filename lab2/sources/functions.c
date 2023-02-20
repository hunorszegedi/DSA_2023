//
// Created by Lenovo on 18/02/2023.
//



#include "functions.h"

//definition

///**
// * Calculates the sum of 2 integers
// * @param number1
// * @param number2
// * @return the value of number1 + number2
// */
//int sum(int number1, int number2) {
//    return number1 + number2;
//}
//
//
///**
// * Finds the minimum of 3 float numbers
// * @param number1
// * @param number2
// * @param number3
// * @return minimum
// */
//float minimum(float number1, float number2, float number3) {
//    float min = (number1 < number2) ? (number1) : (number2);
//    if (min > number3) {
//        min = number3;
//    }
//    return min;
//}
//
///**
// * Allocates memory for a one dimensional array and returns the pointer
// * @param n
// * @return pointer to an int
// */
//int *allocateMemoryForArray1(int n) {
//    int *pArray = (int *) calloc(n, sizeof(int));
//    if (!pArray) {
//        printf(MEMORY_ALLOCATION_ERROR_CODE);
//        exit(MEMORY_ALLOCATION_ERROR_CODE);
//    }
//    return pArray;
//}
//
///**
// * Allocates memory for array
// * @param n (length)
// * @param double pointer to an array
// */
//void allocateMemoryForArray2(int n, int **dpArray) {
//    //int -> int* => & //intre mutato pointer, megkapom a cimet
//    //int* -> int ** => &
//
//    //int* -> int => * //cimbol el szeretnem erni az erteket, amire mutat
//    //int ** -> int * => *
//    *dpArray = (int *) calloc(n, sizeof(int));
//    if (!(*dpArray)) {
//        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
//        exit(MEMORY_ALLOCATION_ERROR_CODE);
//    }
//}
//
///**
// * Reads all data from a specific input
// * Calls the memory allocation function
// * @param n
// * @param dpArray
// * @param input (filename)
// */
//void readArray(int *pn, int **dpArray, const char *input) {
//    if (!freopen(input, "r", stdin)) {
//        printf(FILE_OPENING_ERROR_MESSAGE);
//        exit(FILE_OPENING_ERROR_CODE);
//    }
//    scanf("%i", pn);
//    allocateMemoryForArray2(*pn, dpArray);
//    for (int i = 0; i < *pn; ++i) {
//        scanf("%i", *dpArray + i);
//    }
//    freopen("CON", "r", stdin);
//}
//
///**
// * Prints all elements of the array
// * @param n
// * @param pArray
// * @param output
// */
//void printArray(int n, int *pArray, const char *output) {
//    freopen(output, "w", stdout);
//    printf("The elements of the array:");
//    for (int i = 0; i < n; ++i) {
//        printf("%i ", pArray[i]);
//    }
//    printf("\n");
//    freopen("CON", "w", stdout);
//
//}
//
///**
// * Deallocates the memory
// * @param dpArray
// */
//void deallocateMemoryForArray(int **dpArray) {
//    free(*dpArray);
//    *dpArray = NULL;
//}
//
///**
// * Calculates the average of 2 numbers
// * @param number1
// * @param number2
// * @return average
// */
//float avg(float number1, float number2) {
//    return (number1 + number2) / 2;
//}
//
///**
// * Calculates the maximum of 3 numbers
// * @param number1
// * @param number2
// * @param number3
// * @return maximum
// */
//float maximum(float number1, float number2, float number3) {
//    float maximum = (number1 > number2) ? (number1) : (number2);
//    if (number3 > maximum) {
//        maximum = number3;
//    }
//    return maximum;
//}
//
///**
// * fills the array with random numbers
// * @param n = the number of elements
// * @param pArray = the array
// * @param start = start
// * @param end = end
// */
//void fillWithRandomNumbers(int n, int *pArray, int start, int end) {
//    srand(time(NULL));
//    for (int i = 0; i < n; ++i) {
//        pArray[i] = rand() % (end - start + 1) + start;
//    }
//}
//
///**
// * prints the array in revers
// * @param n = the number of elements
// * @param pArray = the array
// * @param output = con or file or
// */
//void printArrayInReverseOrder(int n, int *pArray, const char *output) {
//    freopen(output, "w", stdout);
//    printf("The elements of the array in reverse order:");
//    for (int i = n - 1; i >= 0; --i) {
//        printf("%i ", pArray[i]);
//    }
//    printf("\n");
//    freopen("CON", "w", stdout);
//}
//
///**
// *Calculcates the number of even numbers
// * @param n numbers in array
// * @param pArray name of array
// * @return count
// */
//int numberOfEvenNumbers(int n, int *pArray) {
//    int count = 0;
//    for (int i = 0; i < n; ++i) {
//        if (pArray[i] % 2 == 0) {
//            count++;
//        }
//    }
//    return count;
//}
//
///**
// * Calculates the sum of positive numbers
// * @param n numbers in array
// * @param pArray name of array
// * @return sum
// */
//int sumOfPositiveNumbers(int n, int *pArray) {
//    int countSum = 0;
//    for (int i = 0; i < n; ++i) {
//        if (pArray[i] >= 0) {
//            countSum += pArray[i];
//        }
//    }
//    return countSum;
//}

/**
 * memory allocation, simple, but not that ellegant
 * @param rows = number of rows
 * @param cols = number of columns
 * @return matrix
 */
int **allocateMemoryForMatrix1(int rows, int cols) {
    int **matrix = (int **) calloc(rows, sizeof(int *));
    if (!matrix) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int *) calloc(cols, sizeof(int));
        if (!matrix[i]) {
            printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
            exit(MEMORY_ALLOCATION_ERROR_CODE);
        }
    }
    return matrix;
}

/**
 * memory allocation
 * @param rows = number of rows
 * @param cols = number of columns
 * @param dpMatrix
 */
void allocateMemoryForMatrix2(int rows, int cols, int ***dpMatrix) {
    *dpMatrix = (int **) calloc(rows, sizeof(int *));
    if (!(*dpMatrix)) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < rows; ++i) {
        ((*dpMatrix)[i]) = (int *) calloc(cols, sizeof(int));
        if (!((*dpMatrix)[i])) {
            printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
            exit(MEMORY_ALLOCATION_ERROR_CODE);
        }
    }
}

void readMatrix(int *pRows, int *pCols, int ***dpArray, const char *input) {
    if (!freopen(input, "r", stdin)) {
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    scanf("%i", pRows);
    scanf("%i", pCols);
    allocateMemoryForMatrix2(*pRows, *pCols, dpArray);
    for (int i = 0; i < *pRows; ++i) {
        for (int j = 0; j < *pCols ; ++j) {
            scanf("%i", &((*dpArray)[i])[j]);
        }
    }
    freopen("CON", "r", stdin);
}




