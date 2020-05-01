#include<stdio.h>
void main()
{

    int i,j,k,l=0,n;
    printf("enter the no.");
    scanf("%d",&n);
    for(i=1;i<=(n/2)+1;i++)
    {

        for(j=1;j<=i;j++)
        printf("%d",++l);
        printf("\n");
    }
        for(k=n/2;k>=1;k--)
        {

            for(j=1;j<=k;j++)
                printf("%d",++l);
                printf("\n");

        }
        return 0;

}
