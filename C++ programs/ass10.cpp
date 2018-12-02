#include<iostream>
using namespace std;
class fraction
{
	int n,d;
	int minimize(int,int);
public:
	int setn(int);
	int setd(int);
	fraction operator+(const fraction &);
	fraction operator-(const fraction&);
	fraction operator*(const fraction&);
	bool operator==(const fraction&);
	fraction operator=(const fraction&);
	fraction operator+=(const fraction&);
	fraction operator-=(const fraction&);
	fraction operator*=(const fraction&);
	int getn();
	int getd();
};
int fraction::setn(int n)
{
	this->n=n;
}
int fraction::setd(int d)
{
	this->d=d;
}
int fraction::minimize(int a,int b)
{
		if((a%b)==0)
			return b;
		else
			return minimize(b,a%b);
}
fraction fraction::operator=(const fraction&c)
{
	fraction f;
	(this->n)=c.n;
	(this->d)=c.d;
	return *this;
}
fraction fraction::operator+=(const fraction&c)
{
	(this->n)=((this->n)*c.d)+((this->d)*c.n);
	(this->d)*=c.d;
	return *this;
}
fraction fraction::operator-=(const fraction&c)
{
	(this->n)=((this->n)*c.d)-((this->d)*c.n);
	(this->d)*=c.d;
	return *this;
}
fraction fraction::operator*=(const fraction&c)
{
	(this->n)*=c.n;
	(this->d)*=c.d;
	return *this;
}
bool fraction::operator==(const fraction &c)
{
	int i;
	fraction c3;
	c3=c;
	i=minimize((this->d),(this->n));
	(this->d)/=i;
	(this->n)/=i;
	i=minimize(c3.d,c3.n);
	(c3.d)/=i;
	(c3.n)/=i;
	if(((this->n)==c3.n)&&((this->d)==c3.d))
		return true;
	else
		return false;
}
fraction fraction::operator+(const fraction&c2)
{
	int i;
	fraction c3;
	c3=(*this);
	c3+=c2;
	if((c3.n)>(c3.d))
		i=minimize(c3.n,c3.d);
	else
		i=minimize(c3.d,c3.n);
	(c3.n)/=i;
	(c3.d)/=i;
	return c3;
}
fraction fraction::operator-(const fraction&c2)
{
	int i;
	fraction c3;
	c3=(*this);
	c3-=c2;
	if(c3.n!=0)
	{if((c3.n)>(c3.d))
		i=minimize(c3.n,c3.d);
	else
		i=minimize(c3.d,c3.n);
	(c3.n)/=i;
	(c3.d)/=i;}
	if(c3.n==0)
        c3.d=1;
	return c3;
}
fraction fraction::operator*(const fraction&c2)
{
	int i;
	fraction c3;
	c3=(*this);
	c3*=c2;
	if((c3.n)>(c3.d))
		i=minimize(c3.n,c3.d);
	else
		i=minimize(c3.d,c3.n);
	(c3.n)/=i;
	(c3.d)/=i;
	return c3;
}
int fraction::getn()
{
	return this->n;
}
int fraction::getd()
{
	return this->d;
}
int main()
{
	fraction c1,c2,c3;
	int ch,r,i;
	do
	{
		cout<<"Enter your choice\n1.addition\n2.subtraction\n3.multiplication\n4.equality\n5.exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"Enter numerator and denominator of 1st fraction\n";
				  cin>>r>>i;
				  c1.setn(r);
				  c1.setd(i);
				  cout<<"Enter numerator and denominator of 2nd fraction\n";
				  cin>>r>>i;
				  c2.setn(r);
				  c2.setd(i);
				  c3=c1+c2;
				  r=c3.getn();
				  i=c3.getd();
				  cout<<"result="<<r<<"/"<<i<<"\n";
				  break;
			case 2:cout<<"Enter numerator and denominator of 1st fraction\n";
				  cin>>r>>i;
				  c1.setn(r);
				  c1.setd(i);
				  cout<<"Enter numerator and denominator of 2nd fraction\n";
				  cin>>r>>i;
				  c2.setn(r);
				  c2.setd(i);
				  c3=c1-c2;
				  r=c3.getn();
				  i=c3.getd();
				  cout<<"result="<<r<<"/"<<i<<"\n";
				  break;
			case 3:cout<<"Enter numerator and denominator of 1st fraction\n";
				  cin>>r>>i;
				  c1.setn(r);
				  c1.setd(i);
				  cout<<"Enter numerator and denominator of 2nd fraction\n";
				  cin>>r>>i;
				  c2.setn(r);
				  c2.setd(i);
				  c3=c1*c2;
				  r=c3.getn();
				  i=c3.getd();
				  cout<<"result="<<r<<"/"<<i<<"\n";
				  break;
			case 4:cout<<"Enter numerator and denominator of 1st fraction\n";
				  cin>>r>>i;
				  c1.setn(r);
				  c1.setd(i);
				  cout<<"Enter numerator and denominator of 2nd fraction\n";
				  cin>>r>>i;
				  c2.setn(r);
				  c2.setd(i);
				  if(c1==c2)
				  	cout<<"both fractions are equal\n";
				  else
				  	cout<<"both fractions are not equal\n";
				  break;
			case 5: return 0;
			default:cout<<"Invalid choice\n";

		}
	}while(true);
		return 0;
}
