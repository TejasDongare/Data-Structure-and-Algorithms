#include <iostream>
using namespace std;
int partition(int *a,int start,int end)
{
    int pivot=a[start];
    int j=start+1;
    int i=j-1;
    for(;j<=end;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[i],a[start]);
    return i;
}
void quick_sort(int *ptr,int start,int end)
{
    if(start>=end)
    {
        return ;
    }
    int pivot=partition(ptr,start,end);
    quick_sort(ptr,start,pivot-1);
    quick_sort(ptr,pivot+1,end);
}
int main() {
    int size;
    cin>>size;
    int a[size];
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    quick_sort(a,0,size-1);
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
}
