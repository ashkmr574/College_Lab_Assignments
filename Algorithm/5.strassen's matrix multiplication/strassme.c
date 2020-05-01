#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int **s;
    int r,c,i1,j1;
}matrix;
int **init(int x,int y)
{
    int i,j;
    int **a=(int**)malloc(x*sizeof(int*));
    for(i=0;i<x;i++)
        a[i]=(int*)malloc(y*sizeof(int));
    return a;
}
matrix add(matrix x,matrix y)
{
	int i,j;
	matrix z={init(x.r,x.c),x.r,x.c,0,0};

	for(i=0;i<z.r;i++)
		for(j=0;j<z.c;j++)
			z.s[i][j]=x.s[i+x.i1][j+x.j1]+y.s[i+y.i1][j+y.j1];
	return z;
}
matrix sub(matrix x,matrix y)
{
	int i,j;
	matrix z={init(x.r,x.c),x.r,x.c,0,0};

	for(i=0;i<z.r;i++)
		for(j=0;j<z.c;j++)
			z.s[i][j]=x.s[i+x.i1][j+x.j1]-y.s[i+y.i1][j+y.j1];

	return z;
}
matrix cut(matrix x,int i1,int j1,int r,int c)
{
	matrix z={x.s,r,c,i1,j1};
	return z;
}
void insert(matrix *d,int i1,int j1,matrix s1)
{
	int i,j;
	for(i=0;i<s1.r;i++)
		for(j=0;j<s1.c;j++)
			d->s[i+i1][j+j1]=s1.s[i+s1.i1][j+s1.j1];
}
matrix mult(matrix x,matrix y)
{
	if(x.r==1 || y.c==1)
	{
		matrix z={ init(1,1),1,1,0,0 };
		z.s[0][0]=x.s[x.i1][x.j1]*y.s[y.i1][y.j1];
		return z;
	}
    matrix A[2][2]=
	{
		cut(x,x.i1,x.j1,x.r/2,x.c/2),
		cut(x,x.i1,x.j1+x.c/2,x.r/2,x.c/2),
		cut(x,x.i1+x.r/2,x.j1,x.r/2,x.c/2),
		cut(x,x.i1+x.r/2,x.j1+x.c/2,x.r/2,x.c/2)
	};

	matrix B[2][2]=
	{
		cut(y,y.i1,y.j1,y.r/2,y.c/2),
		cut(y,y.i1,y.j1+y.c/2,y.r/2,y.c/2),
		cut(y,y.i1+y.r/2,y.j1,y.r/2,y.c/2),
		cut(y,y.i1+y.r/2,y.j1+y.c/2,y.r/2,y.c/2)
	};

	matrix C[2][2];
	matrix P,Q,R,S,T,U,V;

	P=mult(add(A[0][0],A[1][1]),add(B[0][0],B[1][1]));
	Q=mult(add(A[1][0],A[1][1]),B[0][0]);
	R=mult(A[0][0],sub(B[0][1],B[1][1]));
	S=mult(A[1][1],sub(B[1][0],B[0][0]));
	T=mult(add(A[0][0],A[0][1]),B[1][1]);
	U=mult(sub(A[1][0],A[0][0]),add(B[0][0],B[0][1]));
	V=mult(sub(A[0][1],A[1][1]),add(B[1][0],B[1][1]));

	C[0][0]=add(P,add(sub(S,T),V));
	C[0][1]=add(R,T);
	C[1][0]=add(Q,S);
	C[1][1]=add(P,add(sub(R,Q),U));

	matrix z={init(x.r,y.c),x.r,y.c,0,0};


	insert(&z,0,0,C[0][0]);
	insert(&z,0,y.c/2,C[0][1]);
	insert(&z,x.r/2,0,C[1][0]);
	insert(&z,x.r/2,y.c/2,C[1][1]);

	return z;
}
matrix takeinput()
{
    int i,j;
	matrix x;

	printf("Enter dimension no of rows and col: ");
	scanf("%d%d",&x.r,&x.c);
	x.s=init(x.r,x.c);
	printf("Enter values :\n");

	for(i=0;i<x.r;i++)
		for(j=0;j<x.c;j++)
			scanf("%d",&x.s[i][j]);
	x.i1=x.j1=0;
	return x;
}
int main()
{
    int i,j;
    matrix a,b,c1;
    printf("Enter first Matrix :\n");
    a=takeinput();
    printf("Enter second Matrix :\n");
	b=takeinput();
	c1=mult(a,b);
    printf("Multiplication is :\n");
    for(i=0;i<c1.r;i++,printf("\n"))
		for(j=0;j<c1.c;j++)
			printf("%2d ",c1.s[i][j]);
    return 0;
}
