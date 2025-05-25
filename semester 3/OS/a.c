#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define numchop 5
#define numphil 5

sem_t chops[numchop];
sem_t mutex;

void dine(int n)
{

    printf("P %d", n);
    sem_wait(&mutex);

    printf("L %d", n);
    sem_wait(&chops[n]);

    printf("R %d", n);
    sem_wait(&chops[(n + 1) % numchop]);

    sem_post(&mutex);
    printf("E %d", n);
    sleep(1);

    sem_post(&chops[n]);
    sem_post(&chops[(n + 1) % numchop]);

    printf("F %d", n);
}
int main()
{

    pthread_t philospher[numphil];

    sem_init(&mutex, 0, 1);

    for (int i = 0; i < numchop; i++)
    {
        // pthread_create(&philospher,NULL,dine,i);
        sem_init(&chops[i], 0, 1);
    }
    for (int i = 0; i < numphil; i++)
    {
        pthread_create(&philospher[i], NULL, dine, i);
    }
    for (int i = 0; i < numphil; i++)
    {
        pthread_join(philospher[i], NULL);
    }
    for (int i = 0; i < numchop; i++)
    {
        // pthread_create(&philospher,NULL,dine,i);
        // sem_init(&chops[i],0,1);
        sem_destroy(&chops[i]);
    }

    return 0;
}