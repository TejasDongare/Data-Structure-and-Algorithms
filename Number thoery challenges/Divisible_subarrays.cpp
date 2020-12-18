#include<iostream>
using namespace std;
int main(){
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int size,sum=0;
		cin>>size;
		//long long  ans=0;
        long long  count[size+1]={0},a[size+1];
		count[0]=1;
		for(int i=0;i<size;i++)
		{
			cin>>a[i];
			sum+=a[i];
			sum%=size;
			sum=(sum+size)%size;
            count[sum]+=1;
		}
        long long int ans=((count[0])*(count[0]-1))/2;
        for(int i=1;i<size;i++)
        {
            ans+=((count[i])*(count[i]-1))/2;
        }
		cout<<ans<<endl;
	}
	
		
}