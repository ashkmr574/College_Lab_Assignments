#include<stdio.h>
int main()
{
char a[100];
int count=0,i,j=0,p=0,k=0;
printf("enter a sentence  ");
gets(a);
for(i=0;a[i]!='\0';i++)
{
    if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'||a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
        j++;
}
printf("no of vowels=%d",j);
return 0;
}
