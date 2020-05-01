#include<stdio.h>
#define bool int
#define true 1
#define false 0
int N=0;
void printSolution(int board[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(board[i][j]==1)
                printf("Q  ");
            else
                printf("%d  ",board[i][j]);
        }
        printf("\n\n");
    }
}
bool isSafe(int board[N][N],int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i])
            return false;
    }
    for(i=row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j])
            return false;
    }
    for(i=row,j=col;j>=0&&i<N;i++,j--)
    {
        if(board[i][j])
            return false;
    }
    return true;
}
bool solveNQUntil(int board[N][N],int col)
{
    int i;
    //static int p;
    if(col>=N)
        return true;
    for(i=0;i<N;i++)
    {
        if(isSafe(board,i,col))
        {
            board[i][col]=1;
            if(solveNQUntil(board,col+1)==true)
                return true;
            board[i][col]=0;
        }
        //printSolution(board);
        //printf("count = %d\n",p++);
    }
    return false;
}
bool SolveNQ()
{
    int i,j;
    printf("Enter the value of n in N-QUEENS problem\n");
    scanf("%d",&N);
    int board[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            board[i][j]=0;
    }
    if(solveNQUntil(board,0)==false)
    {
        printf("No Solution Exist\n");
        return false;
    }
    printSolution(board);
    return true;
}
int main()
{
    SolveNQ();
    return 0;
}
