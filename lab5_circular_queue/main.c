
#include "circular_queue.h"

int main() {
    Queue intQueue;
    createQueue(6, &intQueue);
    bool ok = true;
    while (ok) {
        printf("Choose from the following options:"
               "\n\t- Check if queue is full: 1"
               "\n\t- Check if queue is empty: 2"
               "\n\t- Add a new item to the queue: 3"
               "\n\t- Remove an item from the queue: 4"
               "\n\t- Display all items waiting in the queue: 5"
               "\n\t- Exit: 0"
               "\n\nChoose an option:");
        int option;
        scanf("%i", &option);
        switch (option) {
            case 0:
                printf("The end");
                ok = false;
                break;
            case 1:
                printf("The queue is full: %s\n", (isFull(intQueue) ? ("yes") : ("no")));
                break;
            case 2:
                printf("The queue is empty: %s\n", (isEmpty(intQueue) ? ("yes") : ("no")));
                break;
            case 3:
                printf("Give an integer number:");
                int value;
                scanf("%i", &value);
                enqueue(&intQueue, value);
                break;
            case 4: {
                int value1 = dequeue(&intQueue);
                if (value1 == INT_MIN) {
                    printf(EMPTY_MESSAGE);
                    break;
                }
                printf("The following item was removed: %i\n", value1);
            }
            case 5:
                display(intQueue);
                break;
            default:
                printf("Invalid option!\n");
        }
    }
    destroyQueue(&intQueue);
    return 0;
}
