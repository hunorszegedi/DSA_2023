#include "functions.h"

int main() {
    Queue queue;
    createQueue(5, &queue);


    bool ok = true;
    while (ok) {
        int option;
        printf("Choose from the following:"
               "\n\t- 1. isFull?"
               "\n\t- 2. isEmpty?"
               "\n\t- 3. New car arrived (enqueue)"
               "\n\t- 4. Remove car (dequeue)"
               "\n\t- 5. Display all data"
               "\n\t- 0. Exit");
        printf("\n\nYour option:");
        scanf("%i", &option);
        switch (option) {
            case 0:
                printf("The end");
                ok = false;
                break;
            case 1:
                printf("The queue is full: %s\n", (isFull(queue) ? ("yes") : ("no")));
                break;
            case 2:
                printf("The queue is empty: %s\n", (isEmpty(queue) ? ("yes") : ("no")));
                break;
            case 3:
//                printf("New car arrived, give a valid plate number:");
//                char carPlate[CAR_PLATE_NUMBER_LIMIT];
//                scanf("%s", carPlate);
//                enqueue(&queue, carPlate);
                readFromFile(&queue, "be.txt");
                break;
            case 4: {
                char *result = dequeue(&queue);
                printf("The removed car is: %s\n", result);
                break;
            }
            case 5:
                display(queue);
                break;
            default:
                printf("Invalid option!\n");
        }
    }


    destroyQueue(&queue);
    return 0;
}
