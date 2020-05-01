#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
int *a;
int r,size;
}queue;
void init(queue*q,int n)
{
	q->a=(int*)malloc(sizeof(int)*n);
	q->size=n;
	q->r=-1;
}
int isfull(queue*q)
{
	if(q->r==q->size-1)
		return 1;
	else
		return 0;
}

int isempty(queue*q)
{
	if(q->r==-1)
		return 1;
	else
		return 0;
}
void enqueue(queue*q,int z)
{
    int c,p,t,i;
	if(isfull(q))
	{
		printf("overflow\n");
		return;
	}
	else
	{
        q->r++;
		q->a[q->r]=z;
		c=q->r;
		do{
              p=(c-1)/2;
              if(q->a[p]<=q->a[c])
              {
                  t=q->a[p];
                  q->a[p]=q->a[c];
                  q->a[c]=t;
              }
              else
                break;
            c=p;
          }while(c!=0);
	}
}
int dequeue(queue*q)
{
	int z,c,p,t;
	if(isempty(q))
	{
		printf("underflow\n");
		return 0;
	}
	else
	{
        z=q->a[0];
        q->a[0]=q->a[q->r];
        q->r--;
        p=0;
        do{
                c=2*p+1;
                if(c<=(q->r))
                {
                    if(c<(q->r)&&(q->a[c])<(q->a[c+1]))
                    c++;
                    if((q->a[c])>(q->a[p]))
                    {
                        t=q->a[c];
                        q->a[c]=q->a[p];
                        q->a[p]=t;
                    }
                    else
                        break;
                    p=c;
                }
          }while(c<=(q->r));
        printf("deleted item is=%d\n",z);
		return z;
    }
}
int main()
{
	queue q;
	int n,c=0,z;
	printf("enter size of queue");
	scanf("%d",&n);
	init(&q,n);
	do{
		printf("enter the choice\n1.enqueue\n2.dequeue\n3.exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("enter the element\n");
       				scanf("%d",&z);
       				enqueue(&q,z);
      				 break;
            case 2:dequeue(&q);
                   break;
            case 3:exit(1);
            default :printf("wrong input\n");
        }
    }while(1);
    return 0;
}


