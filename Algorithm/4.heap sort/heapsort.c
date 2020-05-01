#include<stdio.h>
void create_heap(int a[],int n)
{
    int i,c,p,t;
    for(i=1;i<n;i++)
    {
        c=i;
        do{
            p=(c-1)/2;
            if(a[p]<a[c])
            {
                t=a[p];
                a[p]=a[c];
                a[c]=t;
            }
            else
                break;
            c=p;
        }while(c!=0);
    }
}
build_heap(int a[],int n)
{
    int i,t;
    for(i=n-1;i>0;i--)
    {
        t=a[0];
        a[0]=a[i];
        a[i]=t;
        create_heap(a,i);
    }
}
void heap_sort(int a[],int n)
{
    create_heap(a,n);
    build_heap(a,n);
}
int main()
{
    int a[100];
    int i,n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    printf("enter array element one by one\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    heap_sort(a,n);
    printf("sotred array is\t");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}
