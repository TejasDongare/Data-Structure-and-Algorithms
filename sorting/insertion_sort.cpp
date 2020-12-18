#include<iostream>
using namespace std;
int main()
{
	int size,a[1000];
	cin>>size;
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<size;i++)
	{
		int j=i-1,key=a[i];
		while(a[j]>key and j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
}