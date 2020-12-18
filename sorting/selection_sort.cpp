#include<iostream>
using namespace std;
int main()
{
	int size,a[100000];
	cin>>size;
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
	}
	int min_index;
	for(int i=0;i<size-1;i++)
	{
		min_index=i;
		for(int j=i+1;j<size;j++)
		{
			if(a[min_index]>a[j])
			{
				min_index=j;
			}
		}
		swap(a[min_index],a[i]);
	}
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<endl;
	}
}