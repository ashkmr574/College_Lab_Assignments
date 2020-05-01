#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
   int f,n;
   int p[2];
   pipe(p);
   f=fork();
   if(f==0)
   { 
	while(1)
	{
		read(p[0],&n,sizeof(int));
                if(((n%4==0)&&(n%100!=0))||((n%100==0)&&(n%400==0)))
			printf("Leap Year\n");
		else
			printf("Not a leap year\n");
	}
   }
   else
   {
	while(1)
	{
                printf("Enter a year\n");
                scanf("%d",&n);
		write(p[1],&n,sizeof(int));
		sleep(5);
	}
   }
   return 0;
}
