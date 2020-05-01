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
void push(node **p,int z)
{
    node *t;
    t=cn();
    t->d=z;
    t->n=*p;
    *p=t;
}
int pop(node **p)
{
    node* t;
    int z;
    if(*p==NULL)
        printf("underflow\n");
    else
    {
        z=(*p)->d;
        t=(*p);
        *p=(*p)->n;
        free(t);
        printf("deleted item is=%d\n",z);
        return z;
    }
}
int main()
{
    node *h=NULL;
    int c,z;
    do{
            printf("enter the choice\n1.push\n2.pop\n3.exit\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1 :printf("enter the element to be added\n");
                        scanf("%d",&z);
                        push(&h,z);
                        break;
                case 2 :pop(&h);
                        break;
                case 3 :exit(1);
               default :printf("wrong input\n");
                        break;
            }
      }while(1);
      return 0;
}

