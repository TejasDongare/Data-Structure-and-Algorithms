#include<iostream>
#include<vector>
using namespace std;
void buildMaxHeap(vector<int> &x)
{
    for(int i=2;i<=x.size()-1;i++)
    {
        int current_index=i;
        int parent=i/2;
        while(current_index>1 and x[current_index]>x[parent])
        {
            swap(x[parent],x[current_index]);
            current_index=parent;
            parent=parent/2;
        }
    }
}
bool empty(vector<int> &x)
{
    return x.size()==1;
}
int get(vector<int> &x)
{
    return x[1];
}
void heapify(vector<int> &x,int current_index)
{
    int left=current_index*2;
    int right=left+1;
    int min_index=current_index;
    if(left<=x.size()-1 and x[left]>x[current_index])
    {
        min_index=left;
    }
    if(right<=x.size()-1 and x[min_index]<x[right])
    {
        min_index=right;
    }
    if(min_index!=current_index)
    {
        swap(x[current_index],x[min_index]);
        heapify(x,min_index);
    }
}
void pop(vector<int> &x)
{
    swap(x[1],x[x.size()-1]);
    x.pop_back();
    heapify(x,1);
}
bool e(vector<int> &v)
{
    return v.size()==1;
}
int main()
{
    vector<int> v{-1,2,-70,50,99,-98};
    buildMaxHeap(v);
    while(v.size()>1)
    {
        cout<<get(v)<<endl;
        pop(v);
    }
    
}