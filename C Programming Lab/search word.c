#include<stdio.h>
#include<string.h>
int main()
{
char a[100],b[50];
int i,k,l=0,j=0,g=0,m;
printf("enter a sentence ");
gets(a);
printf("enter word to be found");
gets(b);
for(i=0;a[i]!='\0';i++)
{
    if(a[i]==' '&&a[i+1]!=' ')
{
k=i-1;
for(m=l;m<=k;m++)
{
if(a[m]==b[j])
{
g++;j++;
}
}
if(g==strlen(b))
{
    printf("found");
break;
}
    l=i+1;
    g=0;
    j=0;
}
    if(a[i]!=' '&&a[i+1]=='\0')
    {k=i;
    for(m=l;m<=k;m++)
    {if(a[m]==b[j])
    {g++;
    j++;
    }
    }
    if(g==strlen(b))
    {
    printf("found");
    }
    else
        printf("not found");
    }}
return 0;
}
