#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define b_size 5

sem_t empty, full, mutex;
int max_items = 10;
int in = 0;
int out = 0;
int buffer[arr_size];
int produced_count = 0;
int consumed_count = 0;

void *producer(void *args)
{

    while (produced_count < max_items)
    {
        sleep(1);
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = 1;
        printf("Item produced");
        in = (in + 1) % b_size;
        produced_count++;

        sem_post(&full);
        sem_post(&mutex);
    }
}

void *consumer(void *args)
{

    while (consumed_count < max_items)
    {
        sleep(1);
        sem_wait(&full);
        sem_wait(&mutex);

        buffer[out] = 0;
        printf("Item produced");
        out = (out + 1) % b_size;
        consumed_count++;

        sem_post(&empty);
        sem_post(&mutex);
    }
}

int main()
{

    pthread_t producer_t, consumer_t;

    sem_init(&empty, 0, b_size);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&producer_t, NULL, producer, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);

    pthread_join(producer_t, NULL);
    pthread_join(consumer_t, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}