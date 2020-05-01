#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/un.h>
#include<arpa/inet.h>
#include<math.h>
typedef struct
{
	char a[1000];
}number;
number getcode(number s1)
{
	int l=strlen(s1.a);
	int i,r,n,p,j,k,c;
	number s2;
	for(i=1;;i++)
	{
		if((l+i)<=pow(2,i))
		{
			r=i;
			n=l+r;
			break;
		}
	}
	p=0;
	for(i=0,j=0;i<n;i++)
	{
		if((i+1)==pow(2,p))
			p++;
		else
			s2.a[i]=s1.a[j++];	
	}
	for(i=0;i<n;i++)
		printf("bit=%c\n",s2.a[i]);
	printf("\n");
	for(i=0;i<r;i++)
	{
		p=pow(2,i);
		c=0;
		for(j=p-1;j<n;j=j+2*p)
		{
			for(k=j,l=0;l<p &&k<n;k++,l++)
			    if(s2.a[k]=='1')
			    		c++;
		}
		if(c%2==0)
		      s2.a[p-1]='0';
		    else
		    	s2.a[p-1]='1';	
	}
	return s2;
}
int main()
{
	number s1,s2;
	int size=1;
	int sid=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in s,c;
	s.sin_family=AF_INET;
	s.sin_addr.s_addr=inet_addr("127.0.0.1");
	s.sin_port=htons(1237);
	setsockopt(sid,SOL_SOCKET,SO_REUSEADDR,(void*)&size,sizeof(int));
	bind(sid,(struct sockaddr*)&s,sizeof(s));
	//listen(sid,1);
	long l=sizeof(c);
	while(recvfrom(sid,(void*)&s1,sizeof(s1),0,(struct sockaddr*)&c,(socklen_t *)&l))
	{
		printf("recieved data\n");
		printf("%s\n",s1.a);
		s2=getcode(s1);
		printf("data sent back to client\n");
		sendto(sid,(void*)&s2,sizeof(s2),0,(struct sockaddr*)&c,sizeof(c));
	}
	close(sid);
	return 0;
}
