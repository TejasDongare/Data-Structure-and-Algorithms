#include <iostream>
#include<vector>
using namespace std;
void heapify(vector<int> &x,int i)
{
    int left=(i*2)+1;
    int right=left+1;
    int current_min=i;
    if(left<=(x.size()-1) and x[left]<x[current_min])
    {
        current_min=left;
    }
    if(right<=(x.size()-1) and x[current_min]>x[right])
    {
        current_min=right;
    }
    if(current_min!=i)
    {
        swap(x[current_min],x[i]);
        heapify(x,current_min);
    }
}
void BuildMinHeap(vector<int> &x)
{
    int s=x.size()/2;
    for(int i=s-1;i>=0;i--)
    {
        heapify(x,i);
    }
}
void pop(vector<int> &x)
{
    if(x.size()==1)
    {
        x.pop_back();
        return;
    }
    swap(x[0],x[x.size()-1]);
    x.pop_back();
    heapify(x,0);
    return;
}
void push(vector<int> &x,int t)
{
    x.push_back(t);
    int child=x.size()-1;
    int parent=(child-1)/2;
    while(child>=1 and x[parent]>x[child])
    {
        swap(x[child],x[parent]);
        child=parent;
        parent=(child-1)/parent;
    }
}
void print(vector<int> x)
{
    while(x.size()!=0)
    {
        cout<<x[0]<<" ";
        pop(x);
    }
    cout<<endl;
}
int JoinRopes(vector<int> &x)
{
    if(x.size()<=1)
    {
        return 0;
    }
    int a=x[0];
    pop(x);
    int b=x[0];
    pop(x);
    push(x,a+b);
    int cost=0;
    cost=a+b+JoinRopes(x);
    return cost;
}
int main() 
{
    int ropes[]={4,3,2,6};
    int size=sizeof(ropes)/sizeof(int);
    vector<int> p(ropes,ropes+size);
    BuildMinHeap(p);
    cout<<JoinRopes(p)<<endl;
}
