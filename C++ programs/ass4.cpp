#include<iostream>
using namespace std;
typedef struct
{
    int date,month,year;
}date1;
int operator-(date1 d1,date1 d2)
{
    int d=0;
    if(d1.date>=d2.date)
        d+=(d1.date-d2.date);
    else
    {
        d+=30+(d1.date-d2.date);
        d1.month--;
    }
    if(d1.month>=d2.month)
        d+=(d1.month-d2.month)*30;
    else
    {
        d+=(12+(d1.month-d2.month))*30;
        d1.year--;
    }
    d+=(d1.year-d2.year)*365;
    return d;

}
int main()
{
    date1 d1,d2;
    int d;
    cout<<"enter the  first date month and year respectively\n";
    cin>>d1.date>>d1.month>>d1.year;
    cout<<"enter the second date month and year respectively\n";
    cin>>d2.date>>d2.month>>d2.year;
    d=d2-d1;
    cout<<"difference="<<d<<" days"<<endl;
    return 0;
}
