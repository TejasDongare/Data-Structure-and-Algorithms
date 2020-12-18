#include<iostream>
#include<vector>
using namespace std;
void MinHeapFromArray(vector<int> &x)
{
    for(int i=2;i<=x.size()-1;i++)
    {
        int current_index=i;
        int parent_index=i/2;
        while(current_index>1 and x[parent_index]>x[current_index])
        {
            swap(x[current_index],x[parent_index]);
            current_index=parent_index;
            parent_index=parent_index/2;
        }
    }
}
void heapify(vector<int> &x,int current_index)
{
    int left=current_index*2;
    int right=left+1;
    int min_index=current_index;
    if(left<=x.size()-1 and x[current_index]>x[left])
    {
        min_index=left;
    }
    if(right<=x.size()-1 and x[min_index]>x[right])
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
int main()
{
    vector<int> v{-1,10,20,-10,60,80,-99,100,-1000};
    MinHeapFromArray(v);
    while(v.size()!=1)   
    {
        cout<<v[1]<<" ";
        pop(v);
    }
}