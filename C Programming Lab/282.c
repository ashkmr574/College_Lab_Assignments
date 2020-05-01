#include<stdio.h>
int main()
{
	int a[100],n,i,j,temp,num,low,high,mid,c=0;
	printf("enter size of array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j+1]>a[j])
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=n;i>0;i--)
	printf("%d\t",a[i]);
	printf("enter no. to be search\n");
	scanf("%d",&num);
	low=0;
	high=n-1;
	while(low<=high)
    {
        mid=(low+high)/2;
        if(num==a[mid])
        {
            c=1;
            break;
        }
        else if(num<a[mid])
        {
            high=mid-1;
        }
        else
            {low=mid+1;
            }
    }
    if(c==0)
        printf("not found");
    else
        printf("found");
    return 0;
}


