#include<iostream>
using namespace std;
typedef struct matrix
{
    int **a;
    int r,c;
    void input();
    void output(matrix);

}matrix;
void matrix::input()
{
    cout<<"enter no of rows"<<endl;
    cin>>r;
    cout<<"Enter no of columns"<<endl;
    cin>>c;
    a=new int*[r];
    for(int i=0;i<r;i++)
        a[i]=new int[c];
    cout<<"enter the elements one by one\n";
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>a[i][j];
}
void matrix::output(matrix m)
{
    for(int i=0;i<m.r;i++)
    {
        for(int j=0;j<m.c;j++)
            cout<<m.a[i][j]<<" ";
        cout<<"\n";
    }

}
matrix operator+(matrix m1,matrix m2)
{
    matrix m3;
    m3.r=m1.r;
    m3.c=m1.c;
    m3.a=new int*[m3.r];
    for(int i=0;i<m3.r;i++)
        m3.a[i]=new int[m3.c];
    for(int i=0;i<m3.r;i++)
        for(int j=0;j<m3.c;j++)
        m3.a[i][j]=m1.a[i][j]+m2.a[i][j];
    return m3;
}
matrix operator*(matrix m1,matrix m2)
{
    matrix m3;
    int i,j,k;
    m3.r=m1.r;
    m3.c=m2.c;
    m3.a=new int*[m3.r];
    for(i=0;i<m3.r;i++)
        m3.a[i]=new int[m3.c];
    for(i=0;i<m3.r;i++)
        for(j=0;j<m3.c;j++)
            m3.a[i][j]=0;
    for(i=0;i<m3.r;i++)
        for(j=0;j<m3.c;j++)
            for(k=0;k<m2.r;k++)
               m3.a[i][j]=m3.a[i][j]+(m1.a[i][k]*m2.a[k][j]);
    return m3;
}
matrix operator~(matrix m1)
{
    int i,j;
    matrix m3;
    m3.r=m1.r;
    m3.c=m1.c;
    m3.a=new int*[m3.r];
    for(i=0;i<m3.r;i++)
        m3.a[i]=new int[m3.c];
    for(i=0;i<m3.r;i++)
        for(j=0;j<m3.c;j++)
            m3.a[i][j]=m1.a[j][i];
    return m3;

}
int main()
{
    matrix m1,m2;
    cout<<"enter the first matrix"<<endl;
    m1.input();
    cout<<"Enter the second matrix"<<endl;
    m2.input();
    if((m1.r==m2.r)&&(m1.c==m2.c))
    {
        cout<<"Addition result:\n";
        m1.output(m1+m2);
    }
    else
        cout<<"Addition is not possible"<<endl;
    if(m1.c==m2.r)
    {
        cout<<"Multiplication result:\n";
        m1.output(m1*m2);
    }
    else
        cout<<"multiplication is not possible"<<endl;
    cout<<"Transpose of 1st matrix\n";
    m1.output(~m1);
    cout<<"Transpose of 2nd matrix\n";
    m2.output(~m2);
    //memory deletion
    int i;
    for(i=0;i<m1.r;i++)
        delete []m1.a[i];
    delete []m1.a;
    for(i=0;i<m2.r;i++)
        delete []m2.a[i];
    delete []m2.a;
    return 0;
}
