#include <iostream>
#include<stack>
using namespace std;
class queue
{
    stack<int> s1,s2;
public:
    void enqueue(int d)
    {
        s1.push(d);
        return;
    }
    void dequeue()
    {
        if(!s1.empty())
        {
            while(s1.size()>1)
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.pop();
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    int front()
    {
        int temp=0;
        if(!s1.empty())
        {
            while(s1.size()>1)
            {
                s2.push(s1.top());
                s1.pop();
            }
            temp=s1.top();
            s2.push(temp);
            s1.pop();
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        return temp;
    }
    int size()
    {
        return s1.size();
    }
    bool empty()
    {
        return s1.size()==0;
    }
};
int main() {
    queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    while(!q1.empty())
    {
        cout<<q1.front()<<" ";
        q1.dequeue();
    }
}
