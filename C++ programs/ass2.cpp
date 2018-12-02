#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char* Add(char a,char b)
{
       char* s=new char[3];
       s[0]=a;
       s[1]=b;
       s[2]='\0';
       return s;
}
//char* Add(char a,const char *b)
char* Add(char a,char* b)
{
    int l=strlen(b);
    int i;
    char* s=new char[l+2];
    s[0]=a;
    for(i=1;b[i-1]!='\0';i++)
        s[i]=b[i-1];
    s[i]='\0';
    return s;

}
char* Add(const char *a,char b)
{
    int l=strlen(a);
    char* s=new char[l+2];
    strcpy(s,a);
    s[l]=b;
    s[l+1]='\0';
    return s;
    //return (char*)((string)""+a+b).c_str();

}
int main()
{
	int c;
	char c1,c2;
	string s1;
	char s2[255];
	do{
		cout<<"Enter your chioce\n";
      		cout<<"1.first character and second character\n2.first character and second string\n3.first string and second character\n4.exit\n";
		cin>>c;
		switch(c)
		{
			case 1:cout<<"Enter first character\n";
			       cin>>c1;
			       cout<<"Enter second character\n";
			       cin>>c2;
			       cout<<Add(c1,c2)<<"\n";
			       break;
			case 2:cout<<"Enter character\n";
			       cin>>c1;
			       cout<<"Enter string\n";
                   cin.get();
                   //cin.getline();
                   fgets(s2,sizeof(s2),stdin);
			       //getline(cin,s1,'\n');
			       cout<<Add(c1,s2)<<"\n";
			       //cout<<Add(c1,s1.c_str())<<"\n";
			       break;
			case 3:cout<<"Enter string\n";
			       cin.get();
			       getline(cin,s1,'\n');
			       cout<<"Enter character\n";
			       cin>>c1;
			       cout<<Add(s1.c_str(),c1)<<"\n";
			       break;

			case 4:return 0;
                        default:cout<<"Invalid Input\n";
		}
	}while(true);

}

