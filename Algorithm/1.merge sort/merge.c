#include<stdio.h>
void merge(int a[],int l,int h)
{
    int m,j,k,i,b[100];
    if(l<h)
    {
        m=(l+h)/2;
        merge(a,l,m);
        merge(a,m+1,h);
        for(i=l,j=m+1,k=l;i<=m&&j<=h;k++)
        {
            if(a[i]<a[j])
                b[k]=a[i++];
            else
                b[k]=a[j++];
        }
        while(i<=m)
            b[k++]=a[i++];
        while(j<=h)
            b[k++]=a[j++];
        for(k=l;k<=h;k++)
            a[k]=b[k];
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
    merge(a,0,n-1);
    printf("sotred array is\t");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}
