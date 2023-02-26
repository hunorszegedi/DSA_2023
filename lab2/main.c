#include "functions.h"


int main() {

// 1
//    int num1, num2;
//    printf("Number 1:");
//    scanf("%i", &num1);
//    printf("Number 2:");
//    scanf("%i", &num2);
//    printf("The sum of the number is: %i\n", sum(num1, num2));

// 2
//    float number1, number2, number3;
//    printf("Number 1:");
//    scanf("%f", &number1);
//    printf("Number 2:");
//    scanf("%f", &number2);
//    printf("Number 3:");
//    scanf("%f", &number3);
//    printf("Minimum: %.2f", minimum(number1, number2, number3));
//
//    printf("\nThe average is: %.2f", avg(number1, number2));
//    printf("\nThe maximum is: %.2f", maximum(number1, number2, number3));

//    int n, *pArray;
//    pArray = allocateMemoryForArray1(n);
//    allocateMemoryForArray2(n, &pArray);
//    readArray(&n, &pArray, "be.txt");
//    printArray(n, pArray, "CON");
//    deallocateMemoryForArray(&pArray);

//    int m, *numbers, start, end;
//    printf("Number of generated items:");
//    scanf("%i", &m);
//    printf("Start:");
//    scanf("%i", &start);
//    printf("End:");
//    scanf("%i", &end);
//    if(start > end){
//        int aux = start;
//        start = end;
//        end = aux;
//    }
//    allocateMemoryForArray2(m, &numbers);
//    fillWithRandomNumbers(m, numbers, start, end);
//    printArray(m, numbers, "CON");
//    printArrayInReverseOrder(m, numbers, "CON");
//
//    int count = numberOfEvenNumbers(m, numbers);
//    printf("Number of even number: %i", count);
//
//    int countSum = sumOfPositiveNumbers(m, numbers);
//    printf("\nSum of positive numbers: %i", countSum);
//
//    deallocateMemoryForArray(&numbers);

    //MATRIXOK
    int rows, columns, **pMatrix = NULL;
//    printf("rows:");
//    scanf("%i", &rows);
//    printf("columns:");
//    scanf("%i", &columns);
//    pMatrix = allocateMemoryForMatrix1(rows, columns);
//    allocateMemoryForMatrix2(rows, columns, &pMatrix); //matrix cim szerint
    readMatrix(&rows, &columns, &pMatrix, "beMatrix.txt");
    printMatrix(rows, columns, pMatrix, "CON");

    int givenRow;
    printf("Given Row:");
    scanf("%i", &givenRow);
    //check given row-ra, ami letezik
    if (givenRow >= 0 && givenRow < rows) {
        printf("The minimum of %i is: %i\n", givenRow, minimumValueOfRow(columns, pMatrix[givenRow]));
    } else printf(INVALID_INDEX_ERROR_MESSAGE);

    printf("Minimums of rows: ");
    printArray(rows, rowMinimums(rows, columns, pMatrix), "CON");
    printf("The global minimum of the matrix is %i\n", minimumValueOfMatrix(rows, columns, pMatrix));
    printf("The average of all values is %.2f\n", averageOfMatrixElements(rows, columns, pMatrix));

    deallocateMatrix(rows, &pMatrix); //matrix cim szerint
    if (!pMatrix) { printf("Matrix is NULL"); }
    return 0;
}
