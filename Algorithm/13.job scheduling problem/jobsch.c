#include<stdio.h>
typedef struct event
{
        int s;
        int e;
        int no;
}event;
int compare(const void *x, const void *y)
{
        event *e1 = (event *)x, *e2 = (event *)y;
        return (*e1).e - (*e2).e;
}
int main()
{
        int n;
        printf("Enter no of jobs\n");
        scanf("%d",&n);
        event T[n];
        int i;
        printf("Enter start time and end time of jobs\n");
        for(i=0;i<n;i++)
        {
                scanf("%d%d",&T[i].s,&T[i].e);
                T[i].no = i;
        }
        qsort(T,n,sizeof(event),compare);
        //for(i=0;i<n;i++)
            //printf("%d %d %d\n",T[i].no+1,T[i].s,T[i].e);

        int events[n];

        int pe = 0;

        events[pe++] = T[0].no;
        int pre = 0;

        for(i=1;i<n;i++)
        {
                if(T[i].s >= T[pre].e)
                {
                        events[pe++] = T[i].no;
                        pre = i;
                        //printf("%d\n",i);
                }
        }
        printf("Maximum possible events that can be attended are %d. They are\n",pe);
        for(i=0;i<pe;i++)
        {
                printf("%d\n",events[i]+1);
        }
        return 0;

}
