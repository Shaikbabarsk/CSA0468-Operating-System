#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
  
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

   
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread1, NULL, thread_function, NULL);


    if (pthread_equal(thread1, thread2)) {
        printf("Thread 1 and Thread 1 are equal.\n");
    } else {
        printf("Thread 1 and Thread 1 are not equal.\n");
    }



    return 0;
}

