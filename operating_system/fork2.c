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
		strcpy(arr,"this is child");
		n=3;
		
	}
	else
	{
		strcpy(arr,"this is parent");
		n=5;
		sleep(1);
	}
	for(j=0;j<n;j++)
		puts(arr);
	return 0;
}
