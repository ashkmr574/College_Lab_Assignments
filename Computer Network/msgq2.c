#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
typedef struct 
{
	long int t;
	char a[100];
}mg;
int main()
{
	mg s,s1;
	int id=msgget(12346,0777);
	msgrcv(id,&s,sizeof(s.a),2,0);
	printf("recieved host name= %s\n",s.a);
	sethostname(s.a,strlen(s.a));
	//gethostname(s1.a,sizeof(s1.a));
	//printf("hostname = %s\n",s1.a);
	s1.t=1;
	strcpy(s1.a,"Y");
	msgsnd(id,&s1,strlen(s1.a)+1,0);
	return 0;
	
}
