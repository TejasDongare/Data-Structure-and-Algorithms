#include<iostream>
#include<vector>
using namespace std;
class Heap
{
    vector<int> v;
    bool minHeap;
    bool compare(int parent,int child)
    {
        if(minHeap)
        {
            return parent>child;
        }
        else
        {
            return parent<child;
        }
    }
    void heapify(int current_index)
    {
        int left_index=current_index*2;
        int right_index=left_index+1;
        int min_index=current_index;
        if(left_index<=v.size()-1 and compare(v[current_index],v[left_index]))
        {
            min_index=left_index;
        }
        if(right_index<=v.size()-1 and compare(v[min_index],v[right_index]))
        {
            min_index=right_index;
        }
        if(current_index!=min_index)
        {
            swap(v[min_index],v[current_index]);
            heapify(min_index);
        }
    }
    public:
    Heap(int default_size=10,bool ans=true)
    {
        v.reserve(default_size);
        //this is just to filled 0th index
        v.push_back(-1);
        minHeap=ans;
    }
    void push(int d)
    {
        v.push_back(d);
        int index=v.size()-1;
        int parent=index/2;
        while(index>1 and compare(v[parent],v[index]))
        {
            swap(v[parent],v[index]);
            index=parent;
            parent=parent/2;
        }
    }
    int get()
    {
        return v[1];
    }
    void pop()
    {
        swap(v[1],v[v.size()-1]);
        v.pop_back();
        heapify(1);
    }
    bool empty()
    {
        return v.size()==1;
    }
};
int main()
{
    Heap h;
    h.push(10);
    h.push(6);
    h.push(0);
    h.push(60);
    h.push(99);
    h.push(-10);
    while(!h.empty())
    {
        cout<<h.get()<<" ";
        h.pop();
    }
}