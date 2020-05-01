#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
sem_t mutex1,mutex2;
pthread_t p,c;
void* fn(void *a)
{
        //printf("HELLO");
	while(1)	
	{
		sem_wait(&mutex2);
		printf("00\n");
		sem_post(&mutex1);
                sleep(2);
	}
}
void* fn1(void* a)
{

	while(1)	
        {
		sem_wait(&mutex1);
		printf("11\n");
		sem_post(&mutex2);
                //sleep(5);
	}
}
int main()
{
        printf("hello");
	sem_init(&mutex1,0,0);
	sem_init(&mutex2,0,1);
	pthread_create(&p,NULL,fn,NULL);
	pthread_create(&c,NULL,fn1,NULL);
	pthread_join(p,NULL);
	pthread_join(c,NULL);
	return 0;
}
