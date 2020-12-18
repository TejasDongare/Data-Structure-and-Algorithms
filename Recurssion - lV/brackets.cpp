#include<iostream>
using namespace std;
void brackets(int n,int i,int s,int c,char *p)
{
	if(i==2*n)
	{
		p[i]='\0';
		cout<<p<<endl;
		return ;
	}
	if(s<n)
	{
		p[i]='{';
		brackets(n,i+1,s+1,c,p);
	}
	if(c<s)
	{
		p[i]='}';
		brackets(n,i+1,s,c+1,p);
	}
}
int main()
{
	int n;
	cin>>n;
	char p[100];
	brackets(n,0,0,0,p);
}