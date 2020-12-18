#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int abs(int a,int b)
{
    int d=b-a;
    if(d<0)
    {
        return (-1*d);
    }
    return d;
}
int main()
{
    int t;
    cin>>t;
    int arr[100000]={0};
    while(t--)
    {
        memset(arr,0,sizeof(arr));
        string name;
        int n,rank;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>name>>rank;
            arr[rank]++;
        }
        //greedy approach-assign the team nearest rank available
        int actual_rank=1;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            while(arr[i])
            {
                sum+=abs(actual_rank,i);
                arr[i]--;
                actual_rank++;
            }
        }
        cout<<sum<<endl;
    }
}