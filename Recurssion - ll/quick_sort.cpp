#include <iostream>
using namespace std;
int partition(int *a,int start,int end)
{
    int j=start;
    int i=j-1;
    int pivot=a[end];
    for(;j<=end;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[end]);
    return i+1;
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
