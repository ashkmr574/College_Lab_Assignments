#include<iostream>
#include<cstdio>
using namespace std;
class Staff
{
    string name;
    int code;
public:
    Staff(){};
    Staff(string,int);
    int getcode()
    {
        return code;
    }
    string getname()
    {
        return name;
    }
};
class Officer:public Staff
{
    string grade;
public:
    Officer(){};
    Officer(string,int,string);
    friend int chk(Officer [],int,int);
    void display();
};
class Teacher:public Staff
{
    string subject;
public:
    Teacher(){};
    Teacher(string,int,string);
    friend int chk(Teacher [],int,int);
    void display();
};
class Typist:public Staff
{
    int speed;
public:
    Typist(){};
    Typist(string,int,int);
    int getspeed()
    {
        return speed;
    }
};
class CasualTypist:public Typist
{
    int dw;
public:
    CasualTypist(){};
    CasualTypist(string,int,int,int);
    friend int chk(CasualTypist [],int,int);
    void display();
};
class RegularTypist:public Typist
{
    int rum;
public:
    RegularTypist(){};
    RegularTypist(string,int,int,int);
    friend int chk(RegularTypist [],int,int);
    void display();
};
Staff::Staff(string n,int c)
{
    name=n;
    code=c;
}
Officer::Officer(string n,int c,string g):Staff(n,c)
{
    grade=g;
}
Teacher::Teacher(string n,int c,string g):Staff(n,c)
{
    subject=g;
}
Typist::Typist(string n,int c,int g):Staff(n,c)
{
    speed=g;
}
CasualTypist::CasualTypist(string n,int c,int g1,int g2):Typist(n,c,g1)
{
    dw=g2;
}
RegularTypist::RegularTypist(string n,int c,int g1,int g2):Typist(n,c,g1)
{
    rum=g2;
}
int chk(Officer a[],int i,int c)
{
    int l=-1,k;
    for(k=0;k<i;k++)
        if(a[k].getcode()==c)
            return k;
    return l;
}
int chk(Teacher a[],int i,int c)
{
    int l=-1,k;
    for(k=0;k<i;k++)
        if(a[k].getcode()==c)
            return k;
    return l;
}
int chk(RegularTypist a[],int i,int c)
{
    int l=-1,k;
    for(k=0;k<i;k++)
        if(a[k].getcode()==c)
            return k;
    return l;
}
int chk(CasualTypist a[],int i,int c)
{
    int l=-1,k;
    for(k=0;k<i;k++)
        if(a[k].getcode()==c)
            return k;
    return l;
}
void Officer::display()
{
    cout<<"  name= "<<getname()<<"  code= "<<getcode()<<"  Grade= "<<grade<<endl;
}
void Teacher::display()
{
    cout<<"name= "<<getname()<<"  code= "<<getcode()<<"  subject= "<<subject<<endl;
}
void CasualTypist::display()
{
    cout<<"name= "<<getname()<<"  code= "<<getcode()<<"  speed= "<<getspeed()<<"  remuneration= "<<dw<<endl;
}
void RegularTypist::display()
{
    cout<<"name= "<<getname()<<"  code= "<<getcode()<<"  speed= "<<getspeed()<<"  daily wages= "<<rum<<endl;
}
bool find1(int a[],int n,int code)
{
    int i;
    for(i=0;i<n;i++)
        if(a[i]==code)
            return true;
    return false;
}
int main()
{
    int c,c1,code,rem,sp;
    string s,s1;
    //Staff **a=new Staff*[150];
    Officer a[100];
    Teacher b[100];
    CasualTypist c2[100];
    RegularTypist d[100];
    int cd[100];
    int i=0,j=0,k=0,l=0,m,n=0;
    do
    {
        cout<<"1.INPUT DETAILS\n2.CHECK DETAIL\n3.EXIT\n";
        cin>>c;
        switch(c)
        {
            case 1:cout<<"1.Officer\n2.Teacher\n3.Regular Typist\n4.Casual Typist\n";
                    cin>>c1;
                    getchar();
                    if((c1<5)&&(c1>0))
                    {
                    	cout<<"Enter name\n";
                    	getline(cin,s);
                    	cout<<"Enter code\n";
                    	cin>>code;
                    	if(find1(cd,n,code))
                    	{
                        		cout<<"this code already exists..\n";
                        		break;
                    	}
                    	else
                        		cd[n++]=code;
                    }
                    switch(c1)
                    {
                        case 1:cout<<"Enter Grade"<<endl;
                               getchar();
                               getline(cin,s1);
                               {
                                   Officer ob(s,code,s1);
                                    a[i++]=ob;
                               }
                               break;
                        case 2:cout<<"Enter subject"<<endl;
                               getchar();
                               getline(cin,s1);
                               {
                                   Teacher ob(s,code,s1);
                                    b[j++]=ob;
                               }
                               break;
                        case 3:cout<<"Enter speed\n";
                               cin>>sp;
                               cout<<"Enter remuneration\n";
                               cin>>rem;
                               {
                                   RegularTypist ob(s,code,sp,rem);
                                   d[k++]=ob;
                               }
                               break;
                        case 4:cout<<"Enter speed\n";
                               cin>>sp;
                               cout<<"Enter daily wages\n";
                               cin>>rem;
                               {
                                   CasualTypist ob(s,code,sp,rem);
                                   c2[l++]=ob;
                               }
                               break;
                        default:cout<<"INVALID INPUT\n";
                    }
                    break;
            case 2:cout<<"Enter code\n";
                   cin>>code;
                   m=chk(a,i,code);
                   if(m!=(-1))
                        a[m].display();
                  else
                  {
                        m=chk(b,j,code);
                        if(m!=(-1))
                                b[m].display();
                        else
                        {
                            m=chk(c2,l,code);
                            if(m!=(-1))
                                c2[m].display();
                            else
                            {
                                m=chk(d,k,code);
                                if(m!=(-1))
                                    d[m].display();
                                else
                                    cout<<"Details not exists"<<endl;
                            }
                        }
                    }
                   break;
            case 3:return 0;
            default:cout<<"INVALID INPUT\n";
        }
    }while(true);
    return 0;
}

