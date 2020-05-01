#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/un.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/un.h>
#include<arpa/inet.h>
#include<pthread.h>
typedef struct
{
	char a[1000];
}number;
int sid;
int checkparity(number);

void* f(void * a)
{
	struct sockaddr_in c;
	number s1,s2;
	//printf("hello\n");
	int l=sizeof(c);
	int cid=accept(sid,(struct sockaddr *)&c,&l);
	read(cid,(void*)&s1,sizeof(s1));
	printf("recieved data\n");
	printf("%s\n",s1.a);
	sleep(1);
	int ans=checkparity(s1);
	printf("result sent back to client\n");
	write(cid,(void*)&ans,sizeof(s2));	
	close(cid);
}
int checkparity(number s1)
{
	number s2;
	int i;
	int count=0;
	for(i=0;s1.a[i]!='\0';i++)
	{
		if(s1.a[i]=='1')
			count++;
		s2.a[i]=s1.a[i];
	}
	if((count%2)!=0)
		return 1;
	else
		return 0;
}
int main()
{
	pthread_t p[4];
	int size=1,i;
	sid=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in s,c;
	s.sin_family=AF_INET;
	s.sin_addr.s_addr=inet_addr("127.0.0.1");
	s.sin_port=htons(1237);
	setsockopt(sid,SOL_SOCKET,SO_REUSEADDR,(void*)&size,sizeof(int));
	bind(sid,(struct sockaddr*)&s,sizeof(s));
	listen(sid,4);
	for(i=0;i<4;i++)
		pthread_create(&p[i],NULL,f,NULL);
	for(i=0;i<4;i++)
		pthread_join(p[i],NULL);
	close(sid);
	return 0;
}

