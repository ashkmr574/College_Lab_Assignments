#include <stdlib.h>
typedef struct tree
{
	int v;
	struct tree *l,*r;
} tree;
typedef struct llist
{
   tree* d;
   struct llist *n;
}*stack;
int isempty(stack *s)
{
    if(*s==NULL)
    return 1;
    else
        return 0;
}
void push(stack *s,int v)
{
    stack t;
    t=malloc(sizeof(*t));
    t->d=v;
    t->n=*s;
    *s=t;
}
tree* pop(stack *s)
{
    if(!isempty(s))
    {
        stack t=*s;
        int z;
        z=t->d;
        *s=(*s)->n;
        free(t);
        return z;
    }
}
tree* peak(stack *s)
{
	if(*s)
 		return (*s)->d ;
}
int pr(char ch)
{
if(ch=='*'||ch=='/'||ch=='%')
return 3;
else if
(ch=='+'||ch=='-')
return 2;
else
return 1;
}
int eval(tree *rt)
{
	if((rt->v)>='0'&&(rt->v)<='9')
		return rt->v -'0' ;
	else switch(rt->v)
	{
		case '+' : return eval(rt->l)+eval(rt->r)	;
		case '-' : return eval(rt->l)-eval(rt->r)	;
		case '*' : return eval(rt->l)*eval(rt->r)	;
		case '/' : return eval(rt->l)/eval(rt->r)	;
	}
}
inorder(tree*root)
{
    char c;
	if(root!=NULL)
	{
        if(root->v=='/'||root->v=='*'||root->v=='+'||root->v=='-'||root->v=='%')
            printf("(");
		if(root->l!=NULL)
			inorder(root->l);
		if(((root->v)-'0')>=0)
            printf("%d",(root->v)-'0');
		else
         {
             c=(char)(root->v);
             printf("%c",c);
         }
		if(root->r!=NULL)
			inorder(root->r);
        if(root->v=='/'||root->v=='*'||root->v=='+'||root->v=='-'||root->v=='%')
            printf(")");
	}
	else
    {
        printf("empty tree\n");
		return;
    }
}
preorder(tree*root)
{
    char c;
	if(root!=NULL)
	{
	    if(((root->v)-'0')>=0)
            printf("%d",(root->v)-'0');
		else
         {
             c=(char)(root->v);
             printf("%c",c);
         }
		if(root->l!=NULL)
			preorder(root->l);
		if(root->r!=NULL)
			preorder(root->r);
	}
}
postorder(tree*root)
{
    char c;
	if(root!=NULL)
	{
		if(root->l!=NULL)
			postorder(root->l);
		if(root->r!=NULL)
			postorder(root->r);
		if(((root->v)-'0')>=0)
            printf("%d",(root->v)-'0');
		else
         {
             c=(char)(root->v);
             printf("%c",c);
         }
    }
}
insert(stack *trp,stack *opp)
{
	tree *o	;

	o=pop(opp);

	o->r=pop(trp);
	o->l=pop(trp);

	push(trp,o);
}
tree *convert(char *ip)
{
	stack tr=0,op=0;
	tree *t;
	while(*ip)
	{
		t=malloc(sizeof(tree));
		t->v=(*ip);
		t->l=t->r=0;
        if((*ip)>='0'&&*ip<='9')
                push(&tr,t);
		else switch(*ip)
		{
			case '(' :
						push(&op,t);
						break;

			case ')' :
						while((peak(&op)->v)!='(' )
							insert(&tr,&op);
						pop(&op);
						break;
			default  :
						while(!isempty(&op) && pr(*ip) <= pr(peak(&op)->v))
							insert(&tr,&op);
						push(&op,t);
						break;

        }

		ip++;
	}

	while(!isempty(&op))
		insert(&tr,&op);

	return pop(&tr);
}
int main()
{
    char a[100];
    int i;
    tree *t;
    int c;
    printf("enter infix expression\n");
    gets(a);
    t=convert(a);
    do{
            printf("\nenter your choce\n1.inorder traversal\n2.preorder traversal\n3.postorder traversal\n4.evaluation\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:inorder(t);
                       break;
                case 2:preorder(t);
                       break;
                case 3:postorder(t);
                       break;
                case 4:i=eval(t);
                       printf("answer is=%d\n",i);
                       break;
                default:exit(1);
            }
      }while(1);
    return 0;
}
