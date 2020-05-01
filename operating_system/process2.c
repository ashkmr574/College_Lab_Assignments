#include<stdio.h>
#include<unistd.h>
int main()
{
	execlp("ps","ps","-ax",0);
	return 0;
}
