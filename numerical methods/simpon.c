#include<stdio.h>
#include<math.h>
float sum(float n)
{
    float temp;
    temp=sqrt(1-(0.162*pow(sin(n),2)));
    return(temp);
}
int main()
{
    int i;
    float pi;
    float h,s,s1,s2=0.0,s3=0.0,a,b,n;
    printf("Enter the value of a,b,n\n");
    scanf("%f%f%f",&a,&b,&n);
    pi=4*atan(1.0);
    b=b*pi;
    h=(b-a)/n;
    s1=sum(a)+sum(b);
    for(i=1;i<=n-1;i=i+2)
        s2=s2+sum(a+(i*h));
    for(i=2;i<=n-2;i=i+2)
        s3=s3+sum(a+(i*h));
    s=(h/3)*(s1+(s2*4)+(s3*2));
    printf("value=%f",s);
    return 0;
}
