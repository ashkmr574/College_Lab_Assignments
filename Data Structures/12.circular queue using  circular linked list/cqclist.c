#include <stdio.h>
#include <stdlib.h>
typedef struct linkedlist
{
	int d;
	struct linkedlist *n;
}node;
node* cn()
{
    return((node *)malloc(sizeof(node)));
}
void enqueue(node **r,int z)
{
	node *t;
	t=cn();
	t->d=z;
	if(*r==NULL)
		t->n=t;
	else
	{
		t->n=(*r)->n;
		(*r)->n=t;
	}
	*r=t;
}
int dequeue(node **r)
{
	node *t;
	int z;
	t=*r;
	if(*r==NULL)
	{
		printf("no items to delete\n");
		return;
	}
	else if(*r==(*r)->n)
	{
		z=t->d;
		free(t);
		*r=NULL;
		printf("item deleted is=%d\n",z);
		return z;
	}
	else
	{
		t=(*r)->n;
		(*r)->n=t->n;
		z=t->d;
		free(t);
		printf("item deleted is=%d\n",z);
		return z;
	}
}
int main()
{
	node *p=NULL;
	int c,z;c=z=0;
	do{
		printf("enter the choice\n1.enqueue\n2.dequeue\n3.josephus\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("enter the element to enqueue\n");
			       scanf("%d",&z);
			       enqueue(&p,z);
			       break;
			case 2:dequeue(&p);
			       break;
			case 3:exit(1);
			default :printf("wrong input\n");
                     break;
        }
	}while(1);
	return 0;
}




