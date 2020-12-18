#include<iostream>
using namespace std;
int main()
{
	int array_count,a[50],key,mid;
	cout<<"Enter the number of elements present in array="<<endl;
	cin>>array_count;
	int i;
	for(i=0;i<array_count;i++)
	{
		cin>>a[i];
	}
	cout<<"ENter the key="<<endl;
	cin>>key;
	int start=0;
	int end=array_count-1;
	while(end>=start)
	{
		mid=(start+end)/2;
		if(key==a[mid])
		{
		   cout<<"ELement found at index="<<mid<<endl;
			return 0;
		}
		else if(key>a[mid])
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
		i++;
	}
	cout<<"elemnt did not found";
}