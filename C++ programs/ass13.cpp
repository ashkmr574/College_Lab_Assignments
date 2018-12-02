#include<iostream>
using namespace std;
class matrix
{
    int r,c;
    int **a;
public:
	matrix operator+(const matrix &);
	matrix operator*(matrix&);
	void input();
	void display();
	void setm(int r,int c)
	{
		this->r=r;
		this->c=c;
		a=new int*[r];
    		for(int i=0;i<r;i++)
        		a[i]=new int[c];
	}
	int * operator[](int i)
	{
		return a[i];
	}
};
void matrix::input()
{
	cout<<"please enter the elements one by one\n";
     for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>((*this)[i][j]);
}
matrix matrix::operator+(const matrix &m2)
{
    int i,j;
    matrix m3;
    m3.setm(m2.r,m2.c);
    for(i=0;i<m2.r;i++)
        for(j=0;j<m2.c;j++)
        m3[i][j]=((*this)[i][j])+m2.a[i][j];
    return m3;
}
matrix matrix::operator*(matrix &m2)
{
    int i,j,k;
    matrix m3;
    m3.setm((this->r),m2.c);
    for(i=0;i<m3.r;i++)
        for(j=0;j<m3.c;j++)
            m3[i][j]=0;
    for(i=0;i<(this->r);i++)
        for(j=0;j<m2.c;j++)
            for(k=0;k<m2.r;k++)
               m3[i][j]=m3[i][j]+(((*this)[i][k])*m2[k][j]);
    return m3;
}
void matrix::display()
{
	for(int i=0;i<r;i++)
     {
          for(int j=0;j<c;j++)
                cout<<((*this)[i][j])<<" ";
           cout<<"\n";
     }
}
int main()
{
    int i,j,r,c,r1,c1;
    matrix m1,m2,m3;
    cout<<"Enter the rows and columns of first matrix\n";
    cin>>r>>c;
    m1.setm(r,c);
    m1.input();
    cout<<"Enter the rows and columns of second matrix\n";
    cin>>r1>>c1;
    m2.setm(r1,c1);
    m2.input();
    if((r==r1)&&(c==c1))
    {
        m3=m1+m2;
        cout<<"Addition of two matrices\n";
        m3.display();
    }
    else
         cout<<"addition of two matrices is not possible\n";
    if(c==r1)
    {
        m3=m1*m2;
        cout<<"product of two matrices is\n";
        m3.display();
    }
    else
        cout<<"Matrix multiplication is not possible\n\n";
    return 0;
}
