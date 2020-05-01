#include<stdio.h>
float sqr(float x)
{
   return(x*x);
}
int main()
{
   int i;
   float a,b,n,h,s1,s,s2=0;
   printf("Enter the value of a,b and n respectinely\n");
   scanf("%f%f%f",&a,&b,&n);
   h=(b-a)/n;
   s1=sqr(a)+sqr(b);
   for(i=1;i<=n-1;i++)
   {
      s2=s2+sqr(a+(i*h));
   }
   s=(h/2)*(s1+(2*s2));
   printf("%.4f",s);
   return 0;
}
