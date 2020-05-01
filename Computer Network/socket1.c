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
	number s1;
	int i,j,tmp;
	int sid=socket(AF_UNIX,SOCK_STREAM,0);
	struct sockaddr_un s,c;
	unlink("FILE1");
	strcpy(s.sun_path,"FILE1");
	s.sun_family=AF_UNIX;
	bind(sid,(struct sockaddr*)&s,sizeof(s));
	listen(sid,1);
	int l=sizeof(c);
	int cid=accept(sid,(struct sockaddr *)&c,&l);
	read(cid,(void*)&s1,sizeof(s1));
	printf("recieved data\n");
	for(i=0;i<s1.n;i++)
		{
			printf("%d\n",s1.a[i]);
			//printf("hello\n");
			
		}
	for(i=0;i<s1.n;i++)
	{
		for(j=0;j<(s1.n)-i-1;j++)
		{
			if((s1.a[j])>(s1.a[j+1]))
			{
				tmp=s1.a[j];
				s1.a[j]=s1.a[j+1];
				s1.a[j+1]=tmp;
			}
		}
	}
	printf("data after sorting\n");
	for(i=0;i<s1.n;i++)
		printf("%d\n",s1.a[i]);
	printf("data sent back to client\n");
	write(cid,(void*)&s1,sizeof(s1));
	close(sid);
	close(cid);
	return 0;
}
