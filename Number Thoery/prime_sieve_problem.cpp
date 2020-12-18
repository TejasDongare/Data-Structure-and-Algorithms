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
    int sum=0;
    for(int i=0;i<1000000;i++)
    {
        if(a[i]==1)
        {
            sum+=1;
        }
        cumlative_sum[i]=sum;
    }
    a[0]=a[1]=0;
    a[2]=1;
    int query,x,y;
   cin>>query;
    while(query--)
    {
        cin>>x>>y;
        cout<<cumlative_sum[y]-cumlative_sum[x]<<endl;
    }
}
