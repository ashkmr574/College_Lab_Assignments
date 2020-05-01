#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<math.h>
#define M 2
sem_t t;
pthread_t snd,ack1,timeout;
struct sockaddr_in s;
int s1=0,sid;
int s2=0;
int w;
int ack;
typedef struct frame
{
	int seq;
	int data;
	
}frame;
frame *buf;
void* tm(void* a)
{
	int t1,p;
			    while(1)
			    {
			    	sleep(5);
					p=s1;
					while(p<s2)
					{
						buf[p%w].seq=p%w;
						write(sid,&buf[p%w],sizeof(buf[p%w])),
						printf("Resent frame with sn = %d\t data = %d\n",buf[p%w].seq,buf[p%w].data);
						p++;
					}
				}
}
void* send1(void* a)
{
	while(1)
	{
			//while((s1-s2)<w)
			//{
				int p=rand()%100+1000;
				s2=s2%w;
				buf[s2].seq=s2;
				buf[s2].data=p;
				if(rand()%5)
					write(sid,&buf[s2],sizeof(buf[s2])),
					printf("Sent frame with sn = %d\t data = %d\n",buf[s2].seq,buf[s2].data);
				else
					printf("NOISY : Sent frame with sn = %d\t data = %d\n",buf[s2].seq,buf[s2].data);
				s2=(s2+1)%w;
				if(s2<s1)
					s2=s2+w;
				if(pthread_kill(timeout,0)==0);
				else
					pthread_create(&timeout,NULL,tm,NULL);
				sem_wait(&t);
			//}
	}
}
void* ackn(void* a)
{
	int t1,p;
	while( read(sid,&ack,sizeof(ack)) >0)
	{
		printf("%d %d %d\n",s1,s2,ack);
		if(ack<=(s2%w))
		{
			if(ack<=s1)
				ack=ack+w;
		}
		if((ack>s1)&&(ack<=s2))
		{
			
			printf("Received ack_frame with rn = %d\n",ack%4);
			p=s1;
			while(p<ack)
			{
				s1=(s1+1)%w;
				p++;
				sem_post(&t);
			}
			if(s1==s2)
				pthread_cancel(timeout);
		}
	}
}
int main()
{
	w=pow(2,M);
	buf=(frame *)malloc(w*sizeof(frame));
    sem_init(&t,0,w-2);
	sid=socket(AF_INET,SOCK_STREAM,0);
	s.sin_family=AF_INET;
	s.sin_port=htons(1234);
	s.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(sid,(struct sockaddr*)&s,sizeof(s));
	
	pthread_create(&snd,NULL,send1,NULL);
	pthread_create(&ack1,NULL,ackn,NULL);
	pthread_join(snd,NULL);
	pthread_join(ack1,NULL);
	return 0;
}
