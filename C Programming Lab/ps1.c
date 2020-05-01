#include<stdio.h>
int main()
{
char s[]="computer";
int i,j;
for(i=8;i>0;i--)
{
    for(j=0;j<i;j++)
        printf("%c",s[j]);
    printf("\n");
}
return 0;
}
