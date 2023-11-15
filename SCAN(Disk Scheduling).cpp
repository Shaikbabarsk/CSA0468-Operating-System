#include <stdio.h>
#include <stdlib.h>

void scan(int arr[], int head, int size, int direction) {
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

    int index = 0;
    while (index < size && arr[index] < head) {
        index++;
    }

    printf("Sequence of servicing disk requests:\n");

    // Scan to the right
    for (int i = index; i < size; i++) {
        printf("%d -> ", arr[i]);
        totalMovement += abs(head - arr[i]);
        head = arr[i];
    }

  
    if (direction == 1) {
        for (int i = index - 1; i >= 0; i--) {
            printf("%d -> ", arr[i]);
            totalMovement += abs(head - arr[i]);
            head = arr[i];
        }
    }

    printf("\nTotal head movement: %d\n", totalMovement);
}

int main() {
    int arr[100];
    int head, size, direction;

    printf("Enter the size of the request queue: ");
    scanf("%d", &size);

    printf("Enter the request queue elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial position of the disk arm: ");
    scanf("%d", &head);

    printf("Enter the initial direction of the disk arm (1 for right, 0 for left): ");
    scanf("%d", &direction);

    scan(arr, head, size, direction);

    return 0;
}

