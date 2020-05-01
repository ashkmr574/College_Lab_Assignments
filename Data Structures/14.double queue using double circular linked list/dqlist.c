#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist
{
	int d;
	struct linkedlist *n,*p;
}node;
node* cn()
{
	return((node*)malloc(sizeof(node)));
}
void enqueuer(node **r,int z)
{
	node *t;
	t=cn();
	t->d=z;
	if(*r==NULL)
	{
		t->n=t;
		t->p=t;
	}
	else
	{
		t->n=(*r)->n;
		t->p=*r;
		((*r)->n)->p=t;
		(*r)->n=t;
	}
	*r=t;
}
void enqueuef(node **r,int z)
{
	node *t;
	t=cn();
	t->d=z;
	if(*r==NULL)
	{
		t->n=t;
		t->p=t;
		*r=t;
	}
	else
	{
		t->p=(*r);
		t->n=(*r)->n;
		((*r)->n)->p=t;
		(*r)->n=t;
	}
}
void dequeuef(node **r)
{
	node *t;int z;
	if(*r==NULL)
	{
		printf("list is empty\n");
		return;
	}
	else if(*r==(*r)->n)
	{
        t=(*r)->n;
		z=t->d;
		free(t);
		*r=NULL;
		printf("deleted item is=%d\n",z);
	}
	else
	{
	    t=(*r)->n;
		z=t->d;
		(*r)->n=t->n;
		(t->n)->p=*r;
		free(t);
		printf("deleted item is=%d\n",z);
	}
}
int dequeuer(node **r)
{
	node *t=(*r);int z;
	if(*r==NULL)
	{
		printf("list is empty\n");
		return;
	}
	else if(*r==(*r)->n)
	{
		z=t->d;
		free(t);
		*r=NULL;
		printf("deleted item is=%d\n",z);
	}
	else
	{
		z=t->d;
		(t->p)->n=t->n;
		(t->n)->p=t->p;
		*r=(*r)->p;
		free(t);
		printf("deleted item is=%d\n",z);
	}
}
int main()
{
	node *p=NULL;int c,w;
	do{
        printf("Enter the choice \n1.Enqueuefront\n2.Enqueuerear\n3.Dequeuefront\n4.Dequeuerear\n5.Exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter the number to enqueued\n");
                scanf("%d",&w);
                enqueuef(&p,w);
                break;
            case 2:
                printf("Enter the number to enqueued\n");
                scanf("%d",&w);
                enqueuer(&p,w);
                break;
            case 3:
                dequeuef(&p);
                break;
            case 4:
                dequeuer(&p);
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("Wrong Input\n");
        }
    }while(1);
	return 0;
}
