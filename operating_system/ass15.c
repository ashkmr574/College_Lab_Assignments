#include<stdio.h>
#include<signal.h>
void hello(int i)
{
    printf("interruped occured with signal number %d\n",i);
    signal(SIGINT,SIG_DFL);
}
int main()
{
    signal(SIGINT,hello);
    while(1)
    {
        printf("no interrupt\n");
        sleep(1);
    }
    return 0;
}
