#include<iostream>
#include<cstdio>
using namespace std;
template <class T>
class cqueue
{
protected:
    T *a;
    int r,f,size1;
public:
    void init(int);
    void enqueue(T);
    int getr()
    {
        return r;
    }
    int getf()
    {
        return f;
    }
    T dqueue();
    bool isempty();
    bool isfull();
};
template <class T> class dcqueue:public cqueue<T>
{
public:
    void enqueuef(T);
    bool compare(cqueue<T>&);
    T dqueuer();
};
template <class T> void cqueue<T>::init(int n)
{
	this->a=new T[n];
	this->size1=n;
	this->r=-1;
	this->f=-1;
}
template <class T> bool cqueue<T>::isfull()
{
	if(((this->r==this->size1-1)&&(this->f==0))||(this->f==this->r+1))
		return true;
	else
		return false;
}
template <class T>bool cqueue<T>::isempty()
{
	if(this->r==-1&&this->f==-1)
		return true;
	else
		return false;
}
template <class T>void cqueue<T>::enqueue(T z)
{
	if(isfull())
	{
		cout<<"Overflow"<<endl;
	}
	else
	{
		if(this->f==-1)
			this->f=0;
		if(this->r==this->size1-1)
			this->r=0;
		else
			this->r++;
		this->a[r]=z;
	}
}
template <class T>T cqueue<T>::dqueue()
{
	T z;
	if(isempty())
	{
		printf("underflow\n");
	}
	else
	{
		z=a[f];
		if(f==r)
			f=r=-1;
		else if(f==size1-1)
			f=0;
		else
			f++;
        cout<<z<<endl;
		return z;

	}
}
template <class T>void dcqueue<T>::enqueuef(T z)
{

		 if(this->isfull())
		 {
		 	printf("overflow\n");
		 }
		 else
		 {
		 	if(this->r==-1)
		 		this->f=this->r=this->size1-1;
		 	else if(this->f==0)
                this->f=this->size1-1;
		 	else
		 		this->f--;
		 	this->a[this->f]=z;

		 }
}
template <class T>T dcqueue<T>::dqueuer()
{
		T z;
		if(this->isempty())
		{
			printf("underflow\n");
		}
		else
		{
			z=this->a[this->r];
			if(this->f==this->r)
				this->r=this->f=-1;
			else if(this->r==0)
				this->r=this->size1-1;
			else
				this->r--;
            cout<<"item deleted is="<<z<<endl;
			return z;
		}
}
template <class T> bool dcqueue<T>::compare(cqueue<T> & c)
{
    if(((this->r)==(c.getr()))&&(this->f)==(c.getf()))
        return true;
    else
        return false;
}
int main()
{
    int c,c1,z,n;
    char z1;
    bool f;
    do
    {
        cout<<"Choose Data type\n1.int\n2.char or\n 3.Exit\n";
        cin>>c;
        switch(c)
        {
            case 1:cout<<"Enter no of terms for circular queue\n";
                   cin>>n;
                   cqueue<int>s1;
                   s1.init(n);
                   cout<<"Enter no of terms for double ended circular queue\n";
                   cin>>n;
                   dcqueue<int>s3;
                   s3.init(n);
                   f=true;
                   do
                   {
                        cout<<"1.enqueue(circular queue)\n2.dqueue(circular queue)\n3.enqueue from rear(dcqueue)\n";
                        cout<<"4.enqueue from front(dcqueue)\n5.Dequeue from front(dcqueue)\n6.dequeue from rear(dcqueue)\n7.compare\n8.exit\n";
                        cin>>c1;
                        switch(c1)
                        {
                                case 1:cout<<"Enter the element you want to enter\n";
                                       cin>>z;
                                       s1.enqueue(z);
                                       break;
                                case 2:s1.dqueue();
                                        break;
                                case 3:cout<<"Enter the element you want to enter\n";
                                       cin>>z;
                                       s3.enqueue(z);
                                       break;
                                case 4:cout<<"Enter the element you want to enter\n";
                                       cin>>z;
                                       s3.enqueuef(z);
                                       break;
                                case 5:s3.dqueue();
                                       break;
                                case 6:s3.dqueuer();
                                       break;
                                case 7:if(s3.compare(s1))
                                            cout<<"Equal"<<endl;
                                        else
                                            cout<<"Not Equal\n";
                                        break;
                                case 8:f=false;
                                       break;
                                default:cout<<"Invalid input"<<endl;

                        }
                    }while(f==true);
                    break;
            case 2:cout<<"Enter no of terms for circular queue\n";
                   cin>>n;
                   cqueue<int>s2;
                   s2.init(n);
                   cout<<"Enter no of terms for double ended circular queue\n";
                   cin>>n;
                   dcqueue<int>s4;
                   s4.init(n);
                   f=true;
                   do
                   {
                        cout<<"1.enqueue(circular queue)\n2.dqueue(circular queue)\n3.enqueue from rear(dcqueue)\n";
                        cout<<"4.enqueue from front(dcqueue)\n5.Dequeue from front(dcqueue)\n6.dequeue from rear(dcqueue)\n7.compare\n8.exit\n";
                        cin>>c1;
                        switch(c1)
                        {
                                case 1:cout<<"Enter the element you want to enter\n";
                                       cin>>z;
                                       s2.enqueue(z);
                                       break;
                                case 2:s2.dqueue();
                                        break;
                                case 3:cout<<"Enter the element you want to enter\n";
                                       cin>>z;
                                       s4.enqueue(z);
                                       break;
                                case 4:cout<<"Enter the element you want to enter\n";
                                       cin>>z;
                                       s4.enqueuef(z);
                                       break;
                                case 5:s4.dqueue();
                                       break;
                                case 6:s4.dqueuer();
                                       break;
                                case 7:if(s4.compare(s2))
                                            cout<<"Equal"<<endl;
                                        else
                                            cout<<"Not Equal\n";
                                        break;
                                case 8:f=false;
                                       break;
                                default:cout<<"Invalid input"<<endl;

                        }
                    }while(f==true);
                    break;
            case 3:return 0;
            default:cout<<"Invalid input\n";
        }
    }while(true);
    return 0;
}
