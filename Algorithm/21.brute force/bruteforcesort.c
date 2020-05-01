#include<stdio.h>
int main()
{
    int n,i;
    printf("Enter the number of programs\n");
    scanf("%d",&n);
    int Task[n];
    int len[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the task number with length\n");
        scanf("%d%d",&Task[i],&len[i]);
    }
    float avg =99999;
    int j,k;
    float t;
    int arr[3];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if((i!=j)&&(i!=k)&&(k!=j))
                {
                    t=(len[i]+(len[i]+len[j])+(len[i]+len[j]+len[k]))/3.0;
                    if(t<avg)
                     {
                         avg=t;
                         arr[0]=i+1;
                         arr[1]=j+1;
                         arr[2]=k+1;
                     }
                }
            }
        }

    }
    printf("\n average = %f",avg);
    printf("\n Order is %d %d %d",arr[0],arr[1],arr[2]);
    return 0;

}
