#include "array.h"

int main() {

    IntArray array;
    int value = 1;
    createIntArray(10, &array); //pointerkent adom at, cim szerint, hogy valoban erzekelje a valtozast
    printArray(array);
//    insertFirst(&array, 2);
//    insertFirst(&array, 9);
//    insertFirst(&array, 10);
//    insertLast(&array, 13);
//    printArray(array);
//    insertAt(&array, 2, 99);
//    printArray(array);
    for (int i = 0; i < array.capacity / 2; ++i) {
        insertAt(&array, i, value++);

    }
    printArray(array);
    while (!isFull(array)) {
        if (value % 2 == 0) {
            insertFirst(&array, value++);
        } else insertLast(&array, value++);
    }
    printArray(array);
    deleteItemAt(&array, 3);
    printArray(array);

    printf("Give me an integer number:");
    int searchFor;
    scanf("%i", &searchFor);
    int res = search(array, searchFor);
    if (res == -1) {
        printf(NOT_FOUND_MESSAGE);
    } else {
        printf("Found %i at position: %i\n", searchFor, res);
        printArray(array);
    }


    printf("Give me an integer number to delete:");
    int searchFor1;
    scanf("%i", &searchFor1);
    int res1 = search(array, searchFor1);
    if (res1 == -1) {
        printf(NOT_FOUND_MESSAGE);
    } else {
        printf("Found %i at position: %i\n", searchFor1, res1);
        deleteItemAt(&array, res1);
        printArray(array);
    }

    printf("Give me an integer number:");
    int searchFor2;
    scanf("%i", &searchFor2);
    int res2 = search(array, searchFor2);
    if (res2 == -1) {
        printf(NOT_FOUND_MESSAGE);
    } else {
        printf("Found %i at position: %i\n", searchFor2, res2);
        printf("Give me another integer number:");
        int newItem;
        scanf("%i", &newItem);
        if (!update(&array, res2, newItem)) {
            printf("Update unsuccesful!\n");
        }
        printArray(array);
        deleteItemAt(&array, res2);
        printArray(array);
    }

    srand(time(NULL));
    while (!isEmpty(array)) {
        int position = rand() % array.capacity;
        printf("Item at position %i = %i\n", position, getItemAt(array, position));
        deleteItemAt(&array, position);
    }

    printArray(array);

    deallocateIntArray(&array);

    return 0;
}
