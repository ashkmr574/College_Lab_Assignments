#include<stdio.h>
float sum(float n)
{
    return(1/(1+n*n));
}
int main()
{
    int i;
    float h,s,s1=0.0,s2=0.0,s3=0.0,s4=0.0,a,b,n,sf=0.0;
    printf("Enter the value of a,b,n\n");
    scanf("%f%f%f",&a,&b,&n);
    h=(b-a)/n;
    s=sum(a)+sum(b);
    for(i=0;i<=n-6;i=i+6)
    {
        s1=s1+sum(a+(i+2)*h)+sum(a+(i+4)*h);
        s2=s2+sum(a+(i+1)*h)+sum(a+(i+5)*h);
        s3=s3+sum(a+(i+3)*h);
    }
    for(i=0;i<=n-12;i=i+6)
        s4=s4+sum(a+(i+6)*h);
    sf=(3*h/10)*(s+s1+(s2*5)+(s3*6)+(s4*2));
    printf("value=%.4f\n\n",sf);
    return 0;
}
