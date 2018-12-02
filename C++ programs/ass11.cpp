#include<iostream>
using namespace std;
class Meter
{
    int m;
    float cm;
public:
    /*Meter(){};
    Meter(int);
    Meter(float);
    Meter(int,float);*/
    void setm(int);
    void setcm(float);
    int getm();
    float getcm();
    friend istream & operator >> (istream&, Meter& );
    friend ostream & operator << (ostream&, const Meter& );
};
class dis
{
    int x;
    float y;
public:
    dis(){};
    dis(int);
    dis(float);
    dis(int,float);
    dis(const dis&);
    dis(Meter m);
    void setx(int);
    void sety(float);
    int getx();
    float gety();
    bool operator>(const dis&);
    bool operator>=(const dis&);
    bool operator<(const dis&);
    bool operator<=(const dis&);
    bool operator!=(const dis&);
    dis operator+(const dis&);
    operator int();
    operator float();
    operator Meter();
    friend istream & operator >> (istream&, dis& );
    friend ostream & operator << (ostream&, const dis& );
};
dis::dis(Meter m1)
{

    y=(m1.getm())*3.2808;
    x=(m1.getcm())*0.393701;
    y+=(x/12);
    x=x%12;
}
dis dis::operator+(const dis&d)
{
    dis d3;
    d3.y=(this->y)+d.y;
    d3.x=(this->x)+d.x;
    int i=(d3.x)/12;
    d3.y+=i;
    d3.x=(d3.x%12);
    return d3;
}
dis::operator Meter()
{
    Meter mt;
    float c = (this->y * 30.48)+((this->x)*2.54);
    int q=c/100;
    //cout<<c<<" "<<q<<endl;
    mt.setm(q);
    mt.setcm(c-q*100);
    return mt;
}
dis::operator int()
{
    return this->x;
}
dis::operator float()
{
    return this->y;
}
void dis::setx(int x)
{
    this->x=x;
}
void dis::sety(float y)
{
    this->y=y;
}
dis::dis(int x)
{
    this->x=x;
}
dis::dis(float y)
{
    this->y=y;
}
dis::dis(int x,float y)
{
    this->x=x;
    this->y=y;
}
dis::dis(const dis& o)
{
    this->x=o.x;
    this->y=o.y;
}
int dis::getx()
{
    return this->x;
}
float dis::gety()
{
    return this->y;
}
/*Meter::Meter(int m)
{
    this->m=m;
}
Meter::Meter(float cm)
{
    this->cm=cm;
}
Meter::Meter(int m,float cm)
{
    this->m=m;
    this->cm=cm;
}*/
void Meter::setm(int m)
{
    this->m=m;
    //cout<<(this->m)<<endl;
}
void Meter::setcm(float cm)
{
    this->cm=cm;
    //cout<<(this->cm)<<endl;
}
int Meter::getm()
{
    //cout<<(this->m)<<endl;
    return this->m;
}
float Meter::getcm()
{
    return this->cm;
}
istream& operator>>(istream &in,dis &d)
{
    cout<<"\n Enter feet and inches :";
    in>>d.y>>d.x;
    return in;
}
ostream& operator<<(ostream &out,const dis &d)
{
    cout<<"\n";
    out<<d.y<<"feet "<<d.x<<"inches\n";
    return out;
}
istream& operator>>(istream &in,Meter &d)
{
    cout<<"\nEnter meters and centimeters :";
    in>>d.m>>d.cm;
    return in;
}
ostream& operator<<(ostream &out,const Meter &d)
{
    cout<<"\n";
    out<<d.m<<"meters "<<d.cm<<"centimeters\n";
    return out;
}
bool dis:: operator>(const dis &d1)
{
   float f1 = (this->y)*12 + (this->x);
    float f2 = (d1.y*12)+d1.x;
    if(f1>f2)
        return true;
    else
        return false;
}
bool dis:: operator>=(const dis &d1)
{
   float f1 = (this->y)*12 + (this->x);
    float f2 = (d1.y*12)+d1.x;
    if(f1>=f2)
        return true;
    else
        return false;
}
bool dis:: operator<(const dis &d1)
{
   float f1 = (this->y)*12 + (this->x);
    float f2 = (d1.y*12)+d1.x;
    if(f1<f2)
        return true;
    else
        return false;
}
bool dis:: operator<=(const dis &d1)
{
   float f1 = (this->y)*12 + (this->x);
    float f2 = (d1.y*12)+d1.x;
    if(f1<=f2)
        return true;
    else
        return false;
}
bool dis:: operator!=(const dis &d1)
{
   float f1 = (this->y)*12 + (this->x);
    float f2 = (d1.y*12)+d1.x;
    if(f1!=f2)
        return true;
    else
        return false;
}
int main()
{
    dis d,d1,d3;
    Meter mt;
    int c,i;
    float j;
    do
    {
        cout<<"ENTER YOUR CHOICE\n1.convert to meter\n2.> check\n3.>=check\n4.< check\n5.<= check\n6.!= check\n7.add\n8.getting attribute(overloadingtypecast)\n9.exit\n10.meter to distance\n";
        cin>>c;
        switch(c)
        {
            case 1:cin>>d;
                   mt=(Meter)d;
                   cout<<mt<<endl;
                   break;
            case 2:cout<<"Enter 1st distance\n";
                   cin>>d;
                   cout<<"Enter 2nd distance\n";
                   cin>>d1;
                   if(d>d1)
                        cout<<"first one is greater than the 2nd\n";
                   else
                        cout<<"2nd one is either greater or equal\n";
                   break;
            case 3:cout<<"Enter 1st distance\n";
                   cin>>d;
                   cout<<"Enter 2nd distance\n";
                   cin>>d1;
                   if(d>=d1)
                        cout<<"first one is either greater than or equal to the 2nd\n";
                   else
                        cout<<"2nd greater than the first one \n";
                   break;
            case 4:cout<<"Enter 1st distance\n";
                   cin>>d;
                   cout<<"Enter 2nd distance\n";
                   cin>>d1;
                   if(d<d1)
                        cout<<"first one is less than the 2nd\n";
                   else
                        cout<<"2nd one is either less or equal\n";
                   break;
            case 5:cout<<"Enter 1st distance\n";
                   cin>>d;
                   cout<<"Enter 2nd distance\n";
                   cin>>d1;
                   if(d<=d1)
                        cout<<"first one is either less than or equal to the 2nd\n";
                   else
                        cout<<"2nd is less than the first one \n";
                   break;
            case 6:cout<<"Enter 1st distance\n";
                   cin>>d;
                   cout<<"Enter 2nd distance\n";
                   cin>>d1;
                   if(d!=d1)
                        cout<<"both are not equal\n";
                   else
                        cout<<"both are equal \n";
                   break;
            case 7:cout<<"Enter 1st distance\n";
                   cin>>d;
                   cout<<"Enter 2nd distance\n";
                   cin>>d1;
                   d3=d+d1;
                   cout<<d3;
                   break;
            case 8:cin>>d;
                   i=(int)d;
                   j=(float)d;
                   cout<<"inches="<<i<<endl;
                   cout<<"feet="<<j<<endl;
            case 9:return 0;
            case 10:cin>>mt;
                    d=(dis)mt;
                    cout<<d;
                    break;
            default:cout<<"Invalid Input\n";
        }
    }while(true);
    return 0;
}
