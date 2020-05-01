#include<stdio.h>
int bsearch(int a[],int l,int h,int z)
{
    int m;m=0;
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
int main()
{
     int i,n,p,z;z=i=p=n=0;
     printf("Enter the number of terms\n");
     scanf("%d",&n);
     int a[n];
     printf("Enter the element one by one(sorted)\n");
     for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int l,h;
    l=0;h=n-1;
    printf("Enter the number to be searched\n");
    scanf("%d",&z);
    p=bsearch(a,l,h,z);
    if(a[p]==z)
        printf("Number found at %d position\n",(p+1));
    else
        printf("Number not found\n");
}
