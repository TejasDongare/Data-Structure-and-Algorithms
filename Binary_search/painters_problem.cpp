#include<iostream>
using namespace std;
bool solve(long long int mid,long long a[],long long int cpu,long long int size,long long int p)
{
	long long sum=0,painters=1;
	for(int i=0;i<size;i++)
	{
		if((sum+a[i]*cpu)<=mid)
		{
			sum=(sum+a[i]*cpu);
		}
		else
		{
			painters++;
			sum=a[i]*cpu;
			if(sum>mid)
			{
				return false;
			}
		}
	}
	if(painters<=p)
	{
		return true;
	}
	return false;
}
int main()
{
	long long int size,p,cpu,start=0,end=0;
	long long  a[1000000];
	cin>>size>>p>>cpu;
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
		end=end+a[i];
		start=max(start,a[i]);
	}
	end=cpu*end;
	
	
	long long ans;
	while(start<=end)
	{
		long long int mid=(start+end)/2;
		//cout<<"mid="<<mid;
		if(solve(mid,a,cpu,size,p))
		{
			//cout<<"True"<<endl;
			end=mid-1;
			ans=mid;
		}
		else
		{
		//	cout<<"False"<<endl;
			start=mid+1;
		}
	}
	cout<<ans%10000003<<endl;
}