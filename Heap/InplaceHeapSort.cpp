#include <iostream>
#include<vector>
using namespace std;
void heapfiy(vector<int> &x,int i,int size)
{
    int left=i*2;
    int right=left+1;
    int current_max=i;
    if(left<=size and x[left]>x[current_max])
    {
        current_max=left;
    }
    if(right<=size and x[current_max]<x[right])
    {
        current_max=right;
    }
    if(current_max!=i)
    {
        swap(x[current_max],x[i]);
        heapfiy(x,current_max,size);
    }
}
void BuildMaxHeapUsingArray(vector<int> &x)
{
    int n=x.size()-1;
    for(int i=n/2;i>0;i--)
    {
        heapfiy(x,i,n);
    }
}
void pop(vector<int> &x)
{
    swap(x[1],x[x.size()-1]);
    x.pop_back();
    heapfiy(x,1,x.size()-1);
}
void InplacHeapSort(vector<int> &x)
{
    int n=x.size()-1;
    BuildMaxHeapUsingArray(x);
    while(n>1)
    {
        swap(x[1],x[n]);
        n--;
        heapfiy(x,1,n);
    }
}
int main()
{
    vector<int> v{-1,25,26,99,-99,23,33,65};
    InplacHeapSort(v);
    while(v.size()>1)
    {
        cout<<v[1]<<" ";
        pop(v);
    }
}