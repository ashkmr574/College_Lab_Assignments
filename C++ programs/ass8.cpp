#include<iostream>
#include<cmath>
using namespace std;
class cone
{
    float h,r,area,vol;
public:
    cone();
    cone(float,float);
    cone(const cone&);
    void area1();
    void volume();
    void display();
};
cone::cone()
{
    this->h=10;
    this->r=7;
}
cone::cone(float h,float r)
{
    this->h=h;
    this->r=r;
}
cone::cone(const cone& s)
{
    this->h=s.h;
    this->r=s.r;
}
void cone::area1()
{
    float l;
    l=sqrt((h*h)+(r*r));
    this->area=3.14*r*(l+r);
}
void cone::volume()
{
    this->vol=(1/3.0)*3.14*r*r*h;
}
void cone::display()
{
    cout<<"area= "<<this->area<<" ";
    cout<<"volume= "<<this->vol<<"\n";
}
int main()
{
    cone c1;
    float r,h;
    cout<<"Enter the height and radius of cone"<<endl;
    cin>>h>>r;
    cone c2(h,r);
    cone c3(c2);
    c1.area1();
    c2.area1();
    c3.area1();
    c1.volume();
    c2.volume();
    c3.volume();
    c1.display();
    c2.display();
    c3.display();
    return 0;
}
