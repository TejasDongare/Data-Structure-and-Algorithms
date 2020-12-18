#include <iostream>
using namespace std;
int main() {
    int a[1000000]={0},cumlative_sum[1000000];
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
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        if(a[i])
        {
            cout<<i<<" ";
        }
    }
}
