#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/un.h>
typedef struct
{
	int n;
	int a[100];
}number;
int main()
{
	number s1,s2;
	int i;
	int sid=socket(AF_UNIX,SOCK_STREAM,0);
	struct sockaddr_un s;
	strcpy(s.sun_path,"FILE1");
	s.sun_family=AF_UNIX;
	connect(sid,(struct sockaddr*)&s,sizeof(s));
	printf("Enter no of elements\n");
	scanf("%d",&s1.n);
	printf("Enter element one by one\n");
	for(i=0;i<s1.n;i++)
		scanf("%d",&s1.a[i]);
	write(sid,(void*)&s1,sizeof(s1));
	int l2=read(sid,(void*)&s2,sizeof(s2));
	printf("result recieved from server\n");
	for(i=0;i<s2.n;i++)
		printf("%d\n",s2.a[i]);
	close(sid);
	return 0;
}
