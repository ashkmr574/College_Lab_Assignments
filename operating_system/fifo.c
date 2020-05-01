#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int pdrome(char a[])
{
   int f=0,i,j,k;
   k=strlen(a);
   j=k-1;
   for(i=0;i<(k/2);i++)
   {
	if(a[i]!=a[j])
	{
	    f=1;
	    break;
	 }
	 j--;
    }
    return f;
	
}
int main()
{
	char a[100];
	int f,l;
	mkfifo("fifo1",0777);
	mkfifo("fifo2",0777);
	int fd1= open("fifo1",0);
	int fd2= open("fifo2",1);
	while((l=read(fd1,(void*)a,sizeof(a)))>0)
	{
		printf("recieved string = %s\n",a);
		f=pdrome(a);
		write(fd2,(void*)&f,sizeof(int));
		printf("result sent back to server\n");
	}
	close(fd1);
	close(fd2);
	return 0;
}
