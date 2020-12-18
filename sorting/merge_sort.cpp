#include<iostream>
using namespace std;
void merge(int *a,int start,int mid,int end)
{
	int s=start;
	int m=mid+1;
	int k=0;
	int temp[end-start+2];
	while(s<=mid && m<=end)
	{
		if(a[s]<=a[m])
		{
			temp[k++]=a[s++];
		}
		else
		{
			temp[k++]=a[m++];
		}
	}
	while(s<=mid)
	{
		temp[k++]=a[s++];
	}
	while(m<=end)
	{
		temp[k++]=a[m++];
	}
	int j=0;
	for(int i=start;i<=end;i++)
	{
		a[i]=temp[j++];
	}
}
void merge_sort(int *a,int start,int end)
{
	if(start>=end)
	{
		return;
	}
	int mid=(start+end)/2;
	merge_sort(a,start,mid);
	merge_sort(a,mid+1,end);
	merge(a,start,mid,end);
}
int main()
{
	int size;
	cin>>size;
	int a[size];
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
	}
	merge_sort(a,0,size-1);
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
}