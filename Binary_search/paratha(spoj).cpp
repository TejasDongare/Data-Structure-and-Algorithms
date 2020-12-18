#include<iostream>
using namespace std;
bool paratha_possible(int p,int level[],int l,int mid)
{
	int temp=0,parathas=0;
	for(int i=0;i<l;i++)
	{
		temp=0;
	int	j=1,temp_p=0;
		while(temp+(level[i]*j)<=mid)
		{
			temp=(level[i]*j)+temp;
			j++;
		}
		parathas=parathas+j-1;
	//	cout<<"parathas="<<parathas<<" level="<<level[i]<<endl;
	}

	if(parathas>=p)
	{
		return true;
	}
	return false;
}
int main()
{
	int p,l,level[1000];
	cin>>p>>l;
	for(int i=0;i<l;i++)
	{
		cin>>level[i];
		
	}
	int start=0,end=0;
	for(int i=1;i<=p;i++)
	{
		//cout<<end;
		end=(level[0]*i)+end;
	}
	int ans;
	while(start<=end)
	{
		int mid=(start+end)/2;
	//	cout<<"mid="<<mid<<endl;
		if(paratha_possible(p,level,l,mid))
		{
		//	cout<<"True"<<endl;
			ans=mid;
			end=mid-1;
		}
		else
		{
		//	cout<<"false"<<endl;
			start=mid+1;
		}
	}
	cout<<ans<<endl;
}