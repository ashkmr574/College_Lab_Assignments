#include<stdio.h>
#define bool int
#define true 1
#define false 0
int V;
void printSolution(int color[]);
bool isSafe(int v,bool graph[V][V],int color[],int c)
{
    int i;
    for(i=0;i<V;i++)
    {
        if(graph[v][i]&&c==color[i])
            return false;
    }
    return true;
}
bool graphColoringUntil(bool graph[V][V],int m,int color[],int v)
{
    int c;
    if(v==V)
        return true;
    for(c=1;c<=m;c++)
    {
        if(isSafe(v,graph,color,c))
        {
            color[v]=c;
            if(graphColoringUntil(graph,m,color,v+1)==true)
                return true;
            color[v]=0;
        }
    }
}
bool graphColoring(bool graph[V][V],int m)
{
    int i;
    int color[V];
    for(i=0;i<V;i++)
        color[i]=0;
    if(graphColoringUntil(graph,m,color,0)==false)
    {
        printf("Solution does not exist");
        return false;
    }
    printSolution(color);
    return false;
}
void printSolution(int color[])
{
    int i,max;max=0;
    char c[]={'V','I','B','G','Y','O','R'};
    printf("Solution Exists: Following colors are assigned\n");
    for(i=0;i<V;i++)
    {
        printf("%d ----> %c\n",i+1,c[color[i]-1]);
        if(color[i]>max)
            max=color[i];
    }
    printf("Minimum number of colors required : %d",max);
    printf("\n");
}
int main()
{
    int i,j,f;
    printf("Enter the number of vertices :\n");
    scanf("%d",&V);
    bool graph[V][V];
    printf("Enter the adjacency matrix :\n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            scanf("%d",&f);
            if(f==1)
            graph[i][j]=true;
            else
            graph[i][j]=false;
        }
    }
    int m=V;
    graphColoring(graph,m);
    return 0;
}
