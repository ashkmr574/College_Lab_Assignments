#include<stdio.h>
int main()
{
int mat[10][10],i,j,trans[10][10],m,n;
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
trans[j][i]=mat[i][j];
 }
}
printf("transpose of matrix is\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("%d",trans[i][j]);
}
printf("\n");
}
return 0;
}
