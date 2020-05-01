#include<stdio.h>
#include<math.h>
float cal(float x)
{
	float t;
	t=(x*x)-8;
	return t;
}
float cal2(float x)
{
	float t;
	t=2*x;
	return t;
}
int main()
{
	float a,x,b,c,h,i,eps;
	eps=0.000001;
	for(i=0;i<=100;i++)
	{
		if((cal(i)*cal(i+1))<0)
		{
			a=i;
			b=i+1;
			break;
		}
	}
	c=(a+b)/2;
	x=c;
	do{
		h=(-1)*(cal(x)/cal2(x));
		x=x+h;
	}while(fabs(h)>eps);
	printf("%0.4f",x);
	return 0;
}

