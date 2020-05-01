#include<stdio.h>
int main()
{
char a[100],b[100];
int i,j;
printf("enter two strings\n");
gets(a);
gets(b);
i=0;
j=0;
while((a[i]!='\0')&&(b[j]!='\0'))
{
if(a[i]==b[j])
{
i++;
j++;
}
else if(a[i]<b[j])
{
printf("2nd is greater");
break;
}
else
{
printf("1st is greater");
break;
}
}
if(a[i]=='\0'&&b[j]=='\0')
printf("equal");
return 0;
}
