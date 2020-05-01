#include<stdio.h>
void insertion_sort(int a[],int n)
{
    int i,j,z;
    for(i=1;i<n;i++)
    {
        z=a[i];
        for(j=i-1;j>=0&&a[j]>z;j--)
            a[j+1]=a[j];
        a[j+1]=z;
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
    insertion_sort(a,n);
    printf("sotred array is\t");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}



