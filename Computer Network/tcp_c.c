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
int main()
{
	number s1,s2;
	int i;
	int sid=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in s;
	s.sin_family=AF_INET;
	s.sin_addr.s_addr=inet_addr("127.0.0.1");
	s.sin_port=htons(1235);
	connect(sid,(struct sockaddr*)&s,sizeof(s));
	printf("Enter the bit stream\n");
	scanf("%s",s1.a);
	write(sid,(void*)&s1,sizeof(s1));
	int l2=read(sid,(void*)&s2,sizeof(s2));
	printf("result recieved from server\n");
	printf("%s\n",s2.a);
	close(sid);
	return 0;
}
