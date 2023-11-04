#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int shared_data = 0;
sem_t mutex, write_block;

void *reader(void *arg) {
    sem_wait(&mutex);

    
    printf("Reader is reading: %d\n", shared_data);

    sem_post(&mutex);
    pthread_exit(NULL);
}

void *writer(void *arg) {
    sem_wait(&write_block);

    
    shared_data++;
    printf("Writer is writing: %d\n", shared_data);

    sem_post(&write_block);
    pthread_exit(NULL);
}

int main() {
    pthread_t reader_thread, writer_thread;

    sem_init(&mutex, 0, 1);
    sem_init(&write_block, 0, 1);

    pthread_create(&reader_thread, NULL, reader, NULL);
    pthread_create(&writer_thread, NULL, writer, NULL);

    pthread_join(reader_thread, NULL);
    pthread_join(writer_thread, NULL);

    sem_destroy(&mutex);
    sem_destroy(&write_block);

    return 0;
}

