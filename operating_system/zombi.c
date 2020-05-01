#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char arr[100];
	int n,j;
	int i=fork();
	if(i==0)
	{
		sleep(10);
		for(j=0;j<3;j++)
		printf("this is child and id =%d\n",getpid());
		n=3;
		
	}
	else
	{
		sleep(20);
		for(j=0;j<5;j++)
			printf("this is parent and id=%d\n",getppid());
		
	}
	system("ps -ax");
	return 0;
}
