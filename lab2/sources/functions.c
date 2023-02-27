//
// Created by Lenovo on 18/02/2023.
//



#include "functions.h"

//definition

/**
 * Calculates the sum of 2 integers
 * @param number1
 * @param number2
 * @return the value of number1 + number2
 */
int sum(int number1, int number2) {
    return number1 + number2;
}


/**
 * Finds the minimum of 3 float numbers
 * @param number1
 * @param number2
 * @param number3
 * @return minimum
 */
float minimum(float number1, float number2, float number3) {
    float min = (number1 < number2) ? (number1) : (number2);
    if (min > number3) {
        min = number3;
    }
    return min;
}

/**
 * Allocates memory for a one dimensional array and returns the pointer
 * @param n
 * @return pointer to an int
 */
int *allocateMemoryForArray1(int n) {
    int *pArray = (int *) calloc(n, sizeof(int));
    if (!pArray) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    return pArray;
}

/**
 * Allocates memory for array
 * @param n (length)
 * @param double pointer to an array
 */
void allocateMemoryForArray2(int n, int **dpArray) {
    //int -> int* => & //intre mutato pointer, megkapom a cimet
    //int* -> int ** => &

    //int* -> int => * //cimbol el szeretnem erni az erteket, amire mutat
    //int ** -> int * => *
    *dpArray = (int *) calloc(n, sizeof(int));
    if (!(*dpArray)) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

/**
 * Reads all data from a specific input
 * Calls the memory allocation function
 * @param n
 * @param dpArray
 * @param input (filename)
 */
void readArray(int *pn, int **dpArray, const char *input) {
    if (!freopen(input, "r", stdin)) {
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    scanf("%i", pn);
    allocateMemoryForArray2(*pn, dpArray);
    for (int i = 0; i < *pn; ++i) {
        scanf("%i", *dpArray + i);
    }
    freopen("CON", "r", stdin);
}

/**
 * Prints all elements of the array
 * @param n
 * @param pArray
 * @param output
 */
void printArray(int n, int *pArray, const char *output) {
    freopen(output, "w", stdout);
    for (int i = 0; i < n; ++i) {
        printf("%i ", pArray[i]);
    }
    printf("\n");
    freopen("CON", "w", stdout);

}

/**
 * Deallocates the memory
 * @param dpArray
 */
void deallocateMemoryForArray(int **dpArray) {
    free(*dpArray);
    *dpArray = NULL;
}

/**
 * Calculates the average of 2 numbers
 * @param number1
 * @param number2
 * @return average
 */
float avg(float number1, float number2) {
    return (number1 + number2) / 2;
}

/**
 * Calculates the maximum of 3 numbers
 * @param number1
 * @param number2
 * @param number3
 * @return maximum
 */
float maximum(float number1, float number2, float number3) {
    float maximum = (number1 > number2) ? (number1) : (number2);
    if (number3 > maximum) {
        maximum = number3;
    }
    return maximum;
}

/**
 * fills the array with random numbers
 * @param n = the number of elements
 * @param pArray = the array
 * @param start = start
 * @param end = end
 */
void fillWithRandomNumbers(int n, int *pArray, int start, int end) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        pArray[i] = rand() % (end - start + 1) + start;
    }
}

/**
 * prints the array in revers
 * @param n = the number of elements
 * @param pArray = the array
 * @param output = con or file or
 */
void printArrayInReverseOrder(int n, int *pArray, const char *output) {
    freopen(output, "w", stdout);
    printf("The elements of the array in reverse order:");
    for (int i = n - 1; i >= 0; --i) {
        printf("%i ", pArray[i]);
    }
    printf("\n");
    freopen("CON", "w", stdout);
}

/**
 * Calculcates the number of even numbers
 * @param n numbers in array
 * @param pArray name of array
 * @return count
 */
int numberOfEvenNumbers(int n, const int *pArray) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (!(pArray[i] % 2)) {
            count++;
        }
    }
    return count;
}

/**
 * Calculates the sum of positive numbers
 * @param n numbers in array
 * @param pArray name of array
 * @return sum
 */
int sumOfPositiveNumbers(int n, const int *pArray) {
    int countSum = 0;
    for (int i = 0; i < n; ++i) {
        if (pArray[i] >= 0) {
            countSum += pArray[i];
        }
    }
    return countSum;
}

//MATRIXOK

/**
 * VERSION 1. memory allocation
 * @param rows = number of rows
 * @param columns = number of columns
 * @return the pointer to matrix
 */
