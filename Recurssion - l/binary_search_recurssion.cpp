#include <iostream>
using namespace std;
int binary_search(int *a,int start,int end,int mid,int key)
{
    if(start>end)
    {
        return -1;
    }
    if(a[mid]==key)
    {
        return mid;
    }
    else
    {
        if(a[mid]<key)
        {
            return binary_search(a,mid+1,end,(mid+1+end)/2,key);
        }
        else
        {
            return binary_search(a,start,mid-1,(start+mid-1)/2,key);
        }
    }
}
int main() {
    int size;
    cin>>size;
    int a[size];
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    int key;
    cin>>key;
    int index=binary_search(a,0,size-1,(0+size-1)/2,key);
    cout<<index<<endl;
}
