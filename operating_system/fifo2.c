#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char a[100];
	int f,l=1,c;
	int fd1= open("fifo1",1);
	int fd2= open("fifo2",0);
	while(l)
	{
		printf("1.check\n2.exit\n");
		scanf("%d",&c);
		getchar();
		switch(c)
		{
			case 1:printf("Enter the string\n");
			       scanf("%s",a);
			       write(fd1,(void*)a,sizeof(a));
			       read(fd2,(void*)&f,sizeof(int));
			       if(f==0)
	                          printf("Palindrome\n",f);
	                       else
	                          printf("Not Palindrome\n",f);
                               break;
			case 2: l=0;
				break;
			default:printf("Invalid input\n");
		}
	}
	close(fd1);
	close(fd2);
	return 0;
}
