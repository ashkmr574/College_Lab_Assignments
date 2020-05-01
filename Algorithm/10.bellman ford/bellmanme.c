#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct
{
    int src, dest, weight;
}edge;
void printArr(int dist[], int n)
{
    int i;
    printf("Vertex   Distance from Source\n");
    for (i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
void BellmanFord(int V,int E,edge e[],int src)
{
    int dist[V],i,j;
    for ( i = 0; i < V; i++)
        dist[i]   =99999;
    dist[src] = 0;
    for ( i = 1; i <= V-1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u =e[j].src;
            int v =e[j].dest;
            int weight =e[j].weight;
            if (dist[u] != 99999 && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                //printf("%d\t",dist[v]);
            }
        }
    }
    for (i = 0; i < E; i++)
    {
        int u = e[i].src;
        int v = e[i].dest;
        int weight = e[i].weight;
        if (dist[u] != 99999 && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
    }
    printArr(dist, V);
}
int main()
{
    int V,E,i,j,k=0,source;
    printf("Enter the no of vertices\n");
    scanf("%d",&V);
    int graph[V][V];
    printf("Enter the no of rows\n");
    scanf("%d",&E);
    edge e[50];
    printf("Enter the graph matrix\n");
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            scanf("%d",&graph[i][j]);
    printf("Enter the source vertex\n");
    scanf("%d",&source);
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            if((graph[i][j]!=99999)&&(graph[i][j]!=0))
            {
                e[k].src=i;
                e[k].dest=j;
                e[k].weight=graph[i][j];
                k++;
            }
        }
    }
    for(i=0;i<E;i++)
    {
        printf("%d %d %d\n",e[i].src,e[i].dest,e[i].weight);
    }
    BellmanFord(V,E,e,source);
    return 0;
}
