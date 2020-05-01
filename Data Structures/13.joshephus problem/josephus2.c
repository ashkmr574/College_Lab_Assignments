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
void append(node **p,int z)
{
    node *t,*r;
    t=cn();
    t->d=z;
    if(*p==NULL)
        *p=t;
    else
    {
        r=*p;
        while(r->n!=(*p))
            r=r->n;
        r->n=t;
    }
    t->n=(*p);
}
void delbeg(node **p)
{
    node* t,*r;
    t=(*p);
    r=(*p);
    while(r->n!=(*p))
        r=r->n;
    r->n=(*p)->n;
    *p=(*p)->n;
    free(t);
}
void delp(node *p)
{
	node *t;
	t=p->n;
	p->n=t->n;
	free(t);
}
node* josephus(node *h,int n)
{
    int i=0;
	while(h->n!=h)
	{
	    if(n==1)
        {
            delbeg(&h);
        }
            else
		{
		    for(i=1;i<n-1;i++)
			h=h->n;
            delp(h);
            h=h->n;
        }
	}
	return h;
}
int main()
{
    node*p=NULL;
    int c,z,n;
    do{
            printf("enter the element\n");
            scanf("%d",&z);
            append(&p,z);
            printf("do you want to enter again\n1.yes\n2.no\n");
            scanf("%d",&c);
     }while(c==1);
    printf("enter the count\n");
    scanf("%d",&n);
    p=josephus(p,n);
    printf("result is=%d\n",p->d);
    return 0;
}

