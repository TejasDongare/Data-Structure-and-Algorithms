#include <iostream>
using namespace std;
int gcd(int a,int b)
{
   // cout<<"a="<<a<<" b="<<b<<endl;
    return (a==0)?b:gcd(b%a,a);
}
int main() {
    int x,y;
    cin>>x>>y;
    cout<<gcd(x,y);
}
