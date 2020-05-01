#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/un.h>
#include<arpa/inet.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
	int f2=open("FILEME.txt",O_WRONLY|O_CREAT);
	char p[100];
	struct stat sb;
	int size=1,l1;
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
	
	printf("recieving data from client\n");
	read(cid,(void*)&sb,sizeof(sb));
	chmod("FILEME.txt",sb.st_mode);
	while((l1=read(cid,(void*)p,sizeof(p)))>0)
	{
		write(2,(void*)p,l1);
		write(f2,(void*)p,l1);
	}
	close(sid);
	close(cid);
	close(f2);
	return 0;
}
