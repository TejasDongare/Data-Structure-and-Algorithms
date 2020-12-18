#include <iostream>
#include<stack>
using namespace std;
void insertAtEnd(stack<int> &s,int d)
{
    if(s.empty())
    {
        s.push(d);
        return;
    }
    int p=s.top();
    s.pop();
    insertAtEnd(s,d);
    s.push(p);
    return;
}
void reverse(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }
    int d=s.top();
    s.pop();
    reverse(s);
    insertAtEnd(s,d);
    return;
}
int main() {
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(67);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
