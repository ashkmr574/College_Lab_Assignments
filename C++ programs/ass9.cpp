#include<iostream>
using namespace std;
class complex
{
    float r,i;
public:
    complex(){};
    complex(int,int);
    complex operator+(const complex&);
    complex operator-(const complex&);
    complex operator*(const complex&);
    bool operator==(const complex&);
    void get();
};
void complex::get()
{
    cout<<r<<"+"<<i<<"i\n";
}
complex::complex(int r,int i)
{
    this->r=r;
    this->i=i;
}
complex complex::operator+(const complex &c)
{
    complex c3;
    c3.r=(this->r)+c.r;
    c3.i=(this->i)+c.i;
    return c3;
}
complex complex::operator-(const complex &c)
{
    complex c3;
    c3.r=(this->r)-c.r;
    c3.i=(this->i)-c.i;
    return c3;
}
complex complex::operator*(const complex &c)
{
        complex c3;
        c3.r=(this->r)*(c.r)-(this->i)*(c.i);
        c3.i=(this->r)*(c.i)+(this->i)*(c.r);
        return c3;
}
bool complex::operator==(const complex &c)
{
    if(((this->r)==c.r)&&((this->i)==c.i))
        return true;
    else
        return false;
}
int main()
{
    complex c3;
    int c,r,i;
    bool f1,f2=true;
    cout<<"Enter real and imaginary part of no 1\n";
    cin>>r>>i;
    complex c1(r,i);
    cout<<"Enter real and imaginary part of no 2\n";
    cin>>r>>i;
    complex c2(r,i);
    do{
        cout<<"Enter your choice\n1.addition\n2.subtraction\n3.multiplication\n4.equality\n5.break;\n";
        cin>>c;
        switch(c)
        {
            case 1:c3=c1+c2;
                   c3.get();
                    break;
            case 2:c3=c1-c2;
                   c3.get();
                   break;
            case 3:c3=c1*c2;
                   c3.get();
                   break;
            case 4:if(c1==c2)
                      cout<<"both are equal\n";
                   else
                      cout<<"not equal\n";
                   break;
            case 5:return 0;
            default:cout<<"invalid input\n";
        }
    }while(true);
    return 0;
}
