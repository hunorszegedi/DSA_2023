#include "array.h"

int main() {

    int option;
    IntArray array1, array2;

    //Exercise 1. declaration
    int capacityUser;
    printf("Give me a capacity to array 1:");
    scanf("%i", &capacityUser);
    createIntArray(capacityUser, &array1);

    printf("Give me a capacity to array 2:");
    scanf("%i", &capacityUser);
    createIntArray(capacityUser, &array2);


    printf("Choose an exercise (press 0 to exit):");
    scanf("%i", &option);

    //Exercise 3. array1
    for (int i = 0; i < capacityUser / 2; ++i) {
        insertFirst(&array1, i + 1);
    }
    //Exercise 3. array2
    for (int i = 0; i < capacityUser / 2; ++i) {
        insertLast(&array2, i + 1);
    }

    //Exercise 7.
    int userChoose, counter = 0;

    //Exercise 8.
    int modified;

    switch (option) {
        case 0:
            break;
        case 2:
            //Exercise 2. and 4.
            printArray(array1);
            printArray(array2);
            break;
        case 5:
            //Exercise 5. and 6.
            for (int i = capacityUser / 2 + 1; i <= capacityUser; ++i) {
                if (i % 2 == 0) {
                    insertFirst(&array2, i);
                } else { insertLast(&array2, i); }
            }
            printArray(array2);
            break;
        case 7:
            //Exercise 8.
            for (int i = capacityUser / 2 + 1; i <= capacityUser; ++i) {
                if (i % 2 == 0) {
                    insertFirst(&array2, i);
                } else { insertLast(&array2, i); }
            }
            printArray(array2);

            printf("Give me a number:");
            scanf("%i", &userChoose);

            for (int i = 0; i < capacityUser; ++i) {
                if (array2.elements[i] == userChoose) {
                    counter++;
                }
            }
            printf("The number %i occured %i times in array.\n", userChoose, counter);
            break;
        case 8:
            //Exercise 8.
            for (int i = capacityUser / 2 + 1; i <= capacityUser; ++i) {
                if (i % 2 == 0) {
                    insertFirst(&array2, i);
                } else { insertLast(&array2, i); }
            }
            printArray(array2);

            printf("Give me a number:");
            scanf("%i", &userChoose);

            for (int i = 0; i < capacityUser; ++i) {
                if (array2.elements[i] == userChoose) {
                    counter++;
                }
            }
            printf("The number %i occured %i times in array.\n", userChoose, counter);
            printf("Give me a number to be modified to:");
            scanf("%i", &modified);
            for (int i = 0; i < capacityUser; ++i) {
                if (counter) {
                    if (array2.elements[i] == userChoose) {
                        array2.elements[i] = modified;
                    }
                }
            }
            printArray(array2);

            break;
        case 9:
            printArray(array2);
            break;
        default:
            break;
    }

    return 0;
}
