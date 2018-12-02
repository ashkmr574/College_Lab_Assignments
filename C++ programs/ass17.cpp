#include<iostream>
#include<cmath>
using namespace std;
class shape
{
public:
    double area,volume;
    virtual void area1()=0;
    virtual void volume1()=0;
    virtual void display()=0;
};
class cone:public shape
{
    double r,h,l;
public:
    cone();
    cone(double,double);
    void area1();
    void volume1();
    void display();
    void setv(double,double);
    //double getr();
    //double geth();
};
class cube:public shape
{
    double s;
public:
    cube();
    cube(double);
    void volume1();
    void display();
    void area1();
    void setv(double);
    //double gets();
};
cone::cone()
{
    r=0.0;
    h=0.0;
}
cube::cube()
{
    s=0.0;
}
cone::cone(double r,double h)
{
    this->r=r;
    this->h=h;
    this->l=sqrt(pow((this->r),2)+pow((this->h),2));
}
cube::cube(double s)
{
    this->s=s;
}
void cube::setv(double s)
{
    this->s=s;
}
void cone::setv(double r,double h)
{
    this->r=r;
    this->h=h;
    this->l=sqrt(pow((this->r),2)+pow((this->h),2));
}
void cone::area1()
{
    area= 3.14*r*(r+l);
    cout<<"area="<<area<<endl;
}
void cube::area1()
{
    area= 6*(s*s);
    cout<<"area="<<area<<endl;
}
void cube::volume1()
{
    volume= pow(s,3);
    cout<<"volume="<<volume<<endl;
}
void cone::volume1()
{
    volume=(3.14/3)*r*r*h;
    cout<<"volume="<<volume<<endl;
}
void cube::display()
{
	cout<<"shape = Cube "<<"Area= " <<area<<" volume="<<volume<<endl;
}
void cone::display()
{
	cout<<"shape = Cone "<<"Area= " <<area<<" volume="<<volume<<endl;
}
int main()
{
    double s,r,h;
    int i=0,c1,j;
    shape **a=new shape*[150];
    //cube a1[150];
    do
    {
        cout<<"1.Cube(area and volume)\n2.Cone(area and volume)\n3.show entire list\n4.Exit\n";
        cin>>c1;
        switch(c1)
        {
            case 1:cout<<"Enter the size of cube\n";
                   cin>>s;
                   {
                       a[i]=new cube(s);
                       a[i]->area1();
                       a[i]->volume1();
                       i++;
                   }
                   break;
            case 2:cout<<"Enter base radius and height of cone\n";
                   cin>>r>>h;
                    {
                      a[i]=new cone(r,h);
                       a[i]->area1();
                       a[i]->volume1();
                       i++;
                    }
                   break;
            case 3:for(j=0;j<i;j++)
            			a[j]->display();
            		break;
            case 4:return 0;
            default:cout<<"Invalid Choice\n";
        }
    }while(true);
    return 0;
}
