#include<stdio.h>
#include<math.h>
float cal(float x)
{
	float t;
	t=(x*x*x)-(5*x)+1;
	return t;
}
int main()
{
	float a,x,b,c1,h,i,eps;x=0;
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
	do{
		c1=x;
		x=(a*cal(b)-b*cal(a))/(cal(b)-cal(a));
		if((cal(i)*cal(i+1))<0)
			a=x;
		else
			b=x;
	}while(fabs(c1-x)>eps);
	printf("%0.4f",x);
	return 0;
}
