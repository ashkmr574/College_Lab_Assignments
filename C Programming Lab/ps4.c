#include<stdio.h>
int main()
{
char s[]="computer";
int i,j,k;
for(i=8;i>0;i--)
{
    for(k=7;k>=i;k--)
        printf(" ");
    for(j=0;j<i;j++)
        printf("%c",s[j]);
    printf("\n");
}
return 0;
}
