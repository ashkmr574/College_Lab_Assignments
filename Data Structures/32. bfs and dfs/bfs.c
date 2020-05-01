#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int *a;
    int r,f,size;
}queue;
void init(queue*q,int n)
{
	q->a=(int*)malloc(sizeof(int)*n);
	q->size=n;
	q->r=-1;
	q->f=0;
}
int isfull(queue*q)
{
	if(q->r==q->size-1)
		return 1;
	else
		return 0;
}
int isempty(queue*q)
{
	if((q->r)<(q->f))
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
	if(isempty(q))
		return;
	else
	{
		z=q->a[q->f];
        q->f++;
		return z;
    }
}
void bfs(int n,int a[][n])
{
    queue q;
    init(&q,n);
    int i=0,j;
    int f[n];
    printf("%d\t",i);
    f[i]=1;
    enqueue(&q,0);
    while(!isempty(&q))
    {
        i=dequeue(&q);
        for(j=0;j<n;j++)
            if(a[i][j]==1&&f[j]!=1)
            {
                printf("%d\t",j);
                f[j]=1;
                enqueue(&q,j);
            }
    }
}
int main()
{
    int n;
    printf("enter the no of vertex in graph\n");
    scanf("%d",&n);
    int a[n][n],i,j;
    printf("enter the adjacency matrix for the graph\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    bfs(n,a);
    return 0;
}
