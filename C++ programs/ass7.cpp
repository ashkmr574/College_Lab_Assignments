#include<iostream>
using namespace std;
class student
{
    int rn,m1,m2,m3,total;
    char name[20];
    public:
        void getrn();
        void getm1();
        void getm2();
        void getm3();
        void getname();
        void totalm();
        void modifym1();
        void modifym2();
        void modifym3();
        void display();
        int getrn1(int,int);
        void modifyname();
};
void student::getrn()
{
	cout<<"Enter the roll number\n";
	cin>>rn;
}
void student::getm1()
{
	cout<<"Enter the marks in subject 1\n";
	cin>>m1;
}
void student::getm2()
{
	cout<<"Enter the marks in subject 2\n";
	cin>>m2;
}
void student::getm3()
{
	cout<<"Enter the marks in subject 3\n";
	cin>>m3;

}
void student::getname()
{
	cout<<"Enter the name of student\n";
	cin>>name;
}
void student::totalm()
{
	total=m1+m2+m3;
}
void student ::modifym1()
{
        cout<<"Enter the modified marks\n";
        cin>>m1;
        totalm();

}
void student ::modifym2()
{
        cout<<"Enter the modified marks\n";
        cin>>m2;
        totalm();

}
void student ::modifym3()
{
        cout<<"Enter the modified marks\n";
        cin>>m3;
        totalm();
}
void student::display()
{
	cout<<rn<<" "<<name<<" "<<m1<<" "<<m2<<" "<<m3<<" "<<total<<"\n";
}
void student ::modifyname()
{
	cout<<"enter the new name\n";
	cin>>name;
}
int student::getrn1(int c,int i)
{
	if(rn==c)
		return c;
	else
		return -1;
}
int main()
{
	int n,i;
	cout<<"Enter the no of student\n";
	cin>>n;
	student st[n];
	cout<<"Enter the details of student one by one\n";
	for(i=0;i<n;i++)
	{
		st[i].getrn();
		st[i].getname();
		st[i].getm1();
		st[i].getm2();
		st[i].getm3();
		st[i].totalm();
	}
	cout<<"Details of students are:\n";
	cout<<"RN"<<" "<<" NAME "<<" "<<"M1"<<" "<<"M2"<<" "<<"M3"<<" "<<"TOTAL"<<"\n";
	for(i=0;i<n;i++)
	    st[i].display();
    int rn,p;
    cout<<"Enter roll number of student whose marks you want to modify\n";
    cin>>rn;
    for(i=0;i<n;i++)
        if(st[i].getrn1(rn,i)==rn)
        {
            cout<<"choose the subject whose maks you want to modify\n1.sub 1\n2.sub 2\n3.sub 3\n";
            cin>>p;
            switch(p)
            {
                case 1:st[i].modifym1();
                        cout<<"details after modification \n";
                        st[i].display();
                        break;
                case 2:st[i].modifym2();
                        cout<<"details after modification \n";
                        st[i].display();
                        break;
                case 3:st[i].modifym3();
                        cout<<"details after modification \n";
                        st[i].display();
                        break;
                default:cout<<"Invalid input\n";

            }
            break;
        }
        else if(i==n-1)
            cout<<"Student details not found\n";
	return 0;
}
