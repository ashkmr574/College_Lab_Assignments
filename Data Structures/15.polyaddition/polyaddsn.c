#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist
{
    int d,q;
    struct linkedlist *n;
}node;
node *cn()
{
    return (node *)malloc(sizeof(node));
}
void append(node **p,int z,int y)
{
    node *t,*r;
    t=cn();
    t->d=z;
    t->q=y;
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
    printf("result is  ");
    while(p!=NULL)
    {
        printf("%d %d\t",p->d,p->q);
        p=p->n;
    }
    printf("\n");
}
node* polyadd(node*l1,node*l2)
{
    node*l3=NULL;
    while(l1!=NULL&&l2!=NULL)
    {
        if((l1->q)>(l2->q))
        {
            append(&l3,l1->d,l1->q);
            l1=l1->n;
        }
        else if((l2->q)>(l1->q))
        {
            append(&l3,l2->d,l2->q);
            l2=l2->n;
        }
        else
        {
            append(&l3,(l1->d)+(l2->d),l1->q);
            l1=l1->n;
            l2=l2->n;
        }
    }
    while(l1!=NULL)
    {
        append(&l3,l1->d,l1->q);
        l1=l1->n;
    }
    while(l2!=NULL)
    {
        append(&l3,l2->d,l2->q);
        l2=l2->n;
    }
    return l3;
}
int main()
{
    node *l1=NULL,*l2=NULL,*l3=NULL;
    int c,y,z;
    printf("enter the expression 1\n");
    do{
            printf("enter the coefficient\n");
            scanf("%d",&z);
            printf("enter the power\n");
            scanf("%d",&y);
            append(&l1,z,y);
            printf("do you again want to enter\n1.yes\n2.no\n");
            scanf("%d",&c);
    }while(c==1);
    printf("enter the expression 2\n");
    do{
            printf("enter the coefficient\n");
            scanf("%d",&z);
            printf("enter the power\n");
            scanf("%d",&y);
            append(&l2,z,y);
            printf("do you want to enter again\n1.yes\n2.no\n");
            scanf("%d",&c);
    }while(c==1);
    l3=polyadd(l1,l2);
    show(l3);
    return 0;
}

