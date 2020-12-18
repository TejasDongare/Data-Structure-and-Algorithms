#include<iostream>
using namespace std;
int find(int a[],int size,int key)
{
	int start=0,end=size-1;
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(a[mid]==key)
		{
			return mid;
		}
		else if(a[mid]>a[start])
		{
			if(key>=a[start] and key<=a[end])
			{
				end=mid-1;
			}
			else
			{
				start=start+1;
			}
		}
		else
		{
			if(key>=a[mid] and key<=a[end])
			{
				start=mid+1;
			}
			else
			{
				end=mid-1;
			}
			
		}
	}
	return -1;
}

int main()
{
	int a[1000],size;
	cin>>size;
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
	}
	int key;
	cin>>key;
	int index=find(a,size,key);
	cout<<index<<endl;
}