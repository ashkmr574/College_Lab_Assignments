#include<stdio.h>
#include<string.h>
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
void push(stack*s,int z)
{
    if(isfull(s)==1)
        return ;
    else
    {
        s->tos++;
        s->a[s->tos]=z;
    }
}
int isempty(stack*s)
{
    if(s->tos==-1)
        return 1;
    else
        return 0;
}
int pop(stack *s)
{
    int z;
    if(isempty(s)==1)
      return 1;
    else
    {
        z=s->a[s->tos];
        s->tos--;
        return z;
    }
}
int postfix(char a[])
{
       stack s;
       int o1,o2,r,i;
       init(&s,(strlen(a)+1)/2);
       for(i=0;a[i]!='\0';i++)
       {
             if(a[i]>='0'&&a[i]<='9')
             push(&s,a[i]-'0');
             else
            {
                o2=pop(&s);
                o1=pop(&s);
                switch(a[i])
                {
                    case '+' : r=o1+o2;
                               break;
                    case '-' : r=o2-o1;
                               break;
                    case '*' : r=o1*o2;
                               break;
                    case '/' : r=o1/o2;
                               break;
                    case '%' : r=o1%o2;
                               break;
                        }
			push(&s,r);
           }
	  }
      return pop(&s);
}
int main()
{
 char a[50];
 int d;
 printf("enter the expression");
 fgets(a,50,stdin);
 d=postfix(a);
 printf("result is=%d",d);
 return 0;
}



