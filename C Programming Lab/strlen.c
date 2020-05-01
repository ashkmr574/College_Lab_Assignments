#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{

    char a[100],b[100];
    int i;
    printf("enter array\n");
    gets(a);
    //scanf("%s",a);
    tolower(a);
    printf("%d %s",strlen(a),a);
    return 0;
}
