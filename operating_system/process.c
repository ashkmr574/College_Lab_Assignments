#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("Process is running");
	system("ps -ax");
	return 0;
}
