#include <iostream>
//exponential using logn time 
using namespace std;
int main() {
    int ans=1;
    int a,n;
    cin>>a>>n;
    while(n>0)
    {
        if((n&1))
        {
            ans*=a;
        }
        a*=a;
        n=n>>1;
    }
    cout<<ans;
}
