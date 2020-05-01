#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
pthread_mutex_t lock;
void* f(void * a)
{
	pthread_mutex_lock(&lock);
	printf("string = %s length=%d\n",(char*)a,strlen((char*)a));
	sleep(2);
	pthread_mutex_unlock(&lock);
}
int main()
{
	char a[50];
	int i=0,j;
	pthread_t p[100];
	pthread_mutex_init(&lock,NULL);
	while(i<100)
	{
		printf("Enter a string\n");
		scanf("%s",a);
		pthread_create(&p[i],NULL,f,(void*)a);
		sleep(1);
                i++;
	}
	for(j=0;j<i;j++)
		pthread_join(p[i],NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}
