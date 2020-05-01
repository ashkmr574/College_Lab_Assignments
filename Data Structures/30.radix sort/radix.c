#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int *a;
    int r,f,s;
}queue;
void init(queue*q,int n)
{
    (q->a)=(int *)malloc(sizeof(int)*n);
    q->s=n;
    q->r=-1;
    q->f=0;
}
int isempty(queue*q)
{
    if((q->f)>(q->r))
        return 1;
    else
        return 0;
}
void enqueue(queue*q,int z)
{
    q->r++;
    q->a[q->r]=z;
}
int dequeue(queue*q)
{
    int z;
    z=q->a[q->f];
    q->f++;
    return z;
}
int maxelement(int a[],int n)
{
    int i,max;
    max=0;
    for(i=0;i<n;i++)
            if(a[i]>=max)
                max=a[i];
    return max;
}
int count(int m)
{
    int c=0;
    while(m>0)
    {
        m/=10;
        c++;
    }
    return c;
}
void radix(int a[],int n)
{
    queue q[19];
    int i,r,j,l,d,p,m,k,z,s;
    d=1;
    for(i=0;i<19;i++)
        init(&q[i],n);
    m=maxelement(a,n);
    p=count(m);
    for(i=0;i<=p;i++)
    {
        for(j=0;j<n;j++)
        {
            r=a[j]%(d*10);
            r=r/d;
            enqueue(&q[r+9],a[j]);
        }
        d*=10;
        k=0;
        for(j=0;j<19;j++)
            while(!isempty(&q[j]))
                {
                    a[k++]=dequeue(&q[j]);
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
    radix(a,n);
    printf("sotred array is\t");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}

