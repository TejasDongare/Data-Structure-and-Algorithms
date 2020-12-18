#include<iostream>
#include<vector>
using namespace std;
class Heap
{
    vector<int> v;
    bool minHeap;
    public:
    Heap(int default_size=10,bool ans=true)
    {
        v.reserve(default_size);
        //this is just to filled 0th index
        v.push_back(-1);
        minHeap=ans;
    }
    bool compare(int a,int b)
    {
        if(minHeap)
        {
            return a>b;
        }
        else
        {
            return a<b;
        }
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
};
int main()
{
    Heap h;
    h.push(10);
    h.push(6);
    h.push(0);
    cout<<h.get();
}