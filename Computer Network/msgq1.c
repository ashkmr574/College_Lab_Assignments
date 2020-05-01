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
	int id=msgget(12346,0777|IPC_CREAT);
	//printf("%d\n",id);
	gethostname(s1.a,sizeof(s1.a));
	printf("current hostname = %s\n",s1.a);
	printf("Enter the host name\n");
	scanf("%s",s.a);
	s.t=2;
	msgsnd(id,&s,sizeof(s.a),0);
	//printf("%s %d\n",s.a,s.t);
	msgrcv(id,&s,sizeof(s.a),1,0);
	gethostname(s1.a,sizeof(s1.a));
	printf("changed hostname = %s\n",s1.a);
	return 0;
	
}
