#include<iostream>
using namespace std;
class peripheral
{
protected:
	int on,in;
	string state;
public:
	virtual void show()=0;	
};
class input:virtual public peripheral
{
protected:
	string conn;
public:
	input(){};
	input(int,int,int,int);
	virtual void show();
};
class output:virtual public peripheral
{
protected:
	string colr;
public:
	output(){};
	output(int,int,int,int);
	virtual void show();
};
class keyboard:public input
{
	int key;
	string type;
public:
	keyboard(){};
	keyboard(int,int,int,int,int,int);
	void show();	
};
class mouse:public input
{
	string type;
public:
	mouse(){};
	mouse(int,int,int,int,int);
	void show();	
};
class monitor:public output
{
	string size,res;
public:
	monitor(){};
	monitor(int,int,int,int,int,int);
	void show();	
};
class printer:public output
{
	string type;
public:
	printer(){};
	printer(int,int,int,int,int);
	void show();	
};
class touchscreen:public input,public output
{
	string size,res,type;
public:
	touchscreen(){};
	touchscreen(int,int,int,int,int,int,int,int);
	void show();	
};
/*peripheral::peripheral(int on,int in,int k)
{
	this->on=on;
	this->in=in;
	if(k==1)
		this->state="new";
	else
		this->state="used";
	show();
}
void peripheral::show()
{
	cout<<"order no ="<<(this->on)<<endl;
	cout<<"item no ="<<(this->in)<<endl;
	cout<<"state ="<<(this->state)<<endl;
}*/
input::input(int on,int in,int state,int conn)//:peripheral(on,in,state)
{
     this->on=on;
	this->in=in;
	if(state==1)
		this->state="new";
	else
		this->state="used";
	if(conn==1)
		this->conn="wired";
	else
		this->conn="Wireless";
}
void input::show()
{
	cout<<"order no ="<<(this->on)<<endl;
	cout<<"item no ="<<(this->in)<<endl;
	cout<<"state ="<<(this->state)<<endl;
	cout<<"connection = "<<(this->conn)<<endl;
}
output::output(int on,int in,int state,int colr)//:peripheral(on,in,state)
{
	if(colr==1)
		this->colr="Colored";
	else
		this->colr="B/W";
	this->on=on;
	this->in=in;
	if(state==1)
		this->state="new";
	else
		this->state="used";
}
void output::show()
{
	cout<<"order no ="<<(this->on)<<endl;
	cout<<"item no ="<<(this->in)<<endl;
	cout<<"state ="<<(this->state)<<endl;
	cout<<"colour '"<<(this->colr)<<endl;
}
keyboard::keyboard(int on,int in,int state,int conn,int key,int t):input(on,in,state,conn)
{
	this->key=key;
	if(t==1)
		this->type="Normal";
	else if(t==2)
		this->type="Multimedia";
	else
		this->type="Gaming";
}
void keyboard::show()
{
     cout<<"Inside keyboard \n";
	cout<<"order no ="<<(this->on)<<endl;
	cout<<"item no ="<<(this->in)<<endl;
	cout<<"state ="<<(this->state)<<endl;
	cout<<"connection = "<<(this->conn)<<endl;
	cout<<"no of keys="<<(this->key)<<endl;
	cout<<"type ="<<(this->type)<<endl;
}
mouse::mouse(int on,int in,int state,int conn,int t):input(on,in,state,conn)
{
	if(t==1)
		this->type="Ball";
	else
		this->type="optical";
}
void mouse::show()
{
	cout<<"order no ="<<(this->on)<<endl;
	cout<<"item no ="<<(this->in)<<endl;
	cout<<"state ="<<(this->state)<<endl;
	cout<<"connection = "<<(this->conn)<<endl;
	//cout<<"no of keys="<<(this->key)<<endl;
	cout<<"type ="<<(this->type)<<endl;
}
monitor::monitor(int on,int in,int state,int colr,int size,int res):output(on,in,state,colr)
{
	if(size==1)
		this->size="13 Inch";
	else if(size==2)
		this->size="15.6 Inch";
	else
		this->size="17 Inch";
	if(res==1)
		this->res="720p";
	else
		this->res="1080p";
}
void monitor::show()
{
	cout<<"order no ="<<(this->on)<<endl;
	cout<<"item no ="<<(this->in)<<endl;
	cout<<"state ="<<(this->state)<<endl;
	cout<<"colour ="<<(this->colr)<<endl;
	cout<<"size ="<<(this->size)<<endl;
	cout<<"resolution"<<(this->res)<<endl;
}
printer::printer(int on,int in,int state,int colr,int type):output(on,in,state,colr)
{
	if(type==1)
		this->type="Dot Matrix";
	else if(type==2)
		this->type="Ink Jet";
	else
		this->type="Laser";
}
void printer::show()
{
	cout<<"order no ="<<(this->on)<<endl;
	cout<<"item no ="<<(this->in)<<endl;
	cout<<"state ="<<(this->state)<<endl;
	cout<<"colour ="<<(this->colr)<<endl;
	cout<<"type ="<<(this->type)<<endl;
}
touchscreen::touchscreen(int on,int in,int state,int conn,int colr,int size,int res,int type)
{
	this->on=on;
	this->in=in;
	if(state==1)
		this->state="new";
	else
		this->state="used";
	if(colr==1)
		this->colr="Colored";
	else
		this->colr="B/W";
	if(conn==1)
		this->conn="wired";
	else
		this->conn="wireless";
	if(size==1)
		this->size="Moblie Size";
	else if(size==2)
		this->size="Tablet Size";
	else
		this->size="Laptop Size";
	if(res==1)
		this->res="720p";
	else
		this->res="1080p";
	if(type==1)
		this->type="Resistive";
	else
		this->type="Capacitive";	
}
void touchscreen::show()
{
	cout<<"order no ="<<(this->on)<<endl;
	cout<<"item no ="<<(this->in)<<endl;
	cout<<"state ="<<(this->state)<<endl;
	cout<<"colour ="<<(this->colr)<<endl;
	cout<<"connection="<<(this->conn)<<endl;
	cout<<"size ="<<(this->size)<<endl;
	cout<<"resolution="<<(this->res)<<endl;
	cout<<"type ="<<(this->type)<<endl;
}
int main()
{
	static int on=1000;
	static int in=1;
	peripheral **a=new peripheral*[150];
	int c,s1,s2,i=0,n1,n2,s3,n3,j;
	do
	{
		cout<<"1> Keyboard\n2> Mouse\n3> Monitor\n4> Printer\n5> TouchScreen\n6> Display\n0> Quit\n";
		cin>>c;
		switch(c)
		{
			case 1:{cout<<"Enter state\n1.new\n2.used\n";
				  cin>>s1;
				  cout<<"Eneter connection type\n1.wired\n2.wireless\n";
				  cin>>s2;
				  cout<<"Enter no of keys\n";
				  cin>>n1;
				  cout<<"choose type \n1.normal\n2.multimedia\n3.gaming\n"; 
				  cin>>n2;
				  a[i]=new keyboard(on,in,s1,s2,n1,n2);
				  //a[i]=&b;
				  //a[i]->show();
				  in++;
				  i++;}
				  break;
			case 2:{cout<<"Enter state\n1.new\n2.used\n";
				  cin>>s1;
				  cout<<"Eneter connection type\n1.wired\n2.wireless\n";
				  cin>>s2;
				  cout<<"choose type \n1.ball\n2.optical\n"; 
				  cin>>n2;
				  a[i]= new mouse(on,in,s1,s2,n2);
				  //a[i]=&b;
				  in++;
				  i++;}
				  break;
			case 3:{cout<<"Enter state\n1.new\n2.used\n";
				  cin>>s1;
				  cout<<"Eneter colour\n1.colored\n2.B&W\n";
				  cin>>s2;
				  cout<<"Enter size\n1.13 inch\n2.15.6 inch\n3.17 inch\n";
				  cin>>n1;
				  cout<<"choose resolution \n1.720p\n2.1080p\n"; 
				  cin>>n2;
				  a[i]= new keyboard(on,in,s1,s2,n1,n2);
				  //b.show();
				  //a[i]=&b;
				  in++;
				  i++;}
				  break;
               case 4:{cout<<"Enter state\n1.new\n2.used\n";
				  cin>>s1;
				  cout<<"Eneter colour\n1.colored\n2.B&W\n";
				  cin>>s2;
				  cout<<"Enter type\n1.Dot Matrix\n2.Ink-Jet\n3.Laser\n";
				  cin>>n1;
				  a[i]= new printer(on,in,s1,s2,n1);
				  //a[i]=&b;
				  in++;
				  i++;}
				  break;
			case 5:{cout<<"Enter state\n1.new\n2.used\n";
				  cin>>s1;
				  cout<<"Eneter connection type\n1.wired\n2.wireless\n";
				  cin>>s2;
				  cout<<"Eneter colour\n1.colored\n2.B&W\n";
				  cin>>s3;
				  cout<<"Enter size\n1.Mobile size\n2.Tablet Size\n3.Laptop Size\n";
				  cin>>n1;
				  cout<<"choose resolution \n1.720p\n2.1080p\n"; 
				  cin>>n2;
				  cout<<"Enter type\n1.Resistive\n2.Capacitive\n";
				  cin>>n3;
				  a[i]= new touchscreen(on,in,s1,s2,s3,n1,n2,n3);
				  //a[i]=&b;
				  in++;
				  i++;}
				  break;
			case 6:for(j=0;j<i;j++)
					{
						a[j]->show();
						cout<<"\n";
					}
					break;							
			case 0:return 0;
		}
		
	}while(true);
	return 0;
}

