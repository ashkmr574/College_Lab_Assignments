#include<stdio.h>
typedef struct item
{
        int weight;
        int value;
}item;
int compare(const void *x, const void *y)
{
        item *i1 = (item *)x, *i2 = (item *)y;
        double ratio1 = (*i1).value*1.0 / (*i1).weight;
        double ratio2 = (*i2).value*1.0 / (*i2).weight;
        if(ratio1 < ratio2) return 1;
        else if(ratio1 > ratio2) return -1;
        else return 0;
}
int main()
{
        int n,W;
        printf("Enter the no of items\n");
        scanf("%d",&n);
        item I[n];
        int i;
        printf("Enter the wieght and value of items\n");
        for(i=0;i<n;i++)
        {
                scanf("%d%d",&I[i].weight,&I[i].value);
        }
        qsort(I,n,sizeof(item),compare);
        printf("Enter the maximum wieght of knapsack\n");
        scanf("%d",&W);
        double val = 0.0;
        int pr = 0;
        float cv[n];
        for(i=0;i<n;i++)
            cv[i]=0.0;
        for(i=0;i<n;i++)
        {
                if(pr + I[i].weight <=W)
                {
                        pr = pr + I[i].weight ;
                        val += I[i].value;
                        cv[i]=1;
                }
                else
                {
                        int remain  = W - pr;
                        val += I[i].value*remain *1.0/I[i].weight;
                        cv[i]=(W-pr)*1.0/I[i].weight;
                        break;
                }

        }
        printf("Maximum value that can be attained is %.6lf\n",val);
        printf("And fracton taken of different items are\n");
        for(i=0;i<n;i++)
            printf("Item with value %d is taken %.2f fraction \n",I[i].value,cv[i]);
}
