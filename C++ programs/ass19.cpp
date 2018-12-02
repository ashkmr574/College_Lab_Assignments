#include<iostream>
#include<cstdio>
using namespace std;
template <class T>
class stack
{
	int tos,n;
	T *a;
public:
	void push(T);
	T pop();
	void init(int );

};
template<class T>void stack<T>:: push(T n)
{
	if((this->tos)==((this->n)-1))
        cout<<"Stack is full\n";
    else
    {
        tos++;
        a[tos]=n;
    }
}
template <class T>T stack<T>::pop()
{
	if(tos==-1)
        cout<<"Stack is empty\n";
    else
    {
        T z=a[tos];
        tos--;
        cout<<"poped element="<<z<<endl;
        return z;
    }
}
template <class T> void stack<T>::init(int n)
{
    a=new T[n];
    tos=-1;
    this->n=n;
}
template <class T>void process(stack<T> s,int n)
{
    int c;
    T b;
    bool f=true;
    do
    {
        cout<<"1.push\n2.pop\n";
        cin>>c;
        switch(c)
        {
            case 1:cout<<"enter element\n";
                   cin>>b;
                   s.push(b);
                   break;
            case 2:s.pop();
                   break;
            default:cout<<"Invalid Input\n";
                    f=false;
        }

    }while(f);
}
int main()
{
	int n,c;
	do
	{
		cout<<"Enter the no of elements\n";
		cin>>n;
		cout<<"Choose Type\n1.int\n2.float\n3.string\n4.exit\n";
		cin>>c;
		switch(c)
		{
			case 1:{
                        stack<int> s;
                        s.init(n);
                        process(s,n);

                    }
				  break;
			case 2:{
                        stack<float> s;
                        s.init(n);
                        process(s,n);
				  }
				  break;
			case 3:getchar();
				  {
                        stack<string> s;
                        s.init(n);
                        process(s,n);
				  }
				  break;
			case 4:return 0;
			default:cout<<"Invalid input";
		}
	}while(true);
}
