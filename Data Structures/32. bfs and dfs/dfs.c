#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
  int *a;
  int tos,size;
}stack;
void init(stack*s,int n)
{
    s->a=(int*)malloc(sizeof(int)*n);
    s->size=n;
    s->tos=-1;
}
int isfull(stack*s)
{
    if(s->tos==s->size-1)
        return 1;
    else
        return 0;
}
void push(stack*s,int z)
{
    if(isfull(s))
        return ;
    else
    {
        s->tos++;
        s->a[s->tos]=z;
    }
}
int isempty(stack*s)
{
    if(s->tos==-1)
        return 1;
    else
        return 0;
}
int pop(stack *s)
{
    int z;
    if(isempty(s))
      return 1;
    else
    {
        z=s->a[s->tos];
        s->tos--;
        return z;
    }
}
void dfs(int n,int a[][n])
{
    stack s;
    init(&s,n);
    int i,j,k;
    int f[n];
    push(&s,0);
    while(!isempty(&s))
    {
        i=pop(&s);
        if(f[i]!=1)
        {
            printf("%d\t",i);
            f[i]=1;
            for(j=0;j<n;j++)
                if(a[i][j]==1&&f[j]!=1)
                    push(&s,j);
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
    dfs(n,a);
    return 0;
}
