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
	q->f=-1;
}
int isfull(queue*q)
{
	if(((q->r==q->size-1)&&(q->f==0))||(q->f==q->r+1))
		return 1;
	else
		return 0;
}

int isempty(queue*q)
{
	if(q->r==-1&&q->f==-1)
		return 1;
	else
		return 0;
}
void enqueue(queue*q,int z)
{
	if(isfull(q))
	{
		printf("overflow\n");
		return;
	}
	else
	{
		if(q->f==-1)
			q->f=0;
		if(q->r==q->size-1)
			q->r=0;
		else
			q->r++;
		q->a[q->r]=z;
	}
}

int dequeue(queue*q)
{
	int z;
	if(isempty(q))
	{
		printf("underflow\n");
		return 0;
	}
	else
	{
		z=q->a[q->f];
		if(q->f==q->r)
			q->f=q->r=-1;
		else if(q->f==q->size-1)
			q->f=0;
		else
			q->f++;
        printf("item deleted is=%d\n",z);
		return z;

	}
}
void enqueuef(queue*q,int z)
{

		 if(isfull(q))
		 {
		 	printf("overflow\n");
		 	return;
		 }
		 else
		 {
		 	if(q->r==-1)
		 		q->f=q->r=q->size-1;
		 	else if(q->f==0)
		 		q->f=q->size-1;
		 	else
		 		q->f--;
		 	q->a[q->f]=z;

		 }
}
int dequeuer(queue*q)
{
		int z;
		if(isempty(q))
		{
			printf("underflow\n");
			return;
		}
		else
		{
			z=q->a[q->r];
			if(q->f==q->r)
				q->r=q->f=-1;
			else if(q->r==0)
				q->r=q->size-1;
			else
				q->r--;
            printf("item deleted is=%d\n",z);
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
		printf("enter the choice\n1.enqueue\n2.dequeue\n3.enqueuef\n4.dequeuer\n5.exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("enter the element\n");
                   scanf("%d",&z);
                   enqueue(&q,z);
                   break;
			case 2:dequeue(&q);
                   break;
			case 3:printf("enter the element\n");
				   scanf("%d",&z);
				   enqueuef(&q,z);
                   break;
            case 4 :dequeuer(&q);
                    break;
			case 5:exit(1);
			default :printf("wrong input\n");
		}
	  }while(1);
      return 0;
}


























