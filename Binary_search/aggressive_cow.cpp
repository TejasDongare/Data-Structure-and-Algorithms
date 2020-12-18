#include<iostream>
#include<algorithm>
bool cow_is_possible(int stalls[],int stalls_size,int mid)
{
	int distance=0,count=1;
	for(int i=1;i<stalls[stalls_size-1];i++)
	{
		distance=stalls[i]-stalls[i-1]+ distance;
		if(distance>=mid)
		{
			distance=0;
			count++;
		}
	}
if(count>=mid)
{
	return true;
}
return false;
}
using namespace std;
int main()
{
	int stalls[100000],cows,stalls_size,ans;
	cin>>stalls_size>>cows;
	for(int i=0;i<stalls_size;i++)
	{
		cin>>stalls[i];
	}
	sort(stalls,stalls+stalls_size);
	int start=0,end=stalls[stalls_size-1ll];
	while(start<=end)
	{
		int mid=(start+end)/2;
		//cout<<"mid="<<mid<<" ";
		if(cow_is_possible(stalls,stalls_size,mid))
		{
		//	cout<<"TRUE"<<endl;
			ans=mid;
			start=mid+1;
			//cout<<"mid="<<mid<<endl;
		}
		else
		{
		//	cout<<"False"<<endl;
			end=mid-1;
		}
	//	cout<<"mid="<<mid<<endl;
	}
	cout<<ans<<endl;
}


