/**
	function overloading in c++
**/

#include<iostream>
using namespace std;
float volume(float a)
{
	return a*a*a;
}
float volume(float l,float b,float h)
{
	return l*b*h;
}
float volume(float r,float h)
{
	return (22/7.0)*r*r*h;
}
int main()
{
	float a,l,b,h,r;
    int c;
	cout<<"Enter your choice\n1. Cube\n2. Cuboid\n3. Cylinder\n";
	cin>>c;
    switch(c)
	{
		case 1:
				cout<<"Enter value of side : ";
				cin>>a;
				cout<<"Volume is : "<<volume(a)<<"\n";
				break;
		case 2:
				cout<<"Enter value of length,breadth,height : ";
				cin>>l>>b>>h;
				cout<<"Volume is : "<<volume(l,b,h)<<"\n";
				break;
		case 3:
				cout<<"Enter value of radius, height : ";
				cin>>r>>h;
				cout<<"Volume is : "<<volume(r,h)<<"\n";
				break;

	}

	return 0;
}



