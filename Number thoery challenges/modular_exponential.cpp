#include<iostream>
using namespace std;
int main() {
	long long int a,b,c;
	cin>>a>>b>>c;
    a=a%c;
	long long int ans=1;
	while(b>0)
	{
		if(b&1)
		{
            //cout<<" Ans="<<ans<<" ans%c="<<ans%c<<" a%c="<<a%c<<" ((ans%c)*(a%c))="<<((ans%c)*(a%c))<<" a="<<a<<endl;
			ans=((ans%c)*(a%c));
            
		}
		a=(a%c)*(a%c);
		b=b>>1;
		//cout<<"ans="<<ans<<endl;
	}
//	cout<<ans<<endl;
	cout<<(ans%c)<<endl;
}