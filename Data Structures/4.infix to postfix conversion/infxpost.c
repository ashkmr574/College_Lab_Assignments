#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
  char *a;
  int tos,size;
}stack;
void init(stack*s,int n)
{
  s->a=(char*)malloc(sizeof(char)*n);
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
void push(stack*s,char z)
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
char pop(stack *s)
{
    char z;
    if(isempty(s)==1)
      return 1;
    else
    {
      z=s->a[s->tos];
      s->tos--;
      return z;
    }
}
char peak(stack *s)
{
    char z;
    if(isempty(s))
    return 1;
    else
	{
        z=s->a[s->tos];
        return z;
	}
}
int pr(char ch)
{
    if(ch=='*'||ch=='/'||ch=='%')
        return 3;
    else if(ch=='+'||ch=='-')
        return 2;
    else
        return 1;
}
char* postfix(char a[])
{
	static char b[100];
	stack s;
	int i,j;
	char z;
	init(&s,strlen(a));
	for(j=0,i=0;a[i]!='\0';i++)
	{
		if(a[i]>='a'&&a[i]<='z')
		b[j++]=a[i];
		else
		{
			switch(a[i])
			{
			case '(' : push(&s,a[i]);
			break;
			case ')' : while((z=pop(&s))!='(')
				   b[j++]=z;
		        break;
		        default : while((!isempty(&s)&&pr(peak(&s))>=pr(a[i])))
			           b[j++]=pop(&s);
			           push(&s,a[i]);
			}
	          }
         }
         while(!isempty(&s))
               b[j++]=pop(&s);
               b[j]='\0';
               return b;
}
int main()
{
    char a[100];
    printf("enter expression");
    gets(a);
    puts(postfix(a));
    return 0;
}








