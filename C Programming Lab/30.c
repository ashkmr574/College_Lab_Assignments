#include<stdio.h>

void dec_hex(long int num)
{
long int rem[50],i=0,length=0;
while(num>0)
	{
	rem[i]=num%16;
	num=num/16;
	i++;
	length++;
	}

printf("Hexadecimal number : ");
for(i=length-1;i>=0;i--)
  {
	switch(rem[i])
	{
	case 10:
		printf("A");
		break;
	case 11:
		printf("B");
		break;
	case 12:
		printf("C");
		break;
	case 13:
		printf("D");
		break;
	case 14:
		printf("E");
		break;
	case 15:
		printf("F");
		break;
	default :
		printf("%ld",rem[i]);
	}
     }
}
int main()
{
long int num;
printf("Enter the Decimal number : ");
scanf("%ld",&num);
dec_hex(num);
return 0;
}



