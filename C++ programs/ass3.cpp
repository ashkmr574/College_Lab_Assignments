#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef struct str{
    //string s;
    char* s;
}str;
str operator+(str s1,str s2)
{
    str s3;
    int i,l,l1,j;
    l1=strlen(s1.s);
    l=l1+strlen(s2.s);
    s3.s=new char[l];
    //cout<<l<<"\n";
    for(i=0;i<l1;i++)
        s3.s[i]=s1.s[i];
    for(j=0;i<l;i++,j++)
        s3.s[i]=s2.s[j];
        s3.s[i]='\0';
    //s3.s=(char*)((string)""+s1.s+s2.s).c_str();
    //s3.s=s1.s+s2.s;
    return s3;
}
int main()
{
    int a,b,sum;
    float c,d,e;
    str s1,s2,s3;
    s1.s=new char[255];
    s2.s=new char[255];
    cout<<"ENTER TWO INTEGER NUMBERS TO ADD\n";
    cin>>a>>b;
    cout<<"ENTER TWO FLOAT NUMBERS TO ADD\n";
    cin>>c>>d;
    cout<<"ENTER FIRST STRING\n";
    getchar();
    cin.getline(s1.s,255);
    cout<<"ENTER SECOND STRING\n";
    cin.getline(s2.s,255);
    sum=a+b;
    cout<<"sum of two integers is= "<<sum<<"\n";
    e=c+d;
    cout<<"sum of two floating type numbers is= "<<e<<"\n";
    s3=s1+s2;
    cout<<"resultant string = "<<s3.s<<"\n";
    return 0;

}
