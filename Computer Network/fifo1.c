#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
	char a[250],b[65];
	int n, fd1, fd2,i;

	mkfifo("fifo1",0777);
	mkfifo("fifo2",0777);

	fd1=open("fifo1", O_WRONLY);
	fd2=open("fifo2", O_RDONLY);

	printf("Enter a binary number\n");
	scanf("%s",a);
	write(fd1,a,strlen(a)+1);
	
	read(fd2,b,sizeof(b));
	printf("Result Recieced\nCorresponding Hexadecimal number is = "); 
	for(i=strlen(b)-1;i>=0;i--)
		printf("%c",b[i]);
	printf("\n");
	close(fd1);
	close(fd2);
	return 0;
	
}
