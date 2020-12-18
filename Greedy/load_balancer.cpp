#include <iostream>
using namespace std;
int main() 
{
    int size;
    cin>>size;
    int arr[size];
    int sum=0;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int load=sum/size;
    int diff=0;
    int max_load=0;
    for(int i=0;i<size;i++)
    {
        diff+=(arr[i]-load);
        int ans=max(diff,-diff);
        max_load=max(max_load,ans);
    }
    cout<<max_load<<endl;
}
