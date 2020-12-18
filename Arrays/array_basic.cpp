#include<iostream>
using namespace std;
int main()
{
	int a[10]={0};//intializing all elements as 0
	int b[10]={1};//intitializing all elements as 1
	int c[10]={1,3};//intitalizing first and second elemnt as 1 and 3 and rest as 0
	cout<<"Array a="<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"Enter the first five elements to be updated="<<endl;
	for(int i=0;i<5;i++)
	{
		cin>>a[i];
	}
	cout<<endl;
	cout<<"Updated array is="<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"Size of array in bytes="<<sizeof(a)<<endl;
	cout<<"Total elemnts in array=sizeof(a)/sizeof(int)="<<sizeof(a)/sizeof(int)<<endl;
}