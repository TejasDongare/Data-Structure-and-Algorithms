#include <iostream>
#include<stack>
using namespace std;
int main() {
    stack<int> s;
    stack <int> x;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(7);
    int size=s.size();
    for(int i=0;i<size;i++)
    {
        int temp=s.top();
        s.pop();
        for(int j=0;j<size-i-1;j++)
        {
            int t=s.top();
            s.pop();
            x.push(t);
        }
        s.push(temp);
        while(!x.empty())
        {
            int g=x.top();
            x.pop();
            s.push(g);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
