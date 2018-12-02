//this program has all functions implemented as said in the question
//you need to write proper menu driven program from this.

#include<iostream>
#include<cmath>
using namespace std;
typedef struct
{
    int b[8];
}byte;
void print(byte b1)
{
    for(int i=0;i<8;i++)
        cout<<b1.b[i];
}
byte binary(int d)
{
    int f=0,k=0,i,j;
    int t[8]={0};
    byte b1;
    if(d<0)
    {
        d=(-1)*d;
        f=1;
    }
    while(1)
    {
        t[k++]=d%2;
        d/=2;
        if(d==1)
        {
            t[k++]=1;
            break;
        }
    }
    i=8-k;
    k--;
    for(j=i;j<8;j++)
        b1.b[j]=t[k--];
    for(j=0;j<i;j++)
        b1.b[j]=0;
    return b1;
}
byte operator+(byte b1,byte b2)
{
    byte b3;
    int c=0;
    for(int i=7;i>=0;i--)
    {
        b3.b[i]=(b1.b[i]^b2.b[i])^c;
        c=(b1.b[i]&b2.b[i])|(b1.b[i]&c)|(b2.b[i]&c);
    }
    return b3;
}
byte operator-(byte b1,byte b2)
{
    byte b3;
    int c=0;
    for(int i=7;i>=0;i--)
    {
        b3.b[i]=(b1.b[i]^b2.b[i])^c;
        c=((~b1.b[i])&b2.b[i])|((~b1.b[i])&c)|(b2.b[i]&c);
    }
    return b3;
}
byte operator&(byte x,byte y)
{
	byte c;
	for(int i=0;i<8;i++)
	{
		if((x.b[i]==1)&&(y.b[i]==1))
			c.b[i]=1;
		else
			c.b[i]=0;
	}
	return c;
}
byte operator|(byte x,byte y)
{
	byte c;
	for(int i=0;i<8;i++)
	{
		if((x.b[i]==1)||(y.b[i]==1))
			c.b[i]=1;
		else
			c.b[i]=0;
	}
	return c;
}
byte operator^(byte x,byte y)
{
	byte c;
	for(int i=0;i<8;i++)
	{
		if(x.b[i]==y.b[i])
			c.b[i]=0;
		else
			c.b[i]=1;
	}
	return c;
}
byte operator<<(byte x,int n)
{
	byte c;
	for(int i=0;i<7;i++)
	{
		c.b[i]=x.b[i+1];
	}
	c.b[7]=0;
	return c;
}
byte operator>>(byte x,int n)
{
	byte c;
	for(int i=1;i<8;i++)
	{
		c.b[i]=x.b[i-1];
	}
	c.b[0]=0;
	return c;
}
byte operator~(byte x)
{
	for(int i=0;i<8;i++)
	{
		if(x.b[i]==1)
			x.b[i]=0;
		else
			x.b[i]=1;
	}

	return x;
}
int decimal(byte b1)
{
    int sum=0,i;
    for(i=7;i>=0;i--)
        sum+=b1.b[i]*pow(2,7-i);
    return sum;
}
int main()
{
    int d;
    byte b1,b2,b3;
    cout<<"all numbers given as input should be in the range (-128) to (127)\n";
    cout<<"Enter first decimal number\n";
    cin>>d;
    b1=binary(d);
    cout<<"Binary representation of number=";
    print(b1);
    cout<<"\n";
    cout<<"Enter second decimal number(less than first)\n";
    cin>>d;
    b2=binary(d);
    cout<<"Binary representation of number=";
    print(b2);
    cout<<"\nAddition of number : ";
    print(b1+b2);
    cout<<"\nSubtraction of number : ";
    print(b1-b2);
    cout<<"\nAnd of number : ";
    print(b1&b2);
    cout<<"\nOr of number : ";
    print(b1|b2);
    cout<<"\nXor of number : ";
    print(b1^b2);
    cout<<"\nLeft shift of first number : ";
    print(b1<<1);
    cout<<"\nRight shift  of second number : ";
    print(b2>>1);
    cout<<"\ncomplement of first number :";
    print(~b1);
    cout<<"Enter a 8 bit binary number( EACH BIT SEPARATED BY SPACE)\n";
    for(int i=0;i<8;i++)
        cin>>b3.b[i];
    cout<<"Decimal representation of number :";
    cout<<(decimal(b3))<<endl;
    //print(b1);
    //print(b2);
    return 0;
}
