#include <iostream>
using namespace std;
int main() {
    int a[1000000]={0};
    for(int i=3;i<1000000;i+=2)
    {
        a[i]=1;
    }
    for(int i=3;i<1000000;i+=2)
    {
        if(a[i])
        {
            for(int j=(2*i);j<1000000;j+=i)
            {
                a[j]=0;
            }
        }
    }
    a[0]=a[1]=0;
    a[2]=1;
    int prime_nos[1000000];
    for(int i=0,j=0;i<1000000;i++)
    {
        if(a[i])
        {
            prime_nos[j]=i;
            j++;
        }
    }
    long long int n;
    cin>>n;
    if(n<100000)
    {
        (a[n])?cout<<"prime":cout<<"Not Prime"<<endl;
    }

    else
    {
        for(long long int i=0;prime_nos[i]*(long long int)prime_nos[i]<=n;i++)
        {
            if(n%prime_nos[i]==0)
            {
                cout<<"not Primes"<<endl;
                return 0;
            }
        }
        cout<<"prime"<<endl;
    }
    return 0;
}
