#include<iostream>
using namespace std;
class Base
{   private:
        int b;
    public:
        Base(int v)
        {   b=v;
            cout<<"\nInside Base class constructor";
        }
        int getb()
        {
            return b;
        }

};

class Derived : public Base
{   private:
        int d;
    public:
        Derived(int v1,int v2):Base(v1)
        {   d=v2;
            cout<<"\nInside Derived class Constructor";
        }

        int getd()
        {
            return d;
        }


};

 void Exception1(int i)
        {
            if(i==1)
            {
                cout<<"\nBase class Exception thrown";
                throw( Base(i));
            }
            else if(i==2)
            {
                cout<<"\nDerived class Exception thrown";
                throw(Derived(0,i));

            }
            else
            {
                cout<<"\nUnsupported Exception thrown";
                throw i;
            }
        }
int main()
{   int ch;
    while(1)
    {
        cout<<"\n Exception Menu";
        cout<<"\n 1.Base Exception";
        cout<<"\n 2.Derived Exception";
        cout<<"\n 3.Unsupported Exception";
        cout<<"\n 4.Exit";
        cout<<"\nEnter your choice";
        cin>>ch;
        try
        {
            switch(ch)
            {
                case 1:
                    Exception1(ch);
                    break;
                case 2:
                    Exception1(ch);
                    break;
                case 3:
                    Exception1(ch);
                    break;
                case 4:
                    return 0;
                    break;
                default:
                    break;
            }
        }

        catch(Derived d)
        {
            cout<<"\nDerived class Exception caught....";
            cout<<"\nValue is : "<<d.getd();
        }
        catch(Base b)
        {
            cout<<"\nBase class Exception caught....";
            cout<<"\nValue is : "<<b.getb();
        }
        catch(...)
        {
            cout<<"\nUnsupported Exception caught";
        }
    }

    return 0;
}
