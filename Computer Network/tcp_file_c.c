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
	int i,l;
	struct stat sb;
	char file[100],p[512];
	int sid=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in s;
	s.sin_family=AF_INET;
	s.sin_addr.s_addr=inet_addr("127.0.0.1");
	s.sin_port=htons(1235);
	connect(sid,(struct sockaddr*)&s,sizeof(s));
	//printf("Enter the file name");
	//scanf("%s",file);
	int f1=open("abc.txt",O_RDONLY);
	fstat(f1,&sb);
	write(sid,(void*)&sb,sizeof(sb));
	printf("sending file to server\n");
	while(l=read(f1,(void*)p,512))
	{
		write(2,(void*)p,l);
		write(sid,(void*)p,l);
	}
	close(f1);	
	close(sid);
	return 0;
}
