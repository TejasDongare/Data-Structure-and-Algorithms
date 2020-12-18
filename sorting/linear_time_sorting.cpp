#include<iostream>
using namespace std;
int main()
{
    int a[1000],size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    int lo=0,mid=0,hi=size-1;
    while(mid<=hi)
    {
        if(a[mid]==0)
        {
            swap(a[mid],a[lo]);
            lo++;
        }
        else if(a[mid]==2)
        {
            swap(a[mid],a[hi]);
            hi--;
        }
        mid++;
    }
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<endl;
    }
}