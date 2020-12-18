#include<iostream>
using namespace std;
int main()
{
	int size,a[1000000];
	cin>>size;
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
	
}