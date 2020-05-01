#include<stdio.h>
#include<string.h>
int main()
{
char a[100];
int i,j,f=0;
printf("enter string\n");
gets(a);
i=0;
j=strlen(a)-1;
while(i<j)
{
if(a[i]!=a[j])
{
f=1;
break;
}
i++;
j--;
}
if(f==0)
printf("palindrome");
else
printf("not palindrome");
return 0;
}

