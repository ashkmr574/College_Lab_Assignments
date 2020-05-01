#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/un.h>
#include<arpa/inet.h>
#include<math.h>
#include<pthread.h>
typedef struct
{
	char a[1000];
}number;
int sid;
struct sockaddr_in s,c;
void* f1(void* a)
{
    number s1;
	while(1)
	{
		fgets(s1.a,1000,stdin);
		sendto(sid,(void*)&s1,sizeof(s1),0,(struct sockaddr*)&c,sizeof(c));
	}
}
void* f2(void* a)
{
    number s2;
    long l=sizeof(c);
	while(1)
	{
		recvfrom(sid,(void*)&s2,sizeof(s2),0,(struct sockaddr*)&c,(socklen_t *)&l);
		puts(s2.a);
	}
}
int main()
{
	number s1,s2;
	unsigned int a1,a2;
	int size=1;
	printf("Enter your port");
	scanf("%u",&a1);
	printf("Enter your friend's port");
	scanf("%u",&a2);
	sid=socket(AF_INET,SOCK_DGRAM,0);
	s.sin_family=AF_INET;
	s.sin_addr.s_addr=inet_addr("127.0.0.1");
	s.sin_port=htons(a1);
	c.sin_family=AF_INET;
	c.sin_addr.s_addr=inet_addr("127.0.0.1");
	c.sin_port=htons(a2);
	setsockopt(sid,SOL_SOCKET,SO_REUSEADDR,(void*)&size,sizeof(int));
	bind(sid,(struct sockaddr*)&s,sizeof(s));
	pthread_t u1,u2;
	pthread_create(&u1,NULL,f1,NULL);
	pthread_create(&u2,NULL,f2,NULL);
	pthread_join(u1,NULL);
	pthread_join(u2,NULL);
	return 0;
}
