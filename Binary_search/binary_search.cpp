#include<iostream>
using namespace std;
int binary_search(int a[],int size,int key)
{   
    int start=0,end=size-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(a[mid]==key)
        {
            return mid;
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
    return -1;
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
    int index=binary_search(a,size,key);
    if(index==-1)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"index ="<<index<<endl;
    }
}