#include<stdio.h>
void quick(int a[],int s,int e)
{
    int p,d,u,t,m;
    m=(s+e)/2;
    p=a[m];
    d=s;
    u=e;
    while(d<u)
    {
        while(a[u]>p&&u>s)
            u--;
        while(a[d]<p&&d<e)
            d++;
        if(d<u)
        {
            t=a[u];
            a[u]=a[d];
            a[d]=t;
        }
        //for(i=0;i<6;i++)
          //  printf("%d ",a[i]);
        //printf("\n");
        if(a[d]==a[u])
            break;
    }
    //a[s]=a[u];
    //a[u]=p;
    //printf("%d %d\n",u,d);
    if(u>s)
        quick(a,s,u-1);
    if(e>u)
        quick(a,u+1,e);
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
    quick(a,0,n-1);
    printf("sotred array is\t");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
