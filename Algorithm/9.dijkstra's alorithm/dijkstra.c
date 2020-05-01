#include<stdio.h>
#include<limits.h>
#define bool int
#define true 1
#define false 0
int V;
int minDistance(int dist[],bool sptSet[])
{
    int v;
    int min=INT_MAX,min_index;
    for(v=0;v<V;v++)
    {
        if(sptSet[v]==false&&dist[v]<=min)
            min=dist[v],min_index=v;
    }
    return min_index;
}
int printSolution(int dist[],int n)
{
    int i;
    printf("Vertex  Distance from source\n");
    for(i=0;i<V;i++)
        printf("%d\t\t%d\n",i+1,dist[i]);
}
void dij(int graph[V][V],int src)
{
    int i,count,v;
    int dist[V];
    bool sptSet[V];
    for(i=0;i<V;i++)
        dist[i]=INT_MAX,sptSet[i]=false;
    dist[src]=0;
    for(count=0;count<V-1;count++)
    {
        int u=minDistance(dist,sptSet);
        sptSet[u]=true;
        for(v=0;v<V;v++)
        {
            if(!sptSet[v]&&graph[u][v]&&dist[u]!=INT_MAX&&dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
        }
    }
    printSolution(dist,v);
}
int main()
{
    int i,j,src;
    printf("Enter the number of vertices\n");
    scanf("%d",&V);
    int graph[V][V];
    printf("Enter the adjacency matrix\n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            scanf("%d",&graph[i][j]);
    }
    printf("Enter the source\n");
    scanf("%d",&src);
    dij(graph,src);
    return 0;
}
