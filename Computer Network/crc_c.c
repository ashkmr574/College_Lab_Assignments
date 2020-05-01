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
	char b[100];
}number;
int main()
{
	number s1,s2;
	int i;
	int sid=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in s;
	s.sin_family=AF_INET;
	s.sin_addr.s_addr=inet_addr("127.0.0.1");
	s.sin_port=htons(1237);
	int p=connect(sid,(struct sockaddr*)&s,sizeof(s));
	printf("%d\n",p);
	if(p<0)
	{
		printf("Unable to connect\n");
		return 0;
	}
	while(1)
	{
		printf("Enter the dataword\n");
		scanf("%s",s1.a);
		printf("Enter the divisor\n");
		scanf("%s",s1.b);
		//printf("%s %s\n",s1.a,s1.b);
		if(strcmp(s1.a,"0")==0)
		{
			break;
		}
		int l4=write(sid,(void*)&s1,sizeof(s1));
		//printf("%d\n",l4);
		int l2=read(sid,(void*)&s2,sizeof(s2));
		printf("Recieved codeword = %s\n",s2.a);
	}
	close(sid);
	return 0;
}
