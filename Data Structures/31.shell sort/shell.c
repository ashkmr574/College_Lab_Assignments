#include<stdio.h>
void shell(int a[],int n)
{
    int i,j,g,z,t;
    g=n/2;
    while(g>0)
    {
        for(i=g;i<n;i++)
        {
            z=a[i];
            for(j=i-g;j>=0&&z<a[j];j=j-g)
              {
                    t=a[j];
                    a[j]=a[j+g];
                    a[j+g]=t;
              }
        }
        a[j+g]=z;
        g=g/2;
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
    shell(a,n);
    printf("sotred array is\t");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}
