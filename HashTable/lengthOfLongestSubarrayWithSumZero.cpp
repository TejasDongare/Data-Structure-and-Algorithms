#include<iostream>
#include<unordered_map>
using namespace std;
int length(int *arr,int s)
{
    int max_length=0;
    int pre=0;
    unordered_map<int,int> m;
    for(int i=0;i<s;i++)
    {
        pre+=arr[i];
        if(pre==0)
        {
            max_length=max(max_length,i+1);
        }
        if(m.count(arr[i]))
        {
            max_length=max(max_length,i-m[pre]);
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
    int a[]={0,-1,1,2,5,-5,-2};
    int size=sizeof(a)/sizeof(int);
    cout<<length(a,size)<<endl;
}