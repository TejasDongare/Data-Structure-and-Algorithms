#include<iostream>
using namespace std;
bool solve(int b,int s,int books[],int mid)
{
	int stud=1,sum=0;
    for(int i=0;i<b;i++)
    {
    	if(sum+books[i]<=mid)
    	{
    		sum+=books[i];
    	}
    	else	
    	{
    		stud++;
			if(books[i]>mid)
			{
				return false;
			}
    		sum=books[i];
    	}
    }
    if(stud<=s)
    {
    	return true;
    }
    return false;
}
int main()
{
	int b,s,books[1200],test_cases;
	cin>>test_cases;
	while(test_cases>0)
	{
		int start=0,end=0,ans;
		cin>>b>>s;
		for(int i=0;i<b;i++)
		{
			cin>>books[i];
			end=end+books[i];
		}
		while(start<=end)
		{
			int mid=(start+end)/2;
			//cout<<"MID="<<mid;
			if(solve(b,s,books,mid))
			{
			//	cout<<" True"<<endl;
				end=mid-1;
				ans=mid;
			}
			else
			{
			//	cout<<"False"<<endl;
				start=mid+1;
			}
		}
		test_cases--;
		cout<<ans<<endl;
	}
}