#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist
{
    int d;
    struct linkedlist *n;
}node;
node *cn()
{
    return (node *)malloc(sizeof(node));
}
void append(node **p,int z)
{
    node *t,*r;
    t=cn();
    t->d=z;
    t->n=NULL;
    if(*p==NULL)
        *p=t;
    else
    {
        r=*p;
        while(r->n!=NULL)
            r=r->n;
        r->n=t;
    }
}
int show(node*p)
{
    printf("list is  ");
    while(p!=NULL)
    {
        printf("%d\t",p->d);
        p=p->n;
    }
    printf("\n");
}
void addbeg(node **p,int z)
{
    node *t;
    t=cn();
    t->d=z;
    t->n=*p;
    *p=t;
}
void insp(node *p,int z)
{
    node *t;
    t=cn();
    t->d=z;
    t->n=p->n;
    p->n=t;
}
node *find(node *p,int z)
{
    while(p!=NULL)
    {
        if(p->d==z)
            return p;
        p=p->n;
    }
    return p;
}
void addafter(node *p,int x,int y)
{
    node *t;
    t=find(p,x);
    if(t!=NULL)
        insp(t,y);
    else
    {
        if(p==NULL)
            printf("list is empty\n");
        else
            printf("element not found\n");
    }
}
node* findprev(node *p,int z)
{
    node*m=NULL;
    while(p!=NULL)
    {
        if(p->d==z)
            return m;
        m=p;
        p=p->n;
    }
    return NULL;
}
void addbefore(node **p,int x,int y)
{
    node *t;
    t=findprev(*p,x);
    if(t!=NULL)
         insp(t,y);
    else
    {
        if((*p)==NULL)
            printf("list is empty\n");
        else if((*p)!=NULL&&(*p)->d==x)
            addbeg(p,y);
        else
            printf("element not found\n");
    }
}
void delbeg(node **p)
{
    node* t;
    int z;
    if(*p==NULL)
        printf("list is empty\n");
    else
    {
        z=(*p)->d;
        t=(*p);
        *p=(*p)->n;
        free(t);
        printf("deleted item is=%d\n",z);
    }
}
void delp(node *p)
{
    node *t;
    int z;
    t=p->n;
    z=t->d;
    p->n=t->n;
    free(t);
    printf("deleted item is=%d\n",z);
}
void delend(node **p)
{
    node *t,*r;
    if(*p==NULL)
        printf("list is empty\n");
    else
    {
        r=(*p);
        while((r->n)!=NULL)
            r=r->n;
        t=findprev(*p,r->d);
        if(t==NULL)
            delbeg(p);
        else
            delp(t);
    }
}
void delany(node **p,int z)
{
	node *t;
	t=findprev(*p,z);
	if(t!=NULL)
	delp(t);
	else
	{
	    if((*p)==NULL)
            printf("list is empty\n");
        else if((*p)!=NULL&&(*p)->d==z)
            delbeg(p);
        else
            printf("element not found\n");
	}
}
void rev(node **h)
{
    node *p=NULL,*c,*s;
    c=*h;
    do{
        s=c->n;
        c->n=p;
        p=c;
        c=s;
      }while(c!=NULL);
    *h=p;
}
int main()
{
    node *h=NULL;
    int c,y,z;
    do{
            printf("enter the choice\n1.addbeg\n2.addafter\n3.addbefore\n4.append\n5.delbeg\n6.delend\n7.delany\n8.show\n9.reverse\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1 :printf("enter the element to be added\n");
                        scanf("%d",&z);
                        addbeg(&h,z);
                        break;
                case 2 :printf("enter the element after which you want to add\n");
                        scanf("%d",&y);
                        printf("enter the element to be added\n");
                        scanf("%d",&z);
                        addafter(h,y,z);
                        break;
                case 3 :printf("enter the element before which you want to add\n");
                        scanf("%d",&y);
                        printf("enter the element to be added\n");
                        scanf("%d",&z);
                        addbefore(&h,y,z);
                        break;
                case 4 :printf("enter the element to be added\n");
                        scanf("%d",&z);
                        append(&h,z);
                        break;
                case 5 :delbeg(&h);
                        break;
                case 6 :delend(&h);
                        break;
                case 7 :printf("enter the element to be deleted\n");
                        scanf("%d",&z);
                        delany(&h,z);
                        break;
                case 8 :if(h==NULL)
                            printf("list is empty\n");
                        else
                            show(h);
                        break;
                case 9 :if(h==NULL)
                            printf("list is empty\n");
                        else
                            rev(&h);
                        break;
               default :exit(1);

            }
      }while(1);
return 0;
}

