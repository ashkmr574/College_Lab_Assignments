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
}msg;
int main()
{
	int i,n,j,tmp;
	msg m;
	char b[100];
	int id=msgget(10050,0777);
	msgrcv(id,&m,sizeof(m.s),3,0);
	n=m.N;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if((m.s[j].roll)>(m.s[j+1].roll))
			{
				tmp=m.s[j].roll;
				m.s[j].roll=m.s[j+1].roll;
				m.s[j+1].roll=tmp;
				strcpy(b,m.s[j].name);
				strcpy(m.s[j].name,m.s[j+1].name);
				strcpy(m.s[j+1].name,b);
			}
		}
	}
	m.t=4;
	msgsnd(id,&m,sizeof(m.s),0);
	return 0;
}
