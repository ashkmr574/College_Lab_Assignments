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
	int i;
	msg m;
	int id=msgget(10050,0777);
	msgrcv(id,&m,sizeof(m.s),1,0);
	qsort(m.s,m.N,sizeof(struct student),strcmp);
	m.t=2;
	msgsnd(id,&m,sizeof(m.s),0);
	return 0;
}
