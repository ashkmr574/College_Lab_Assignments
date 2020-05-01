#include<stdio.h>
int main()
{
char a[100];
int count=0,i,j=0,p=0,k=0;
printf("enter a sentence  ");
gets(a);
for(i=0;a[i]!='\0';i++)
{
    if((a[i]==' ')&&(a[i+1]!=' '))
    count++;
}
count+=1;
printf("no of words=%d\n",count);
for(i=0;a[i]!='\0';i++)
{
    if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'||a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
        j++;
        else if(a[i]==' ')
        p++;
        else
            k++;
}
printf("no of vowels=%d\n",j);
printf("no of digits=%d",j+k);
return 0;
}
