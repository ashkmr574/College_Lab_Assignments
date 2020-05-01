#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#define N 5
typedef struct buffer 
{
   int a[N];
   sem_t empty,full;
   int in,out;
}buffer;
buffer buf;
void* C(void * a)
{
	int t;
	//sem_wait(&(buf.full));
	while(1)	
	{
		sem_wait(&(buf.full));
		t=buf.a[buf.out];
		printf("item consumed = %d\n",t);
		//buf.out++;
		buf.out=(buf.out+1)%N;
		sem_post(&(buf.empty));
	}
	//sem_post(&(buf.empty));
}
void* P(void * a)
{
	int t=1;
	//sem_wait(&(buf.empty));
	while(1)
	{
		sem_wait(&(buf.empty));
		buf.a[buf.in]=t;
		printf("item produced = %d\n",t);
		sem_post(&(buf.full));
		buf.in=(buf.in+1)%N;
		if(t%N==0)
		{
		     sleep(2);
		}
		t++;
		//buf.in++;
		//buf.in=(buf.in+1)%N;
		//sem_post(&(buf.full));
	}
	//sem_post(&(buf.full));
}
int main()
{
	sem_init(&(buf.empty),0,N);
	sem_init(&(buf.full),0,0);
	buf.in=0;
	buf.out=0;
	pthread_t c,p;
	pthread_create(&p,NULL,C,NULL);
	pthread_create(&c,NULL,P,NULL);
	pthread_join(p,NULL);
	pthread_join(c,NULL);
	return 0;
}
