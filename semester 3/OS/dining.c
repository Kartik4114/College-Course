#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t chops[5];
sem_t mutex;

void *dine(void *args){

    printf("P %d is thinking ",n);
    sem_wait(&mutex);
    printf("P %d is try",n);

    sem_wait(&chops[5]);
    


}
int main()
{
    pthread_t philospher[5];

    for (int i = 0; i < 5; i++)
    {
        sem_init(&chops[i],0,1);
        pthread_create(&philospher[i],NULL,dine,i);
    }

    for (int i = 0; i < 5; i++)
    {
        sem_destroy(&chops[i]);
        pthread_join(philospher[i],NULL);
    }


    
    return 0;
}