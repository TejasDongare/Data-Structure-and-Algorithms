#include <iostream>
#include<queue>
using namespace std;
int main() 
{
    //By default max heap
    priority_queue<int> t;
    //greater int is inbuild comparator this will make min heap
    priority_queue<int,vector<int>,greater<int>> pq;
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        int no;
        cin>>no;
        pq.push(no);//O(LogN)
    }

    //Remove the elements  
    while(!pq.empty())
    {
        int top=pq.top();
        cout<<top<<" ";
        pq.pop();
    }
}
