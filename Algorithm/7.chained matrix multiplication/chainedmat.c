#include<stdio.h>
int M[20][20],M1[20][20];
int matrix(int M[20][20],int p[],int i,int j)
{
    if(i==j)
        return 0;
    if(M1[i][j])
        return M1[i][j];
    int k,c,min=999999;
    for (k=i;k<j;k++)
    {
        c=matrix(M,p,i,k)+matrix(M,p,k+1,j)+(p[i-1]*p[k]*p[j]);
        if(c<min)
        {
            min=c;
            M1[i][j]=c;
            M[i][j]=k;
        }
    }
    return min;
}
void print(int M[20][20],int i,int j)
{
    if(i==j)
    printf("M%d",i);
    else
    {
        printf("(");
        print(M,i,M[i][j]);
        print(M,M[i][j]+1,j);
        printf(")");
    }
}
int main()
{
    int n,i,val,l,m;
    printf("Enter the number of matrices: ");
    scanf("%d",&n);
    int p[n+1];
    for(i=0;i<n;i++)
    {
        printf("Enter the no of rows of the matrix %d: ",i+1);
        scanf("%d",&p[i]);
    }
    printf("Enter the no of columns of the matrix %d: ",i);
    scanf("%d",&p[i]);
    val=matrix(M,p,1,n);
    printf("\nNumber of multiplication: %d\n\n",val);

    for(l=1;l<=n;l++)
    {
        for(m=1;m<=n;m++)
        {
                printf("%4d ",M1[l][m]);
        }
        printf("\n");
    }
    for(l=1;l<=n;l++)
    {
        for(m=1;m<=n;m++)
        {
                printf("%2d ",M[l][m]);
        }
        printf("\n");
    }
    printf("\nThe Optimal order is:\n");
    print(M,1,n);
    return 0;
}
