#include<stdio.h>
int main()
{
int mat[10][10],i,j,p,m,n,f=0;
printf("enter the value of m and n");
scanf("%d%d",&m,&n);
printf("enter the elements of matrix\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&mat[i][j]);
}
}
printf("the matrix is\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("%d",mat[i][j]);
}
printf("\n");
}
for(i=0;i<m;i++)
{
 for(j=0;j<n;j++)
 {
if(mat[i][j]==0&&i!=j)
    f++;
 }
}
if(f==m*(n-1))
printf("digonal matrix");
else
    printf("not digonal");
return 0;
}
