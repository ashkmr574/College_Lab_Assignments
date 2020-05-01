#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,j,i,f=0;
    printf("enter the size of matrix\n");
    scanf("%d",&n);
    int a[n][n];
    printf("enter the elements of matrix one by one\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                f=1;
                break;
            }
        }
    }
    if(f==1)
        printf("not lower triagular matrix\n");
    else
        printf("lower triangular matrix\n");
    return 0;
}
