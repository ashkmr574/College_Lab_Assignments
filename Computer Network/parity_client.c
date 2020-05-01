#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/un.h>
#include<arpa/inet.h>
typedef struct
{
	char a[1000];
}number;
number addparity(number s1)
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
	//printf("%d\n",count);
	if((count%2)!=0)
		s2.a[i++]='1';
	else
		s2.a[i++]='0';
	s2.a[i]='\0';
	return s2;
}
int main()
{
	number s1,s2;
	int i,msg;
	int sid=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in s;
	s.sin_family=AF_INET;
	s.sin_addr.s_addr=inet_addr("127.0.0.1");
	s.sin_port=htons(1237);
	int p=connect(sid,(struct sockaddr*)&s,sizeof(s));
	//printf("%d\n",p);
	if(p<0)
	{
		printf("Unable to connect\n");
		return 0;
	}
	printf("Enter the bit stream\n");
	scanf("%s",s1.a);
	s2=addparity(s1);
	write(sid,(void*)&s2,sizeof(s1));
	int l2=read(sid,(void*)&msg,sizeof(s2));
	if(msg==1)
		printf("server says there is error\n");
	else
		printf("server says there is no error\n");
	close(sid);
	return 0;
}
