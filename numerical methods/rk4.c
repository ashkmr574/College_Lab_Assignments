#include<stdio.h>
#include<math.h>
float fun(float x, float y)
{
    float temp;
    temp= (x*x)+(y*y*x);
    return(temp);
}
int main()
{
    float x0,y0,x,y,h,xn,k1,k2,k3,k4;
    printf("Enter the value of x0,y0,h,xn\n");
    scanf("%f%f%f%f",&x0,&y0,&h,&xn);
    x=x0;
    y=y0;
    do{
        k1=h*fun(x,y);
        k2=h*fun(x+(h/2.0),y+(k1/2.0));
        k3=h*fun(x+(h/2.0),y+(k2/2.0));
        k4=h*fun(x+h,y+k3);
        y=y+((1/6.0)*(k1+(2*k2)+(2*k3)+k4));
        x=x+h;
    }while(x<xn);
    printf("%.4f\n",y);
    return 0;
}
