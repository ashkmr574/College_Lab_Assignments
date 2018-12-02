#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class strng
{
	char* str;
	int len;
public:
	 strng(){str=NULL;len=0;};
	 strng(string);
	 strng(int);
	 void setstr(int d);
	 int getlen();
	 strng(const strng&);
	 strng operator+(const strng&);
	 strng operator+=(const strng&);
	 bool operator==(const strng&);
	 bool operator>(const strng&);
	 bool operator<(const strng&);
	 strng operator=(const strng&);
	 //void setstrng(string);
	 friend ostream & operator << (ostream&, const strng& );
	 ~strng();
};
/*void strng::setstrng(string s)
{

}*/
int strng::getlen()
{
	return this->len;
}
strng::strng(int len)
{
	this->len=len;
	this->str=new char[len+1];
}
void strng::setstr(int d)
{
	this->len=d;
	this->str=new char[len+1];
	cout<<"Enter string\n";
	cin>>this->str;
}
strng::~strng()
{
	if(this->str!=NULL){ delete[] this->str;
	cout<<"memory deallocated\n";}
}
bool strng::operator==(const strng& s)
{
	if(strcmp(this->str,s.str)==0)
		return true;
	else
		return false;
}
strng strng::operator=(const strng& s)
{
	if(this==&s) return *this;
	else{
		if(this->str!=NULL) delete[] this->str;
		this->len=s.len;
		this->str=new char[(s.len)+1];
		strcpy(this->str,s.str);
		return *this;
	}
}
bool strng::operator>(const strng& s)
{
	if(strcmp(this->str,s.str)>0)
		return true;
	else
		return false;
}
bool strng::operator<(const strng& s)
{
	if(strcmp(this->str,s.str)<0)
		return true;
	else
		return false;
}
ostream& operator<<(ostream &out,const strng &d)
{
    out<<d.str;
    return out;
}
strng strng::operator+(const strng& s)
{
	strng s1(*this);
	s1.len+=s.len;
	int j=(this->len);
	for(int i=0;i<s.len;i++)
		s1.str[j++]=s.str[i];
	return s1;
}
strng strng::operator+=(const strng& s)
{
	strng s1;
	s1.len=(this->len)+s.len;
	s1=(*this)+s;
	*this=s1;
	return *this;
}
strng::strng(string s)
{
	len=s.length();
	str=new char[len+1];
	for(int i=0;i<len;i++)
		str[i]=s.at(i);
}
strng::strng(const strng &s)
{
	this->len=s.len;
	this->str=new char[(s.len)+1];
	strcpy(this->str,s.str);
}
int main()
{
	int c,d;
	strng s1,s2;
	string s;
	do
	{
		cout<<"enter your choice\n1.add\n2.equality\n3.compare\n4.exit\n";
		cin>>c;
		switch(c)
		{
			case 1:cout<<"Enter length of 1st string\n";
				  cin>>d;
				  s1.setstr(d);
				  cout<<"Enter length of 2nd string\n";
				  cin>>d;
				  s2.setstr(d);
				  s1+=s2;
				  cout<<"resultant string= "<<s1<<endl;
				  break;
		     case 2:cout<<"Enter length of 1st string\n";
				  cin>>d;
				  s1.setstr(d);
				  cout<<"Enter length of 2nd string\n";
				  cin>>d;
				  s2.setstr(d);
				  if(s1>s2)
				  	cout<<"first one is greater than the second\n";
				  else if(s1==s2)
				  	cout<<"both are equal\n";
				  else if(s1<s2)
				  	cout<<"first one is less than the second one\n";
				  break;
			case 3:cout<<"Enter length of 1st string\n";
				  cin>>d;
				  s1.setstr(d);
				  cout<<"Enter length of 2nd string\n";
				  cin>>d;
				  s2.setstr(d);
				  if(s1>s2)
				  	cout<<"first one is greater than the second\n";
				  else if(s1==s2)
				  	cout<<"both are equal\n";
				  else if(s1<s2)
				  	cout<<"first one is less than the second one\n";
				  break;
			case 4:return 0;
			default:cout<<"Invalid input\n";
		}
	}while(true);
}
