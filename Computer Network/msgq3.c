#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
struct student
{
	char name[40];
	int roll;
};
typedef struct 
{
	long t;
	int N;
	struct student s[100];
}ms;
void print(ms msg,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%s %d\n",msg.s[i].name,msg.s[i].roll);
	}
}
int main()
{
	ms msg,mn,mn1;
	int i,n;
	int id=msgget(10050,0777|IPC_CREAT);
	printf("Enter number of students\n");
	scanf("%d",&n);
	printf("Enter the details of student one by one\n");
	for(i=0;i<n;i++)
	{
		printf("Enter name\n");
		scanf("%s",msg.s[i].name);
		printf("Enter roll number\n");
		scanf("%d",&msg.s[i].roll);
	}
	msg.t=1;
	msg.N=n;
	printf("sending message to process 2\n");
	msgsnd(id,&msg,sizeof(msg.s),0);
	msg.t=3;
	printf("sending message to process 3\n");
	msgsnd(id,&msg,sizeof(msg.s),0);
	printf("recieved result from process 2\nlist of student sorted according to name\n");
	msgrcv(id,&mn,sizeof(mn.s),2,0);
	for(i=0;i<mn.N;i++)
		printf("%s %d\n",mn.s[i].name,mn.s[i].roll);
	printf("recieved result from process 3\nlist of student sorted according to roll number\n");
	msgrcv(id,&mn1,sizeof(mn1.s),4,0);
	for(i=0;i<mn1.N;i++)
		printf("%s %d\n",mn1.s[i].name,mn1.s[i].roll);
	return 0;	
}
