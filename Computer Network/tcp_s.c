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
number bitstuff(number s)
{
	int count=0;
	int i,j;
	number s2;
	for(i=0,j=0;s.a[i]!='\0';i++)
	{
		s2.a[j++]=s.a[i];
		if(s.a[i]=='1')
			count++;
		else
			count=0;
		if(count==5)
		{
			s2.a[j++]='0';
			count=0;
		}
	}
	return s2;
}
int main()
{
	number s1,s2;
	int size=1;
	int sid=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in s,c;
	s.sin_family=AF_INET;
	s.sin_addr.s_addr=inet_addr("127.0.0.1");
	s.sin_port=htons(1235);
	setsockopt(sid,SOL_SOCKET,SO_REUSEADDR,(void*)&size,sizeof(int));
	bind(sid,(struct sockaddr*)&s,sizeof(s));
	listen(sid,1);
	int l=sizeof(c);
	int cid=accept(sid,(struct sockaddr *)&c,&l);
	read(cid,(void*)&s1,sizeof(s1));
	printf("recieved data\n");
	printf("%s\n",s1.a);
	s2=bitstuff(s1);
	printf("data sent back to client\n");
	write(cid,(void*)&s2,sizeof(s2));
	close(sid);
	close(cid);
	return 0;
}
