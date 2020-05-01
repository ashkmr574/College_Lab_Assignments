#include<stdio.h>
int main()
{

    int n,i,j;
    printf("enter the number");
    scanf("%d",&n);
    printf("prime nos are\n");
    for(i=1;i<=n;i++)
    {
        for(j=2;j<=i;j++)
        {
            if(j<=i-1)
            {
                if(i%j==0)
                    break;

            }
            else
                printf("%2d\n",i);

        }
    }
}
