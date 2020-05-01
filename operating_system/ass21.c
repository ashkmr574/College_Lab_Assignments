#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define N 5
sem_t mutex;
sem_t s[N];
int arr[]={0,1,2,3,4};
int state[N];
void test(int num)
{
    int left,right;
    left=(num+4)%N;
    right=(num+1)%N;
    if((state[num]==1)&&(state[left]!=2)&&(state[right]!=2))
    {
        state[num]=2;
        printf("Philosopher %d takes fork %d and %d\n",num+1,left+1,num+1);
        printf("Philosopher %d is eating\n",num+1);
        sem_post(&s[num]);	
    }
}
void take_fork(int num)
{
   	sem_wait(&mutex);
        state[num]=1;
        printf("Philosopher %d is hungary and ready to eat\n",num+1);
        test(num);
        sem_post(&mutex);
        sem_wait(&s[num]);
       sleep(2);       
}
void put_fork(int num)
{
	sem_wait(&mutex);
        int left,right;
        left=(num+4)%N;
        right=(num+1)%N;
        state[num]=0;
        printf("Philosopher %d putting fork %d and %d down\n",num+1,left+1,num+1);
        test(left);
        test(right);
        sem_post(&mutex);
}
void* F(void* a)
{
	while(1)
	{
	    int* i=a;
	    take_fork(*i);
            sleep(1);
            put_fork(*i);
        }
}
int main()
{
      pthread_t th[N];
      int i;
      sem_init(&mutex,0,1);
      for(i=0;i<N;i++)
	  sem_init(&s[i],0,0);
      for(i=0;i<N;i++)
      {
	   pthread_create(&th[i],NULL,F,&arr[i]);
           printf("Philosopher %d is thinking\n",i+1);
      }
      for(i=0;i<N;i++)
		pthread_join(th[i],NULL);
      return 0;
}

