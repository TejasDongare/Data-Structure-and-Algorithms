#include<iostream>
using namespace std;
int main()
{
	int n,key;
	int a[1000];
	cout<<"ENter the Number of elements in array="<<endl;
	cin>>n;
	int i;
	cout<<"Enter the elemnts=";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<endl;
	cout<<"ENter the element to be searched="<<endl;
	cin>>key;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			break;
		}
	}
	if(i==n)
	{
		cout<<"ELement Not Found";
	}
	else
	{
		cout<<"ELement found at index="<<i;
	}

}