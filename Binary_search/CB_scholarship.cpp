#include<iostream>
using namespace std;
bool is_possible(int n,int m,int x,int y,int mid)
{
	int coupens=(n-mid)*y;
	int temp=(coupens+m)-(mid*x);
	if(temp>=0)
	{
		return true;
	}
	return false;
}
int main()
{
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	int start=1,end=n,ans;
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(is_possible(n,m,x,y,mid))
		{
			ans=mid;
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}
	cout<<ans;
}