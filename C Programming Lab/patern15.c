#include<stdio.h>
int main()
{
    int i,j,l,k;
    for(i=5;i>=1;i--)
    {

        for(j=4;j>=i;j--)
            printf(" ");
        for(k=1;k<=i;k++)
            printf("%d",k%2);
        for(l=i-1;l>=1;l--)
            printf("%d",l%2);
        printf("\n");
    }
    return 0;
}
