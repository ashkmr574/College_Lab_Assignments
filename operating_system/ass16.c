#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int k=0;
void f(int i)
{
	printf("the signal that stopped the process is %d\n",i);
	signal(SIGINT,SIG_DFL);
	k=100;
}
int main()
{
	int i;
	i=fork();
	if(i!=0)
	{
		signal(SIGINT,f);
		while(1)
		{
			if(k==100)
				break;
			printf("Hi.......................\n");
			sleep(1);
		}
	}
	else
	{
		sleep(5);
		printf("Child sending alarm\n");
		kill(i,SIGINT);
	}
	return 0;

}
