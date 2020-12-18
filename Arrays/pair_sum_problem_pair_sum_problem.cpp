#include <iostream>
using namespace std;
int binarysearch(int a[],int n,int key,int start,int end)
{
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if(a[mid]>key)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return -1;
}
//Given a sorted array find the pair such that it is equal to key
int main() {
    int array_size,a[50];
    cout<<"Enter the array size="<<endl;
    cin>>array_size;
    for(int i=0;i<array_size;i++)
    {
        cin>>a[i];
    }
    cout<<"ENter the key"<<endl;
    int key;
    cin>>key;
    int j=array_size-1;
    int start=0;
    int end=array_size-1;
    while(start<end)
    {
        int temp=key-a[end];
        int x=binarysearch(a,array_size,temp,start,end-1);
        if(x!=-1)
        {
            cout<<a[x]<<" And "<<a[end]<<endl;
            end--;
        }
        else
        {
            end--;
        }
    }
}
