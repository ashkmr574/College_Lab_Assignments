#include<stdio.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int power(int n,int k)
{
	int f=1,i;
	for(i=1;i<=k;i++)
	{
		f=f*n;
	}
	return f;
}

int main()
{
	char c[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	char b[250],temp[4];
	char d[65];
	int i,n,fd1,fd2,j,sum,k,l=0;

	fd1=open("fifo1", O_RDONLY);
	fd2=open("fifo2", O_WRONLY);

	read(fd1,b,sizeof(b));
	
	for(i=strlen(b)-1;i>=0;)
	{
		memset(temp,'\0',sizeof(temp));
		sum=0;
		for(j=0;j<4;j++)
		{
			if(i>=0)
			{
				temp[j]=b[i--];
			}
			else
			break;
		}
		for(k=0;k<j;k++)
		{
			sum+=((temp[k]-48)*(1<<k));
		}
		
		d[l++]=c[sum];
	}
	
	write(fd2,d,strlen(d)+1);
	close(fd1);
	close(fd2);
	
	return 0;
}
