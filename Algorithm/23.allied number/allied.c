#include<stdio.h>
int count(int A[],int z)
{
    int i,cnt;cnt=0;
    for(i=0;i<10;i++)
    {
        if(A[i]==z)
            ++cnt;
    }
    return cnt;
}
int check(int A[])
{
    int cnt,i;
    for(i=0;i<10;i++)
    {
        cnt=count(A,i);
        if(A[i]==cnt);
        else
        return 0;
    }
    return 1;
}
int main()
{
    int A[10]={0},i,j;
    while((j=check(A))==0)
    {
        for(i=0;i<10;i++)
            A[i]=count(A,i);
    }
    printf("The allied number is:\n");
    for(i=0;i<10;i++)
        printf("%d",A[i]);
}
