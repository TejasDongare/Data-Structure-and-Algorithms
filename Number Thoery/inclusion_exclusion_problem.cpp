#include <iostream>
using namespace std;
int main() {
    int prime_number[]={2,3,5,7,11,13,17,19};
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum=0;
        cin>>n;
        int subset=(1<<8)-1;
        for(int i=1;i<=subset;i++)
        {
            int find_bits=__builtin_popcount(i);
            int den=1;
            for(int j=0;j<=7;j++)
            {
                if(i&(1<<j))
                {
                    den=den*prime_number[j];
                }
            }
            if((find_bits)%2)
            {
                sum+=(n/den);
            }
            else
            {
                sum-=(n/den);
            }
        }
        cout<<sum<<endl;
    }
}
