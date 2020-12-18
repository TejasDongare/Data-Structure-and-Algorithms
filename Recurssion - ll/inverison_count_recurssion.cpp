#include <iostream>
using namespace std;
int merge(int *ptr,int start,int mid,int end)
{
    int count=0;
    int s=start;
    int m=mid+1;
    int k=0;
    int temp[end-start+2];
    while(s<=mid && m<=end)
    {
        if(ptr[s]<=ptr[m])
        {
            temp[k++]=ptr[s++];
        }
        else
        {
            count+=mid-s+1;
            temp[k++]=ptr[m++];
        }
    }
    while(s<=mid)
    {
        temp[k++]=ptr[s++];
    }
    while(m<=end)
    {
        temp[k++]=ptr[m++];
    }
    k=0;
    for(int i=start;i<=end;i++)
    {
        ptr[i]=temp[k++];
    }
    return count;
}
int inversion_count(int *ptr,int start,int end)
{
    if(start>=end)
    {
        return 0;
    }
    int mid=(start+end)/2;
    int x=inversion_count(ptr,start,mid);
    int y=inversion_count(ptr,mid+1,end);
    int z=merge(ptr,start,mid,end);
    return x+y+z;
}
int main() {
    int size;
    cin>>size;
    int a[size];
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    cout<<inversion_count(a,0,size-1);
}
