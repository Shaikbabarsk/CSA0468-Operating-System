#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *thread_function(void *arg) {
    int exit_code = 99; 

    
    pthread_exit((void *) &exit_code);

   
    printf("This won't be reached.\n");

    return NULL;
}

int main() {
    pthread_t thread;
    void *thread_exit_status;

    
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        perror("Thread creation failed");
        return 1;
    }


    if (pthread_join(thread, &thread_exit_status) != 0) {
        perror("Thread join failed");
        return 1;
    }

    int *exit_code_ptr = (int *)thread_exit_status;
    if (exit_code_ptr != NULL) {
        int exit_code = *exit_code_ptr;
        printf("Thread exit status code: %d\n", exit_code);
    } else {
        printf("Thread exit status code not available.\n");
    }

    return 0;
}

