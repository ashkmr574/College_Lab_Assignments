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
#define M 3
sem_t t;
pthread_t snd,ack1;
pthread_t *timeout;
struct sockaddr_in s;
int s1=0,sid;
int s2=0;
int w;
int ack[2];
typedef struct frame
{
	int seq;
	int data;
	
}frame;
frame *buf;
void* tm(void* a)
{
			    while(1)
			    {
			    	sleep(10);
					write(sid,&buf[(int)a],sizeof(buf[(int)a])),
					printf("Resent frame with sn = %d\t data = %d\n",buf[(int)a].seq,buf[(int)a].data);
				}
}
void* send1(void* a)
{
	while(1)
	{
				int p=rand()%100+1000;
				buf[s2%w].seq=s2%w;
				buf[s2%w].data=p;
				if(rand()%5)
					write(sid,&buf[s2%w],sizeof(buf[s2%w])),
					printf("Sent frame with sn = %d\t data = %d\n",buf[s2%w].seq,buf[s2%w].data);
				else
					printf("NOISY : Sent frame with sn = %d\t data = %d\n",buf[s2%w].seq,buf[s2%w].data);
				pthread_create(&timeout[s2%w],NULL,tm,(void*)(s2%w));
				s2=(s2+1)%w;
				if(s2<s1)
					s2+=w;
				sem_wait(&t);
	}
}
void* ackn(void* a)
{
	int t1,p;
	while( read(sid,ack,sizeof(ack)) >0)
	{
		//printf("%d %d %d %d\n",ack[0],ack[1],s1,s2);
		if(s2<s1)
			s2+=w;
		if(ack[1]<=(s2%w))
		{
			if(ack[1]<s1)
				ack[1]+=w;
		}
		if(ack[0]==1)
		{
			if((ack[1]>s1)&&(ack[1]<=s2))
			{
				printf("Received ack_frame with rn = %d\n",ack[1]%w);
				p=s1;
				while(p<ack[1])
				{
					pthread_cancel(timeout[s1]);
					s1=(s1+1)%w;
					p++;
					sem_post(&t);
				}
			}
			else
				printf("ACK or NAK is out of order\n");
		}
		else if((ack[0])==(-1))  //-1 means nak
		{
			if((ack[1]>=s1)&&(ack[1]<=s2))
			{
				printf("Received nak_frame with rn = %d\n",ack[1]);
				pthread_cancel(timeout[ack[1]]);
				write(sid,&buf[ack[1]],sizeof(buf[ack[1]]));
				printf("Resent frame with sn = %d\t data = %d\n",buf[ack[1]].seq,buf[ack[1]].data);
				pthread_create(&timeout[ack[1]],NULL,tm,(void*)ack[1]);
				
			}
			else
				printf("ACK or NAK is out of order\n");
		}
	}
}
int main()
{
	w=pow(2,M);
	buf=(frame *)malloc(w*sizeof(frame));
    sem_init(&t,0,w/2-1);
	timeout=(pthread_t*)malloc(w*sizeof(pthread_t));
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
