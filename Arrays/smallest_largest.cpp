#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int array_count,smallest,largest;
	cout<<"Enter the Number of ELements in array=";
	cin>>array_count;
	int a[50];
	for(int i=0;i<array_count;i++)
	{
		cin>>a[i];
	}
	smallest=INT_MAX;
	largest=INT_MIN;
	/*for(int i=0;i<array_count;i++)
	{
		if(smallest>a[i])
		{
			smallest=a[i];
		}
		if(largest<a[i])
		{
			largest=a[i];
		}
	}
	OR*/
	for(int i=0;i<array_count;i++)
	{
		largest=max(largest,a[i]);
		smallest=min(smallest,a[i]);
	}
	cout<<"Largest="<<largest<<endl;
	cout<<"smallest="<<smallest;
}