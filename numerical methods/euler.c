#include<stdio.h>
float fun(float x, float y)
{
    return(x-y);
     //return((x*x)+(y*y*x));
     //return((y-x)/(y+x));
}
int main()
{
    float x0,y0,x,y,h,xn;
    printf("Enter the value of x0,y0,h,xn\n");
    scanf("%f%f%f%f",&x0,&y0,&h,&xn);
    x=x0;
    y=y0;
    do{
        y=y+(h*fun(x,y));
        printf("%f\n",y);
        x=x+h;
    }while(x<xn);
    printf("%.4f\n",y);
    return 0;
}
