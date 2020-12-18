//square root monotonic function
#include<iostream>
using namespace std;
float binary_search(int number,int pre)
{
	int start=0,end=number;
	float ans=0;
	while(start<=end)
	{
		int mid=(start+end)/2;
		int square=mid*mid;
		if(square<=number)
		{
			start=mid+1;
			ans=mid;
		}
		else
		{
			end=mid-1;
		}
	}
	float value=0.1;
	for(int i=1;i<=pre;i++)
	{
		while(ans*ans<=number)
		{
			ans=ans+value;
		}
		ans-=value;
		value=value/10
	}
	
	return ans;
}
int main()
{
	int number,pre;
	cout<<"enter the number to find the square root"<<endl;
	cin>>number;
	cout<<"Enter the precision"<<endl;
	cin>>pre;
	float num=binary_search(number,pre);
	cout<<num<<endl;
}