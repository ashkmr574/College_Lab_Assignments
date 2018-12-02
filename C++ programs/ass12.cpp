#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
class Cartesian
{
	double x,y;
public:
	Cartesian(){};
	Cartesian(const Cartesian&);
	void setx(double x)
	{
		this->x=x;
	}
	void sety(double y)
	{
		this->y=y;
	}
	double getx()
	{
		return this->x;
	}
	double gety()
	{
		return this->y;
	}
	double operator-(const Cartesian&);
	bool operator==(const Cartesian&);
	bool operator!=(const Cartesian &);
     friend istream & operator >> (istream&, Cartesian& );
     friend ostream & operator << (ostream&, const Cartesian& );
};
class Polar
{
	double r,o;
public:
	Polar(){};
	Polar(const Polar&);
	double operator-(Polar&);
	bool operator==(const Polar&);
	bool operator!=(const Polar&);
	bool operator==(Cartesian &);
	Polar(Cartesian &);
	operator Cartesian();
	friend istream & operator >> (istream&, Polar& );
    	friend ostream & operator << (ostream&, const Polar& );
    	friend bool operator==(Cartesian,Polar);

};
double Polar::operator-(Polar &p)
{
     double ans;
	Cartesian c1,c2;
	c1=(Cartesian)(*this);
	c2=(Cartesian)p;
	ans=c1-c2;
	return ans;
}
bool Polar::operator==(Cartesian & c)
{
	Polar p=(Polar)c;
	if((this->r)==p.r)
	{
		if(fabs((this->o)-p.o)<=0.0001)
			return true;
		else
			return false;
	}
	else
		return false;
}
bool operator==(Cartesian c,Polar p1)
{
	Polar p=(Polar)c;
	if((p1.r)==p.r)
	{
		if(fabs((p1.o)-p.o)<=0.0001)
			return true;
		else
			return false;
	}
	else
		return false;
}
Polar::Polar(Cartesian &c)
{
	double x,y;
	x=c.getx();
	y=c.gety();
	this->r=sqrt(pow(x,2)+pow(y,2));
	this->o=atan(y/x);
}
Polar::operator Cartesian()
{

    Cartesian c;
    double x,y;
    x=(this->r)*cos(this->o);
    y=(this->r)*sin(this->o);
    c.setx(x);
    c.sety(y);
    return c;
}
Cartesian::Cartesian(const Cartesian& o)
{
    this->x=o.x;
    this->y=o.y;
}
Polar::Polar(const Polar& o1)
{
    this->r=o1.r;
    this->o=o1.o;
}
bool Cartesian::operator==(const Cartesian &c)
{
	if(((this->x)==c.x)&&((this->y)==c.y))
		return true;
	else
		return false;
}
bool Cartesian::operator!=(const Cartesian &c)
{
	if(((this->x)==c.x)&&((this->y)==c.y))
		return false;
	else
		return true;
}
bool Polar::operator==(const Polar &c)
{
	if(((this->r)==c.r)&&((this->o)==c.o))
		return true;
	else
		return false;
}
bool Polar::operator!=(const Polar &c)
{
	if(((this->r)==c.r)&&((this->o)==c.o))
		return false;
	else
		return true;
}
double Cartesian::operator-(const Cartesian& c)
{
	double t1,t2,ans;
	t1=(this->x)-c.x;
	t2=(this->y)-c.y;
	ans=sqrt(pow(fabs(t1),2)+pow(fabs(t2),2));
	return ans;
}
istream& operator>>(istream &in,Cartesian &d)
{
    cout<<"\nEnter x and y co-ordinates:";
    in>>d.x>>d.y;
    return in;
}
ostream& operator<<(ostream &out,const Cartesian &d)
{
    cout<<"\n";
    out<<"x="<<d.x<<"y="<<d.y<<"\n";
    return out;
}
istream& operator>>(istream &in,Polar &d)
{
    cout<<"\nEnter r and o:";
    in>>d.r>>d.o;
    return in;
}
ostream& operator<<(ostream &out,const Polar &d)
{
    cout<<"\n";
    out<<"r="<<d.r<<"o="<<d.o<<"\n";
    return out;
}
int main()
{
	   Polar p1,p2;
	   Cartesian c1,c2;
	   int c;
	   double ans;
	   do{
        cout<<"ENTER YOUR CHOICE\n1.convert to cartesian\n2.convert to polar\n3.distance(Cartesian)\n4.distance(polar)\n5.compare(cartesian)\n6.compare(polar)\n7.compare(different)\n8.inequality(polar)\n9.inequality(cartesian)\n10.exit\n";
        cin>>c;
        switch(c)
        {
            case 1:cin>>p1;
                   c1=(Cartesian)p1;
                   cout<<c1<<endl;
                   break;
            case 2:cin>>c1;
                   p1=(Polar)c1;
                   cout<<p1<<endl;
                   break;
            case 3:cout<<"Enter source point\n";
                   cin>>c1;
                   cout<<"Enter destination point\n";
                   cin>>c2;
                   ans=c1-c2;
                   cout<<ans<<endl;
                   break;
            case 4:cout<<"Enter source point\n";
                   cin>>p1;
                   cout<<"Enter destination point\n";
                   cin>>p2;
                   ans=p1-p2;
                   cout<<ans<<endl;
                   break;
            case 5:cout<<"Enter 1st \n";
                   cin>>c1;
                   cout<<"Enter 2nd\n";
                   cin>>c2;
                   if(c1==c2)
                        cout<<"equal\n";
                   else
                        cout<<"not equal \n";
                   break;
            case 6:cout<<"Enter 1st \n";
                   cin>>p1;
                   cout<<"Enter 2nd\n";
                   cin>>p2;
                   if(p1==p2)
                        cout<<"equal\n";
                   else
                        cout<<"not equal \n";
                   break;
            case 7:cout<<"Enter polar \n";
                   cin>>p1;
                   cout<<"Enter cartesian\n";
                   cin>>c1;
                   if(c1==p1)
                        cout<<"equal\n";
                   else
                        cout<<"not equal \n";
                   break;
                   break;
             case 9:cout<<"Enter 1st \n";
                   cin>>c1;
                   cout<<"Enter 2nd\n";
                   cin>>c2;
                   if(c1!=c2)
                        cout<<"not equal\n";
                   else
                        cout<<"equal \n";
                   break;
            case 8:cout<<"Enter 1st \n";
                   cin>>p1;
                   cout<<"Enter 2nd\n";
                   cin>>p2;
                   if(p1!=p2)
                        cout<<"not equal\n";
                   else
                        cout<<"equal \n";
                   break;
            case 10:return 0;
            default:cout<<"Invalid Input\n";
          }
      }while(true);
	return 0;
}
