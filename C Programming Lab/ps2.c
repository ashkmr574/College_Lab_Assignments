#include<stdio.h>
int main()
{
char s[]="hello";
int i,j,k;
for(i=0;i<5;i++)
{
    for(j=0;j<=i;j++)
        printf("%c",s[j]);
    printf("\n");
}
for(i=4;i>0;i--)
{
    for(j=0;j<i;j++)
        printf("%c",s[j]);
    printf("\n");
}

return 0;
}
