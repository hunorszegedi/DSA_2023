//
// Created by Lenovo on 18/02/2023.
//

#ifndef LAB1_GYAKORLAS_FUNCTIONS_H
#define LAB1_GYAKORLAS_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "constatns.h"
//declaration

int sum(int number1, int number2);

float minimum(float number1, float number2, float number3);

int *allocateMemoryForArray1(int n);

void allocateMemoryForArray2(int n, int **dpArray);

void readArray(int *pn, int **dpArray, const char *input);

void printArray(int n, int *pArray, const char *output);

void deallocateMemoryForArray(int **dpArray);

float avg(float number1, float number2);

float maximum(float number1, float number2, float number3);

void fillWithRandomNumbers(int n, int *pArray, int start, int end);

void printArrayInReverseOrder(int n, int *pArray, const char *output);

int numberOfEvenNumbers(int n, const int *pArray);

int sumOfPositiveNumbers(int n, const int *pArray);

//MATRIXOK

int **allocateMemoryForMatrix1(int rows, int columns);

void allocateMemoryForMatrix2(int rows, int columns, int ***dpMatrix);

void readMatrix(int *pRows, int *pColumns, int ***dpArray, const char *input);

void printMatrix(int rows, int columns, int **matrix, const char *output);

void deallocateMatrix(int rows, int ***dpMatrix);


int minimumValueOfRow(int columns, const int *pRows);

int *rowMinimums(int rows, int columns, int **pMatrix);

int minimumValueOfMatrix(int rows, int columns, int **pMatrix);

float averageOfMatrixElements(int rows, int columns, int **pMatrix);


void parosSzamokNullaraAllitasa(int rowsTest, int columnsTest, int **pMatrixTest);

#endif //LAB1_GYAKORLAS_FUNCTIONS_H
