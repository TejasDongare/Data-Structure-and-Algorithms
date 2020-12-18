//Finding the first occurence in sorted array
#include<iostream>
using namespace std;
int lower_bound(int a[],int size,int key)
{   
    int start=0,end=size-1,index=size;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(a[mid]==key and index>mid)
        {
            end=mid-1;
            index=mid;
        }
        if(a[mid]<key)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    if(index==size)
    {
        return -1;
    }
    else
    {
        return index;
    }
}
int main()
{
    int a[1000];
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    int key;
    cin>>key;
    int index=lower_bound(a,size,key);
    if(index==-1)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"index ="<<index<<endl;
    }
}