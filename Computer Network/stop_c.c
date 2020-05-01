#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
sem_t t;
pthread_t snd,ack1,timeout;
struct sockaddr_in s;
int buf[2];
int flag=1;
int flag2=0;
int sn=0,sid;
int ack;
void* tm(void* a)
{
			    while(1)
			    {
			    	sleep(3);
					int t1=(sn+1)%2;
					buf[0]=t1;
					write(sid,buf,sizeof(buf)),
					printf("Resent frame with sn = %d\t data = %d\n",buf[0],buf[1]);
				}
}
void* send1(void* a)
{
	while(1)
	{
		    flag2=0;
			printf("hi\n");
			int p=rand()%100+100;
			buf[0]=sn;
			buf[1]=p;
			if(rand()%4)
				write(sid,buf,sizeof(buf)),
				printf("Sent frame with sn = %d\t data = %d\n",buf[0],buf[1]);
	       else
		      printf("NOISY : Sent frame with sn = %d\t data = %d\n",buf[0],buf[1]);
			sn=(sn+1)%2;
			pthread_create(&timeout,NULL,tm,NULL);
			pthread_join(timeout,NULL);
			printf("bye\n");
			sem_wait(&t);
	}
}
void* ackn(void* a)
{
	while( read(sid,&ack,sizeof(ack)) >0)
	{
	    printf("hello\n");
		if(ack==sn)
		{
			printf("Received ack_frame with rn = %d\n",ack);
			flag2=1;
			sem_post(&t);
			pthread_cancel(timeout);
		}
	}
}
int main()
{
    sem_init(&t,0,0);
	sid=socket(AF_INET,SOCK_STREAM,0);
	s.sin_family=AF_INET;
	s.sin_port=htons(1234);
	s.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(sid,(struct sockaddr*)&s,sizeof(s));
	
	pthread_create(&snd,NULL,send1,NULL);
	pthread_create(&ack1,NULL,ackn,NULL);
	//pthread_create(&timeout,NULL,tm,NULL);
	pthread_join(snd,NULL);
	pthread_join(ack,NULL);
	//pthread_join(timeout,NULL);
	return 0;
}
