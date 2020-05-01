#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int *a;
    int r,f,size;
}queue;
void init(queue*q,int n)
{
	q->a=(int*)malloc(sizeof(int)*n);
	q->size=n;
	q->r=-1;
	q->f=0;
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
	if((q->r)<(q->f))
		return 1;
	else
		return 0;
}
void enqueue(queue*q,int z)
{
    q->r++;
    q->a[q->r]=z;
}
int dequeue(queue*q)
{
	int z;
	if(isempty(q))
	{
		printf("underflow\n");
		return;
	}
	else
	{
		z=q->a[q->f];
        q->f++;
        printf("item deleted s=%d\n",z);
		return z;
    }
}
int main()
{
	queue q;
	int n,c=0,z;
	printf("enter size of queue\n");
	scanf("%d",&n);
	init(&q,n);
	do{
		printf("enter the choice\n1.enqueue\n2.dequeue\n3.exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:if(!(isfull(&q)))
                    {
                        printf("enter the element\n");
                        scanf("%d",&z);
                        enqueue(&q,z);
                    }
                    else
                        printf("overflow\n");
                    break;
            case 2:dequeue(&q);
                   break;
            case 3:exit(1);
            default :printf("wrong input\n");
        }
    }while(1);
    return 0;
}













