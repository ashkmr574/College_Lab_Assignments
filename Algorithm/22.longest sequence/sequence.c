#include<stdio.h>
int calculate(int a[],int s,int n)
{
    int length,i,max=0;
    for(i=s;i<n;i++)
    {
        if(a[i]>a[s-1])
        {
            length = 1+calculate(a,i+1,n);
            if(length>max)
                max=length;
        }
    }
    return max;
}
int main()
{
    int n,i,max,l;max=l=0;
    printf("Enter the number of integers\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the integers\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        l=1+calculate(a,i+1,n);
        if(l>max)
            max=l;
    }
    printf("Length = %d",max);
    return 0;
}
