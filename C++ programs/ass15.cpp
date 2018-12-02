#include<iostream>
#include<cstdio>
using namespace std;
class account
{
public:
	string name,type;
	int acnumber;
	double balance;
	account(){};
	account(string,int,double);
	void displayb();
	void display();
	int gettype()
	{
		if(type=="Savings")
			return 1;
		else
			return 2;
	}
	void deposit(double);
	void withdraw(double);
	virtual void interest(){};
	
};
class CrrAcc :public account
{
public:
    CrrAcc(){};
	CrrAcc(string,int,double);
	void interest();
};
class SavAcc :public account
{
public:
    SavAcc(){};
	SavAcc(string,int,double);
	void interest();
};
void SavAcc::interest()
{
    double l;
    l=balance*0.05;
    cout<<"After Depositing interest ";
    deposit(l);
}
void CrrAcc::interest()
{
    double l;
    l=balance*0.1;
    cout<<"After Depositing interest ";
    deposit(l);
}
void  account::display()
{
	cout<<"name= "<<name<<endl<<"account type="<<type<<endl;
	cout<<"account number= "<<acnumber<<endl<<"balance= "<<balance<<endl;
}
void  account::displayb()
{
	cout<<"your current balance is ="<<balance<<endl;
}
void account::deposit(double b)
{
	balance+=b;
	displayb();
}
account::account(string name,int type,double balance)
{
		static int acnumber=1;
		this->name=name;
		if(type==1)
			this->type="Savings";
		else
			this->type="Current";
		this->acnumber=acnumber;
		acnumber++;
		this->balance=balance;
}
SavAcc::SavAcc(string name,int type,double balance):account(name,type,balance)
{
		cout<<"your account has been created and your account details are \n";
		display();
}
CrrAcc::CrrAcc(string name,int type,double balance):account(name,type,balance)
{
		cout<<"your account has been created and your account details are \n";
		display();
}
void account::withdraw(double b)
{
	balance-=b;
	displayb();
}
int main()
{
	int c,acc,i=0,j=0,k=0,minc,mins,l,m;
	string name;
	double balance;
	account **a=new account*[150];
	cout<<"Enter minimum balance for savings account"<<endl;
	cin>>mins;
	cout<<"Enter minimum balance for current account"<<endl;
	cin>>minc;
	do
	{
		cout<<"1.create account\n2.deposit balance\n3.withdrawal\n4.check balance\n5.deposit interest\n6.exit\n";
		cin>>c;
		getchar();
		switch(c)
		{
			case 1:cout<<"Enter name\n";
				  getline(cin,name);
				  cout<<"Enter Account type\n1.savings\n2.current"<<endl;
				  cin>>acc;
				  cout<<"Enter initial balance to be deposited"<<endl;
				  cin>>balance;
				  if(acc==1&&balance>=mins)
				  {
				  	a[i++]=new SavAcc(name,acc,balance);
				  	//a[i++]=b;
				  	k++;
				  }
				  else if(acc==2&&balance>=minc)
				  {
				  	a[i++]=new CrrAcc(name,acc,balance);
				  	//b[j++]=b1;
				  	k++;
				  }
				  else
                    cout<<"Account could not be created as initial amount should be at least equal to minimun balance\n";
				  break;
			case 2:cout<<"enter the account number";
				  cin>>acc;
				  if(acc<=k)
				  {
				  	cout<<"Enter the balance to be added";
				  	cin>>balance;
				  	for(j=0;j<i;j++)
				  	{
				  		if((a[j]->acnumber)==acc)
				  			a[j]->deposit(balance);
				  	}
                      }
				  else
                    cout<<"Account does not exists\n";
				  break;
			case 3:cout<<"enter the account number";
				  cin>>acc;
				  if(acc<=k)
				  {
				  	cout<<"enter the withdrawal amount\n";
				  	cin>>balance;
				  	for(j=0;j<i;j++)
				  	{
				  		if((a[j]->acnumber)==acc)
				  		{
				  			l=a[j]->gettype();
				  			if(l==1)
				  			{
				  				if((a[j]->balance)-balance>=mins)
                            				a[l]->withdraw(balance);
                        				else if(((a[l]->balance)-balance-20)>=0)
                            				a[l]->withdraw(balance+20);
                        				else
                            				cout<<"Insufficient balance\n";
				  			}
				  			else
				  			{
				  				if((a[j]->balance)-balance>=minc)
                            						a[j]->withdraw(balance);
                        				else
                            				a[j]->withdraw(balance+20);
				  			}
				  		}
				  	}
				  }
                    else
                    	cout<<"account does not exists\n";
				  break;
            case 4:cout<<"enter the account number";
				  cin>>acc;
				  if(acc<=k)
				  {
				  	for(j=0;j<i;j++)
				  	{
				  		if((a[j]->acnumber)==acc)
				  			a[j]->displayb();
				  	}
				  }
				  	else
                    		cout<<"Account does not exists\n";
				  break;
            case 5:cout<<"enter the account number";
				  cin>>acc;
				 if(acc<=k)
				 {
				  	for(j=0;j<i;j++)
				  	{
				  		if((a[j]->acnumber)==acc)
				  		{
				  			a[j]->interest();
				  		}
                    	}
                    }
				 else
                    	cout<<"Account does not exists\n";
                break;
			case 6:return 0;
			default:cout<<"invalid input"<<endl;
		}
	}while(true);
	return 0;
}
