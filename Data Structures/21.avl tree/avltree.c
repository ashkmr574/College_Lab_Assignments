#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    int d,b;
    struct tree *l,*r;
}tree;
tree* cn()
{
	return((tree*)malloc(sizeof(tree)));
}
void lrotate(tree **root)
{
    tree *t;
    t=((*root)->r)->l;
    ((*root)->r)->l=(*root);
    (*root)=(*root)->r;
    ((*root)->l)->r=t;
}
void rrotate(tree **root)
{
    tree *t;
    t=((*root)->l)->r;
    ((*root)->l)->r=(*root);
    (*root)=(*root)->l;
    ((*root)->r)->l=t;
}
int depth(tree*root)
{
    int hl,hr;hr=hl=0;
    if(root!=NULL)
    {
        if(root->l!=NULL)
            hl=depth(root->l);
        if(root->r!=NULL)
            hr=depth(root->r);
        return (1+(hl>hr?hl:hr));
    }
    else
        return 0;
}
void bfactor(tree *root)
{
    int lh,rh;
    if(root!=NULL)
    {
        lh=depth(root->l);
        rh=depth(root->r);
        root->b=(lh-rh);
        bfactor(root->l);
        bfactor(root->r);
    }
}
void bnode(tree **root)
{
    bfactor(*root);
    if(((*root)->b)>1)
    {
        if((((*root)->l)->b)<0)
            lrotate(&(*root)->l);
        rrotate(root);
        bfactor(*root);
    }
    else if(((*root)->b)<(-1))
    {
        if((((*root)->r)->b)>0)
            rrotate(&(*root)->r);
        lrotate(root);
        bfactor(*root);
    }
}
void insert(tree **root,int z)
{
    if(*root==NULL)
    {
            *root=cn();
            (*root)->d=z;
            (*root)->l=(*root)->r=NULL;
            (*root)->b=0;
    }
    else if(z<(*root)->d)
            insert(&(*root)->l,z);
    else
            insert(&(*root)->r,z);
    bnode(root);
}
tree *search(tree*root,int z)
{
    if(root==NULL)
        return;
    else
    {
        if(root->d==z)
            return root;
        else if((root->d)>z)
            return search(root->l,z);
        else
            return search(root->r,z);
    }
 }
 tree *findmin(tree *root)
 {
    while(root->l!=NULL)
            root=root->l;
    return root;
 }
 void delnode(tree **root,int z)
 {
 	tree *t;
    if(z<(*root)->d)
    {
            delnode(&((*root)->l),z);
            bnode(root);
    }
    else if(z>(*root)->d)
           {
                delnode(&((*root)->r),z);
                bnode(root);
           }
    else
    {
        if(((*root)->l!=NULL)&&((*root)->r!=NULL))
        {
            t=findmin((*root)->r);
            (*root)->d=t->d;
            delnode(&((*root)->r),t->d);
            bnode(root);
        }
        else
        {
            t=*root;
            if(((t->l)==NULL)&&((t->r)==NULL))
                    *root=NULL;
            else if(((t->l)!=NULL)&&((t->r)==NULL))
            {
                *root=(*root)->l;
                bnode(root);
            }
            else
            {
                *root=(*root)->r;
                bnode(root);
            }
            free(t);
        }
    }
}
tree* preorder(tree*root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->d);
		if(root->l!=NULL)
			preorder(root->l);
		if(root->r!=NULL)
			preorder(root->r);
	}
	else
    {
        printf("empty tree\n");
		return;
    }
}
tree*postorder(tree*root)
{
	if(root!=NULL)
	{
		if(root->l!=NULL)
			postorder(root->l);
		if(root->r!=NULL)
			postorder(root->r);
		printf("%d\t",root->d);
	}
    else
    {
        printf("empty tree\n");
		return;
    }
}
inorder(tree*root)
{
	if(root!=NULL)
	{
		if(root->l!=NULL)
			inorder(root->l);
		printf("%d\t",root->d);
		if(root->r!=NULL)
			inorder(root->r);
	}
	else
    {
        printf("empty tree\n");
		return;
    }
}
int main()
{
	tree *root=NULL,*t;
	int c,z,y=0;
	t=NULL;
	do{
		printf("\nenter the choice\n1.insert\n2.search\n3.findmin\n4.preorder\n5.postorder\n6.inorder\n7.delete\n8.depth\n9.exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("enter the element to be inserted\n");
			       scanf("%d",&z);
			       insert(&root,z);
			       break;
			case 2:printf("enter the element to be searched\n");
			       scanf("%d",&z);
			       t=search(root,z);
			       if(t!=NULL)
			       	  printf("element found\n");
			       else
			       	  printf("element not found\n");
			       break;
			case 3:t=findmin(root);
			       printf("minimum element is=%d\n",t->d);
			       break;
			case 4:preorder(root);
				break;
			case 5:postorder(root);
				break;
			case 6:inorder(root);
				break;
			case 7:if(root==NULL)
				  printf("empty tree\n");
			       else
			       {
			       	  printf("enter the element to be deleted\n");
			       	  scanf("%d",&z);
			       	  t=search(root,z);
			       	  if(t!=NULL)
                            delnode(&root,z);
                      else
                        printf("element not found you want to delete\n");
			       }
			       break;
			 case 8:y=depth(root);
			 	printf("depth=%d\n",y);
			 	break;
			 case 9:exit(1);
			 default:printf("wrong input\n");
			 	break;
		}
	}while(1);
	return 0;
}


