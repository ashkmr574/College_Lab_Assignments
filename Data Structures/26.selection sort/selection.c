#include<stdio.h>
void selection_sort(int a[],int n)
{
    int i,j,t,min,loc;
    min=a[0];
    for(i=0;i<n;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                loc=j;
            }
        }
        if(loc!=i)
        {
            t=a[i];
            a[i]=a[loc];
            a[loc]=t;
        }
    }
}
int main()
{
    int a[100];
    int i,n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    printf("enter array element one by one\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    selection_sort(a,n);
    printf("sotred array is\t");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}

