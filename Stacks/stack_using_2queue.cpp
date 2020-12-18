#include <iostream>
#include<queue>
using namespace std;
class stack
{
    queue<int> q1,q2;
public:
    void push(int d)
    {
        q1.push(d);
    }
    void pop()
    {
        if(!q1.empty())
        {
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
            swap(q1,q2);
        }
    }
    int top()
    {
        int temp=0;
        if(!q1.empty())
        {
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
             temp=q1.front();
            q1.pop();
            q2.push(temp);
            swap(q1,q2);
        }
        return temp;
    }
    int size()
    {
        return q1.size();
    }
    bool empty()
    {
        return q1.size()==0;
    }
};
int main() 
{
    stack s;
    s.push(10);
    s.push(50);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    s.pop();
}
