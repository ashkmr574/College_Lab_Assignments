#include<stdio.h>
int p[40][10],d[40];
int fact(int num)
{
    int f=1,i;
    if(num!=0)
        for(i=1;i<=num;i++)
            f=f*i;
    return f;
}
void perm(int list[],int k,int m)
{
    int i,temp;
    static r=0;
    if(k==m)
    {
        for(i=0;i<=m;i++)
            p[r][i+1]=list[i];
        r++;
    }
    else
    {
            for(i=k;i<=m;i++)
            {
                temp=list[k];
                list[k]=list[i];
                list[i]=temp;
                perm(list,k+1,m);
                temp=list[k];
                list[k]=list[i];
                list[i]=temp;
            }
    }
}
void tsp(int list[],int n,int a[][n])
{
    int i,j;
    perm(list,0,n-2);
    for(i=0;i<fact(n-1);i++)
    {
        p[i][0]=0;
        p[n][0]=0;
    }
    for(i=0;i<fact(n-1);i++)
    {
        d[i]=0;
        for(j=0;j<n;j++)
        {
            d[i]=d[i]+a[p[i][j]][p[i][j+1]];
        }
    }
}
int min(int list[],int n)
{
    int minimum=list[0],i;
    for(i=0;i<fact(n-1);i++)
    {
        if(list[i]<minimum)
            minimum=list[i];
    }
    return minimum;
}
void print(int n)
{
    int i,j;
    for(i=0;i<fact(n-1);i++)
    {
        if(d[i]==min(d,n))
            break;
    }
    printf("Minimum cost=%d\n",d[i]);
}
int main()
{
    int n,i,j;
    printf("Enter the no of city\n");
    scanf("%d",&n);
    int a[n][n];
    int list[n];
    printf("Enter the cost matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n-1;i++)
        list[i]=i+1;
    tsp(list,n,a);
    print(n);
    return 0;
}
