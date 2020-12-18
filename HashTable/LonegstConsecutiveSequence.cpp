#include <iostream>
#include<unordered_set>
using namespace std;
//time complexity is O(N) as max iteration will be 2*n
int longestConsecutiveSequence(int *arr,int n)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    int ans=0,count;
    for(int i=0;i<n;i++)
    {
        if(s.find(arr[i]-1)!=s.end())
        {
            continue;
        }
        else
        {
            int x=arr[i];
            count=0;
            while(s.find(x)!=s.end())
            {
                count++;
                x++;
            }
            ans=max(ans,count);
        }
    }
    return count;
}
int main()
{
    int arr[]={5,3,7,2,4,1,6};
    int size=sizeof(arr)/sizeof(int);
    cout<<longestConsecutiveSequence(arr,size);
}