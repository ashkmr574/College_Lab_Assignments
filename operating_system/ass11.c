#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char arr[100];
	int n,j;
	int i=fork();
	system("ps -ax");
	if(i==0)
	{
		for(j=0;j<3;j++)
		printf("this is child and id =%d\n",getpid());
		sleep(20);
		n=3;
		
	}
	else
	{
		for(j=0;j<5;j++)
			printf("this is parent and id=%d\n",getppid());
		sleep(10);
	}
	return 0;
}
