#include<stdio.h>
#include<limits.h>
int chk(int a[][4],int d[][4])
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(a[i][j]!=d[i][j])
                return 1;
    return 0;
}
void print(int a[][4],int c[],int k)
{
    int i,j;
    for(i=0;i<k;i++)
    {
        if(c[i]==1)
            printf("UP\n");
        else if(c[i]==2)
            printf("DOWN\n");
        else if(c[i]==3)
            printf("LEFT\n");
        else
            printf("RIGHT\n");
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
}
int min(int a[][4])
{
    int i,j,min1=0,index=1;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if((a[i][j]==index))
                min1++;
            index++;
        }
    }
    //printf("hh %d\n",min1);
    return 16-min1;
}
int main()
{
    int a[4][4],b[16],i,j,k=0,min1=INT_MAX,temp,loc1,loc2,loc3,loc4;
    int c[150]={0},l1=0,k1=0,d[4][4];
    printf("Enter the initial state\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==16)
            {
                loc1=i;
                loc2=j;
            }
            b[k++]=a[i][j];
            d[i][j]=a[i][j];
        }
    }
    //print(a);
    int less=0;
    for(i=0;i<16;i++)
    {
        temp=b[i];
        for(j=i+1;j<16;j++)
            if(b[j]<temp)
                less++;
        //printf("%d\n",less);
    }
    if((loc1+loc2)%2!=0)
        less++;
    //printf("%d\n",less);
    int f1=0;
    if(less%2==0)
    {
        int l=min(a);
        while((min1!=0)&&(l!=0))
        {
            if(loc1!=0)
            {
                temp=a[loc1][loc2];
                a[loc1][loc2]=a[loc1-1][loc2];
                a[loc1-1][loc2]=temp;
                temp=min(a);
                if((temp<min1)&&(chk(a,d)==1))
                {
                    min1=temp;
                    loc3=loc1-1;
                    loc4=loc2;
                    f1=1;
                }
                temp=a[loc1][loc2];
                a[loc1][loc2]=a[loc1-1][loc2];
                a[loc1-1][loc2]=temp;
                //printf("min1=%d\n",min1);
            }
            if(loc1<3)
            {
                temp=a[loc1][loc2];
                a[loc1][loc2]=a[loc1+1][loc2];
                a[loc1+1][loc2]=temp;
                temp=min(a);
                if((temp<min1)&&(chk(a,d)==1))
                {
                    min1=temp;
                    loc3=loc1+1;
                    loc4=loc2;
                    f1=2;
                }
                temp=a[loc1][loc2];
                a[loc1][loc2]=a[loc1+1][loc2];
                a[loc1+1][loc2]=temp;
                //printf("min2=%d\n",min1);
            }
            if(loc2!=0)
            {
                temp=a[loc1][loc2];
                a[loc1][loc2]=a[loc1][loc2-1];
                a[loc1][loc2-1]=temp;
                temp=min(a);
                if((temp<min1)&&(chk(a,d)==1))
                {
                    min1=temp;
                    loc3=loc1;
                    loc4=loc2-1;
                    f1=3;
                }
                temp=a[loc1][loc2];
                a[loc1][loc2]=a[loc1][loc2-1];
                a[loc1][loc2-1]=temp;
                //printf("min3=%d\n",min1);
            }
            if(loc2<3)
            {
                temp=a[loc1][loc2];
                a[loc1][loc2]=a[loc1][loc2+1];
                a[loc1][loc2+1]=temp;
                temp=min(a);
                if((temp<min1)&&(chk(a,d)==1))
                 {
                    min1=temp;
                    loc3=loc1;
                    loc4=loc2+1;
                    f1=4;
                }
                temp=a[loc1][loc2];
                a[loc1][loc2]=a[loc1][loc2+1];
                a[loc1][loc2+1]=temp;
                //printf("min4=%d\n",min1);
            }
            temp=a[loc1][loc2];
            a[loc1][loc2]=a[loc3][loc4];
            a[loc3][loc4]=temp;
            loc1=loc3;
            loc2=loc4;
            //printf("%d\t",++l1);
            c[k1++]=f1;
            //break;
        }
        //printf("\n");
        print(a,c,k1);
    }
    else
        printf("GOAL STATE CANNOT BE REACHED\n");
    return 0;
}
