#include<iostream>
#include<cstdio>
using namespace std;
template <class T>void sort(T a[],int n)
{
	int i,j;
	T temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}	
		}
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<"\t";
	cout<<"\n";
}
template <class T>void takeinput(T a[],int n)
{
	cout<<"Enter elements one by one\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,n);
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
				  	int a[n];
				  	takeinput(a,n);
				  }
				  break;
			case 2:{
					float a[n];
				  	takeinput(a,n);
				  }
				  break;
			case 3:getchar();
				  {
				    	string a[n];
				  	takeinput(a,n);
				  }
				  break;
			case 4:return 0;
			default:cout<<"Invalid input";	
		}
	}while(true);
}
