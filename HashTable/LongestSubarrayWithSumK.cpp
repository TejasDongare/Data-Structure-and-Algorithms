#include <iostream>
#include<unordered_map>
using namespace std;
int longestsubarraysumk(int *arr,int size,int k)
{
    unordered_map<int,int> m;
    int pre=0;
    int max_length=0;
    for(int i=0;i<size;i++)
    {
        pre+=arr[i];
        if(pre==k)
        {
            max_length=max(i+1,max_length);
        }
        else if(m.count(pre-k))
        {
            max_length=max(max_length,i-m[pre-k]);
        }
        else
        {
            m[pre]=i;
        }
    }
    return max_length;
}
int main() 
{
    int arr[]={1,-1,5,-2,3};
    int size=sizeof(arr)/sizeof(int);
    cout<<longestsubarraysumk(arr,size,3)<<endl;;
}
