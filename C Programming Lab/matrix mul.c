#include<stdio.h>
int main()
{
int mat1[10][10],mat2[10][10],mat3[10][10]={0},i,j,k,m,n,p,q;
printf("enter the value of m and n\n");
scanf("%d%d",&m,&n);
printf("enter the elements of matrix1\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&mat1[i][j]);
}
}
printf("enter the value of p and q\n");
scanf("%d%d",&p,&q);
printf("enter the elements of matrix2\n");
for(i=0;i<p;i++)
{
for(j=0;j<q;j++)
{
scanf("%d",&mat2[i][j]);
}
}
printf("the first matrix is\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("%2d",mat1[i][j]);
}
printf("\n");
}
printf("the second matrix is\n");
for(i=0;i<p;i++)
{
for(j=0;j<q;j++)
{
printf("%2d",mat2[i][j]);
}
printf("\n");
}
if(n==p)
{
    printf("matrix multiplication is possible\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            for(k=0;k<q;k++)
            {
                mat3[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    printf("result is\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {

            printf("%2d ",mat3[i][j]);
        }
        printf("\n");
    }
}
else
    printf("multiplication is not possible\n");
    return 0;}

