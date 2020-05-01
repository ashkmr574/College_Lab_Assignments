#include<stdio.h>
main()
{
    int row,col,i,j,p;
    printf("--------MULTIPLICATION TABLE-----------------------\n");
    printf("---------------------------------------------------\n");
    for(i=0;i<100;i++)
    {
        row=i+1;
        for(j=0;j<10;j++)
        {
            col=j+1;
        p=row*col;
        printf("%4d ",p);
    }

    printf("\n");
    printf("-----------------------------------------------------\n");
    }
    return 0;
}
