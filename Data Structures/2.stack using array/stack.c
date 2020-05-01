#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int *a;
    int tos,size;
}stack;
void init(stack*s,int n)
{
    s->a=(int*)malloc(sizeof(int)*n);
    s->size=n;
    s->tos=-1;
}
int isfull(stack*s)
{
    if(s->tos==s->size-1)
            return 1;
    else
            return 0;
}
int isempty(stack*s)
{
    if(s->tos==-1)
            return 1;
    else
            return 0;
}
void push(stack*s,int z)
{
    if(isfull(s))
            {
                printf("stack is full\n");
                return ;
            }
    else
    {
        s->tos++;
        s->a[s->tos]=z;
    }
}
int pop(stack *s)
{
    int z;
    z=s->a[s->tos];
    s->tos--;
    return z;
}
int main()
{
    stack s;
    int d,c,n;
    printf("enter the size of stack\n");
    scanf("%d",&n);
    init(&s,n);
    do{
            printf("enter the choice\n1.push\n2.pop\n3.exit\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1 :printf("enter the element\n");
                        scanf("%d",&d);
                        push(&s,d);
                        break;
                case 2:if(!isempty(&s))
                       {
                           d=pop(&s);
                           printf("the item poped is=%d\n",d);
                       }
                       else
                            printf("no item to pop as stack is empty\n");
                       break;
                case 3:exit(1);
                default :printf("wrong input\n");
                         break;
            }
        }while(1);
        return 0;
}



