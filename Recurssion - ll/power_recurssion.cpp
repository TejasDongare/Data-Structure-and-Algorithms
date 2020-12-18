#include <iostream>
using namespace std;
int power(int n,int p)
{
    if(p==0)
    {
        return 1;
    }
    return n*power(n,p-1);
}
int fast_power(int n,int p)
{
    if(p==0)
    {
        return 1;
    }
    int x=fast_power(n,p/2);
    x*=x;
    if(p%2==1)
    {
        x=x*n;
    }
    return x;
}
int main() {
    int n,p;
    cin>>n>>p;
    cout<<"Method - 1"<<endl;
    cout<<power(n,p)<<endl;
    cout<<endl<<"Method - 2"<<endl;
    cout<<fast_power(n,p);
}
