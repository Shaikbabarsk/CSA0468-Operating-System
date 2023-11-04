#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    int *thread_id = (int *)arg;
    printf("Thread %d is running\n", *thread_id);

    for (int i = 0; i < 5; i++) {
        printf("Thread %d is working...\n", *thread_id);
    }
    printf("Thread %d is done\n", *thread_id);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int thread_id1 = 1, thread_id2 = 2;

   
    if (pthread_create(&thread1, NULL, thread_function, &thread_id1) != 0) {
        perror("Thread creation failed");
        return 1;
    }
    if (pthread_create(&thread2, NULL, thread_function, &thread_id2) != 0) {
        perror("Thread creation failed");
        return 1;
    }

    
    if (pthread_join(thread1, NULL) != 0) {
        perror("Thread join failed");
        return 1;
    }
    if (pthread_join(thread2, NULL) != 0) {
        perror("Thread join failed");
        return 1;
    }

    printf("Both threads have joined.\n");

    return 0;
}

