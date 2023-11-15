#include <stdio.h>
#include <stdlib.h>

void cscan(int arr[], int head, int size) {
    int totalMovement = 0;

   
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
               
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sequence of servicing disk requests:\n");

    for (int i = 0; i < size; i++) {
        if (arr[i] >= head) {
            printf("%d -> ", arr[i]);
            totalMovement += abs(head - arr[i]);
            head = arr[i];
        }
    }

    // Move to the beginning of the disk
    printf("0 -> ");
    totalMovement += head;

    // C-SCAN to the right again
    for (int i = 0; i < size; i++) {
        if (arr[i] < head) {
            printf("%d -> ", arr[i]);
            totalMovement += abs(head - arr[i]);
            head = arr[i];
        }
    }

    printf("\nTotal head movement: %d\n", totalMovement);
}

int main() {
    int arr[100];
    int head, size;

    printf("Enter the size of the request queue: ");
    scanf("%d", &size);

    printf("Enter the request queue elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial position of the disk arm: ");
    scanf("%d", &head);

    cscan(arr, head, size);

    return 0;
}

