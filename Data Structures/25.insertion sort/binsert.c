#include<stdio.h>
int bsearch(int a[],int l,int h,int z)
{
    int m;
    if(l<=h)
    {
        m=(l+h)/2;
        if(a[m]==z)
            return m;
        else if(z<a[m])
            return bsearch(a,l,m-1,z);
        else
            return bsearch(a,m+1,h,z);
    }
    return h;
}
void binsertion(int a[],int n)
{
    int i,j,z,p;
    for(i=1;i<n;i++)
    {
        z=a[i];
        p=bsearch(a,0,i-1,z);
        for(j=i-1;j>=(p+1);j--)
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
    binsertion(a,n);
    printf("sotred array is\t");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}

