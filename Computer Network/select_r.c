#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<math.h>
#define M 3
struct sockaddr_in s,c;
int r1=0,r2,w;
typedef struct frame
{
	int seq;
	int data;
	
}frame;
frame *buf;
frame temp;
int *flag;
int ack[2];
int nak=0;
int main()
{
	w=pow(2,M);
	buf=(frame*)malloc(w*sizeof(frame));
	flag=(int*)calloc(w,sizeof(int));
	r2=w/2-1;
	int sid=socket(AF_INET,SOCK_STREAM,0);
	s.sin_family=AF_INET;
	s.sin_port=htons(1234);
	s.sin_addr.s_addr=inet_addr("127.0.0.1");
	int l=1;
	setsockopt(sid,SOL_SOCKET,SO_REUSEADDR,(void*)&l,sizeof(int));
	bind(sid,(struct sockaddr*)&s,sizeof(s));
	listen(sid,1);
	l=sizeof(c);
	int cid=accept(sid,(struct sockaddr *)&c,&l);
	while(1)
	{
		if((read(cid,(void*)&temp,sizeof(temp)))>0)
		{
			sleep(1);
			if((temp.seq)<=(r2%w))
			{
				if((temp.seq)<r1)
					temp.seq=(temp.seq)+w;
			}
			if(((temp.seq)>=r1)&&((temp.seq)<=r2))
			{
				temp.seq=(temp.seq)%w;
				printf("Frame received with seq no %d and data %d\n",temp.seq,temp.data);
				flag[temp.seq]=1;
				buf[temp.seq].seq=temp.seq;
				buf[temp.seq].data=temp.data;
				if(temp.seq==r1)
				{
					int l=r1;
					while(flag[l]==1)
					{
						flag[l]=0;
						printf("Frame sent to network layer with seq no %d and data %d\n",buf[l].seq,buf[l].data);
						l=(l+1)%w;
						r1=(r1+1)%w;
						ack[0]=1;
						ack[1]=l;
						if(rand()%5)
						{
							write(cid,ack,sizeof(ack));
							printf("Ack sent with ackno %d\n",ack[1]);
						}	
						else
							printf("Noissy Ack sent with ackno %d\n",ack[1]);
						r2=(r2+1)%w;
						if(r2<r1)
							r2=r2+w;
						nak=0;
					}
				}
				else
				{
					if(!nak)
					{
						ack[0]=-1;
						ack[1]=r1;
						write(cid,ack,sizeof(ack));
						printf("NAK sent with Nakno %d\n",ack[1]);
						nak=1;
					}
				}
			}
			else
			{
				printf("Frame out of order, hence discarded\n");
				ack[0]=1;
				ack[1]=r1;
				if(rand()%5)
				{
					write(cid,ack,sizeof(ack));
					printf("Ack sent with ackno %d\n",ack[1]);
				}	
				else
					printf("Noissy Ack sent with ackno %d\n",ack[1]);
				
			}
		}
	}
	return 0;
}
