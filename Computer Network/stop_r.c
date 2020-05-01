#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<stdlib.h>
struct sockaddr_in s,c;
int buf[2];
int r=0;
int main()
{
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
		read(cid,(void*)buf,sizeof(buf));
		sleep(1);
		if(buf[0]==r)
		{
			printf("Frame received with frame no %d and data %d\n",r,buf[1]);
			r=(r+1)%2;
		}
		else
		{
			printf("Frame out of order, hence discarded\n");
		}
		if(rand()%5)
		{
			write(cid,&r,sizeof(r));
			printf("Ack sent with ackno %d\n",r);
		}
		else
			printf("Noissy Ack sent wirh ackno %d\n",r);
	}
	return 0;
}
