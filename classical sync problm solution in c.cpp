#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 2

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg) {
    int item;
    for (int i = 0; i < 5; i++) {
        item = rand() % 100;  
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        printf("Produced: %d\n", item);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item;
    for (int i = 0; i < 5; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        printf("Consumed: %d\n", item);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_threads[NUM_PRODUCERS];
    pthread_t consumer_threads[NUM_CONSUMERS];

    
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_create(&producer_threads[i], NULL, producer, NULL);
    }
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_create(&consumer_threads[i], NULL, consumer, NULL);
    }

    
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producer_threads[i], NULL);
    }
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumer_threads[i], NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}

