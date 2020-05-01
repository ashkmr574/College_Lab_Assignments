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
#include<math.h>
typedef struct
{
	char a[1000];
	char b[100];
}number;
int sid;
number add_crc(number);
void* f(void * a)
{
	struct sockaddr_in c;
	number s1,s2;
	//printf("hello\n");
	int l=sizeof(c);
	int cid=accept(sid,(struct sockaddr *)&c,&l);
	//printf("%d\n",cid);
	while((l=read(cid,(void*)&s1,sizeof(s1)))>0)
	{
		printf("recieved data\n");
		printf("%s\n%s\n",s1.a,s1.b);
		if(strcmp(s1.a,"0")==0)
		{
	   		break;
	  	}
		sleep(1);
		number ans=add_crc(s1);
		printf("Resultant codeword=%s\n",ans.a);
		printf("result sent back to client\n");
		write(cid,(void*)&ans,sizeof(s2));
	}	
	close(cid);
}
number add_crc(number s1)
{
	number s2;
	char b[50];
	int a,b1,i,l1,l2,j,y,k;
	l1=strlen(s1.b);
	l2=strlen(s1.a);
	for(i=l2,j=1;j<l1;j++,i++)
		s1.a[i]='0';
	s1.a[i]='\0';
	printf("%s %s\n",s1.a,s1.b);
	for(i=0;i<l1;i++)
		b[i]=s1.a[i];
	b[i]='\0';
	y=l2-1;
	k=l1;
	while(y>0)
	{
		if(b[0]=='1')
			for(i=0;i<l1;i++)
			{
				b[i]=48+((b[i]-'0')^(s1.b[i]-'0'));
				//printf("%c\n",b[i]);
			}
		for(i=0;i<l1-1;i++)
			b[i]=b[i+1];
		b[i++]=s1.a[k];
		k++;
		b[i]='\0';
		//puts(b);
		y--;
		
	}
	for(i=l2,j=1;j<l1;j++,i++)
		s1.a[i]=b[j];
	s1.a[i]='\0';
	return s1;
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

