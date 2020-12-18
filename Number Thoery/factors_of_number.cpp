#include <iostream>
#include<math.h>
using namespace std;
//factors of number
int main()
{
    int n;
    pair<int ,int >p[1000];
    int j=-1;
    cin>>n;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            j++;
            p[j].first=i;
            int count=0;
            while(n%i==0)
            {
                n=n/i;
                count++;
            }
            p[j].second=count;
        }
    }
    if(n!=1)
    {
        j++;
        p[j].first=n;
        p[j].second=1;
    }
    for(int i=0;i<=j;i++)
    {
        cout<<p[i].first<<"^"<<p[i].second<<endl;
    }
}
