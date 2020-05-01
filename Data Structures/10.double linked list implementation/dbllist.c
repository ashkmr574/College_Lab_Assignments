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
void append(node **h,node **l,int z)
{
	node *t;
	t=cn();
	t->d=z;
	t->n=NULL;
	t->p=*l;
	if(*h==NULL)
	*h=t;
	else
	(*l)->n=t;
	*l=t;
}
void addbeg(node **h,node **l,int z)
{
	node *t;
	t=cn();
	t->d=z;
	t->n=*h;
	t->p=NULL;
	if(*h==NULL)
        *l=t;
	else
        (*h)->p=t;
	*h=t;
}
node* find(node *h,int z)
{
    while(h!=NULL)
	{
		if(h->d==z)
		return h;
        h=h->n;
	}
	return h;
}
void addbefore(node *r,int z)
{
	node *t;
	t=cn();
	t->d=z;
	t->n=r;
	t->p=r->p;
	(r->p)->n=t;
	r->p=t;
}
void addafter(node *r,int z)
{
	node *t;
	t=cn();
	t->d=z;
	t->n=r->n;
	(r->n)->p=t;
	t->p=r;
	r->n=t;
}
int delbeg(node **h,node **l)
{
	node *t;
	int z;
	if(*h==NULL)
	{
		printf("list is empty\n");
		return;
	}
	else
	{
		t=*h;
		z=t->d;
		if(*h==*l)
            *h=*l=NULL;
		else
		{
			*h=(*h)->n;
			(*h)->p=NULL;
		}
		free(t);
		printf("deleted number is=%d\n",z);
		return z;
	}
}
int delend(node **h,node **l)
{
	node *t;
	int z;
	if(*h==NULL)
	{
		printf("list is empty\n");
		return;
	}
	else
	{
		t=*l;
		z=t->d;
		if(*h==*l)
		*h=*l=NULL;
		else
		{
			*l=(*l)->p;
			(*l)->n=NULL;
		}
		free(t);
		printf("deleted number is=%d\n",z);
		return z;
	}
}
void delany(node *r)
{
    int z;
	(r->p)->n=r->n;
	(r->n)->p=r->p;
	z=r->d;
	free(r);
	printf("deleted number is=%d\n",z);
}
void show(node *h)
{
	if(h==NULL)
	{
		printf("list is empty\n");
		return;
	}
	else
    {
        printf("list is  ");
        while(h!=NULL)
        {
            printf("%d\t",(h->d));
            h=h->n;
        }
        printf("\n");
    }
}
void rev(node **h,node **l)
{
    node *p=NULL,*c,*s,*t;
    c=*h;
    t=*h;
    do{
        s=c->n;
        c->p=c->n;
        c->n=p;
        p=c;
        c=s;
      }while(c!=NULL);
    *h=p;
    *l=t;
}
int main()
{
	node *h=NULL,*l=NULL,*t=NULL;
	int c,z,x;
	do{
        printf("Enter the choice\n1.addbeg\n2.append\n3.addbefore\n4.addafter\n5.delbeg\n6.delend\n7.Delany\n8.show\n9.reverse\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("Enter the number to be inserted\n");
                   scanf("%d",&z);
                   addbeg(&h,&l,z);
                   break;
            case 2:printf("Enter the number to be inserted\n");
                   scanf("%d",&z);
                   append(&h,&l,z);
                   break;
            case 3:printf("Enter the number before which you want to insert\n");
                   scanf("%d",&x);
                   printf("Enter the number to be inserted\n");
                   scanf("%d",&z);
                   t=find(h,x);
                   if(t==NULL&&h==NULL)
                       printf("list is empty\n");
                   else if(t==NULL&&h!=NULL)
                       printf("element not found\n");
                   else
                   {
                       if(t->p==NULL)
                          addbeg(&h,&l,z);
                       else
                          addbefore(t,z);
                   }
                   break;
            case 4:printf("Enter the number after which you want to insert\n");
                   scanf("%d",&x);
                   printf("Enter the number to be inserted\n");
                   scanf("%d",&z);
                   t=find(h,x);
                   if(t==NULL&&h==NULL)
                          printf("list is empty\n");
                   else if(t==NULL&&h!=NULL)
                          printf("element not found\n");
                   else
                   {
                      if(t->n==NULL)
                          append(&h,&l,z);
                      else
                          addafter(t,z);
                   }
                   break;
            case 5:delbeg(&h,&l);
                   break;
            case 6:delend(&h,&l);
                   break;
            case 7:
                if(h==NULL)
                {
                    printf("list is empty\n");
                }
                else
                {
                    printf("Enter the number to be deleted\n");
                    scanf("%d",&z);
                    t=find(h,z);
                    if(t==NULL)
                        printf("element not found\n");
                    else
                    {
                        if(t==h)
                            delbeg(&h,&l);
                        else if(t==l)
                            delend(&h,&l);
                        else
                            delany(t);
                    }
                }
                break;
            case 8:show(h);
                  break;
            case 9:if(h==NULL)
                        printf("list is empty\n");
                   else
                        rev(&h,&l);
                   break;
            default:exit(1);
        }
	}while(1);
    return 0;
}