int **allocateMemoryForMatrix1(int rows, int columns) {
    int **matrix = (int **) calloc(rows, sizeof(int *));
    if (!matrix) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int *) calloc(columns, sizeof(int));
        if (!matrix[i]) {
            printf(MEMORY_ALLOCATION_ERROR_MESSAGE_ROWS);
            exit(MEMORY_ALLOCATION_ERROR_CODE_ROWS);
        }
    }
    return matrix;
}

/**
 * prints all elements of the matrix to  a given output file/ or console
 * @param rows
 * @param columns
 * @param matrix
 * @param output
 */
void printMatrix(int rows, int columns, int **matrix, const char *output) {
    freopen(output, "w", stdout);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%5i ", matrix[i][j]);
        }
        printf("\n");
    }
    freopen("CON", "w", stdout); //visszaallitjuk
}

/**
 * free memory where matrix elements were stored
 * @param dpMatrix
 */
void deallocateMatrix(int rows, int ***dpMatrix) {
    for (int i = 0; i < rows; ++i) {
        free((*dpMatrix)[i]);
    }
    free(*dpMatrix);
    *dpMatrix = NULL;
}

/**
 * allocates memory for a matrix
 * @param rows
 * @param columns
 * @param dpMatrix -> double pointer to matrix
 */
void allocateMemoryForMatrix2(int rows, int columns, int ***dpMatrix) {
    *dpMatrix = (int **) calloc(rows, sizeof(int *)); //*-al elerem a  matrixot
    if (!(*dpMatrix)) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < rows; ++i) {
        (*dpMatrix)[i] = (int *) calloc(columns, sizeof(int));
        if (!(*dpMatrix)[i]) {
            printf(MEMORY_ALLOCATION_ERROR_MESSAGE_ROWS);
            exit(MEMORY_ALLOCATION_ERROR_CODE_ROWS);
        }
    }
}

/**
 * reads all elements of the amtrix from file/ CONSOLE
 * @param pRows
 * @param pColumns
 * @param dpArray -> double pointer to a matrix
 * @param input
 */
void readMatrix(int *pRows, int *pColumns, int ***dpArray, const char *input) {
    //atiranyitas
    if (!freopen(input, "r", stdin)) {
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }

    //rows, columns
    scanf("%i%i", pRows, pColumns);

    //allocation
    allocateMemoryForMatrix2(*pRows, *pColumns, dpArray);

    //reading all data
    for (int i = 0; i < *pRows; ++i) {
        for (int j = 0; j < *pColumns; ++j) {
            scanf("%i", &((*dpArray)[i][j]));
        }
    }

    //visszaallitas
    freopen("CON", "r", stdin);

}

/**
 * minimum value of a specific row
 * @param columns
 * @param pRows
 * @return
 */
int minimumValueOfRow(int columns, const int *pRows) {
    int minimum = INT_MAX; // a legnagyobb int ertek
    for (int i = 0; i < columns; ++i) {
        if (pRows[i] < minimum) {
            minimum = pRows[i];
        }
    }
    return minimum;
}

/**
 * return an array containing all minimum values of rows
 * @param rows
 * @param columns
 * @param pMatrix
 * @return array of minimums
 */
int *rowMinimums(int rows, int columns, int **pMatrix) {
    int *minimums;
    allocateMemoryForArray2(rows, &minimums);
    for (int i = 0; i < rows; ++i) {
        minimums[i] = minimumValueOfRow(columns, pMatrix[i]);
    }
    return minimums;
}

/**
 * The global minimum of the matrix
 * @param rows
 * @param columns
 * @param pMatrix
 * @return the minimum value
 */
int minimumValueOfMatrix(int rows, int columns, int **pMatrix) {
    return minimumValueOfRow(rows, rowMinimums(rows, columns, pMatrix));
}

/**
 * the average of all elements of the matrix
 * @param rows
 * @param columns
 * @param pMatrix
 * @return average value
 */
float averageOfMatrixElements(int rows, int columns, int **pMatrix) {
    if (rows * columns == 0) {
        printf(DIVISION_BY_0_ERROR_MESSAGE);
        return -1;
    }
    float avg = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            avg += pMatrix[i][j];
        }
    }
    return avg / (rows * columns);
}

void parosSzamokNullaraAllitasa(int rowsTest, int columnsTest, int **pMatrixTest) {
    if (rowsTest * columnsTest == 0) {
        printf(DIVISION_BY_0_ERROR_MESSAGE);
    }
    for (int i = 0; i < rowsTest ; ++i) {
        for (int j = 0; j < columnsTest ; ++j) {
            if(!(pMatrixTest[i][j] % 2)){
                pMatrixTest[i][j] = 0;
            }
        }
    }

}





