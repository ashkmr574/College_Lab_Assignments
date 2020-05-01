#include<stdio.h>
int main()
{
  int i;
  float x[10],total;
  printf("enter 10 real nos");
  for(i=0;i<10;i++)
    scanf("%f",&x[i]);
  total=0.0;
  for(i=0;i<10;i++)
  total=total+x[i]*x[i];
  printf("\n");
  for(i=0;i<10;i++)
    printf("x[%d] = %.2f\n",i+1,x[i]);
  printf("\ntotal=%.2f",total);
  return 0;
}
