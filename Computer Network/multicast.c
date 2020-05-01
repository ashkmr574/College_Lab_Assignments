#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/un.h>
#include<arpa/inet.h>
#include<math.h>
#include<pthread.h>
pthread_t u1,u2;
typedef struct
{
	char a[1000];
}number;
int sid,cid;
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
    struct sockaddr_in p;
    long l=sizeof(p);
	while(1)
	{
		recvfrom(sid,(void*)&s2,sizeof(s2),0,(struct sockaddr*)&p,(socklen_t *)&l);
		puts(s2.a);
		
	}
}
int main()
{
	number s1,s2;
	int size=1;
	sid=socket(AF_INET,SOCK_DGRAM,0);
	//cid=socket(AF_INET,SOCK_DGRAM,0);
	c.sin_family=AF_INET;
	c.sin_addr.s_addr=inet_addr("225.0.0.22");
	c.sin_port=htons(27015);
	s.sin_family=AF_INET;
	s.sin_addr.s_addr=inet_addr("0.0.0.0");
	s.sin_port=htons(27015);
	setsockopt(sid,SOL_SOCKET,SO_REUSEADDR,(void*)&size,sizeof(int));
	bind(sid,(struct sockaddr*)&s,sizeof(s));
	struct ip_mreq m;
	m.imr_multiaddr.s_addr=inet_addr("225.0.0.22");
	m.imr_interface.s_addr=inet_addr("0.0.0.0");
	setsockopt(sid,IPPROTO_IP,IP_ADD_MEMBERSHIP,(void*)&m,sizeof(m));
	pthread_create(&u1,NULL,f1,NULL);
	pthread_create(&u2,NULL,f2,NULL);
	pthread_join(u1,NULL);
	pthread_join(u2,NULL);
	return 0;
}
